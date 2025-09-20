

struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet &o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }
};

struct PacketHash {
    size_t operator()(const Packet &p) const noexcept {
        // simple integer mixing
        size_t h = (size_t)p.source;
        h = h * 1000003u + (size_t)p.destination;
        h = h * 1000003u + (size_t)p.timestamp;
        return h;
    }
};

class Router {
public:
    deque<Packet> qt;                                   // packet queue (order of insertion)
    unordered_set<Packet, PacketHash> st;               // duplicate check
    unordered_map<int, deque<int>> dest_times;          // per-destination timestamps (sorted by insertion/time)
    int limit = -1;

    Router(int memoryLimit) {
        this->limit = memoryLimit;
        if (memoryLimit > 0) st.reserve(memoryLimit * 2u);
        dest_times.reserve(1024);
    }

    bool addPacket(int source, int destination, int timestamp) {
        Packet new_packet{source, destination, timestamp};
        if (st.find(new_packet) != st.end()) return false; // duplicate

        if (limit >= 0 && (int)qt.size() == limit) {
            // evict oldest
            Packet old = qt.front();
            qt.pop_front();
            st.erase(old);
            auto it = dest_times.find(old.destination);
            if (it != dest_times.end()) {
                // expected front to match (chronological assumption)
                if (!it->second.empty() && it->second.front() == old.timestamp) {
                    it->second.pop_front();
                    if (it->second.empty()) dest_times.erase(it);
                } else {
                    // fallback (rare): remove first occurrence (linear) — avoid TLE if timestamps are chronological
                    auto &dq = it->second;
                    auto pos = find(dq.begin(), dq.end(), old.timestamp);
                    if (pos != dq.end()) dq.erase(pos);
                    if (dq.empty()) dest_times.erase(old.destination);
                }
            }
        }

        qt.push_back(new_packet);
        st.insert(new_packet);
        dest_times[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (qt.empty()) return {};
        Packet p = qt.front();
        qt.pop_front();
        st.erase(p);

        auto it = dest_times.find(p.destination);
        if (it != dest_times.end()) {
            if (!it->second.empty() && it->second.front() == p.timestamp) {
                it->second.pop_front();
                if (it->second.empty()) dest_times.erase(it);
            } else {
                // fallback (rare)
                auto &dq = it->second;
                auto pos = find(dq.begin(), dq.end(), p.timestamp);
                if (pos != dq.end()) dq.erase(pos);
                if (dq.empty()) dest_times.erase(p.destination);
            }
        }

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = dest_times.find(destination);
        if (it == dest_times.end() || it->second.empty()) return 0;

        auto &dq = it->second;
        auto itLo = lower_bound(dq.begin(), dq.end(), startTime);
        auto itHi = upper_bound(dq.begin(), dq.end(), endTime);
        return (int)(itHi - itLo); // deque iterators are random-access -> pointer subtraction works
    }
};
