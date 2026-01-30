class AuctionSystem {
public:
    //code by vishu badmos 
    //badmashi nahi mitar 
    unordered_map<int, unordered_map<int, int>> user_map;
    unordered_map<int, set<pair<int, int>>> item_map;
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        // this to add the user id on particular item id with some bid amount
        int prev_amount = user_map[userId][itemId];
        user_map[userId][itemId] =
            bidAmount; // set the bid amount and also update the item map side
                       // by side

        if (item_map[itemId].count({prev_amount, userId})) {
            item_map[itemId].erase({prev_amount, userId});
        }
        item_map[itemId].insert({bidAmount, userId}); // newly bid amount
    }

    void updateBid(int userId, int itemId, int newAmount) {
        // this to update the amount only of some user with user id and some
        // item id
        int prev_amount = user_map[userId][itemId];
        user_map[userId][itemId] = newAmount;

        if (item_map[itemId].count({prev_amount, userId})) {
            item_map[itemId].erase({prev_amount, userId});
        }
        item_map[itemId].insert({newAmount, userId}); // newly bid amount
    }

    void removeBid(int userId, int itemId) {
        // now i want this user's bid amont of item id
        int bid_amount = user_map[userId][itemId];
        item_map[itemId].erase(
            {bid_amount, userId}); // also update the items map
    }

    int getHighestBidder(int itemId) {
        // it will tell the user id of the person who is having the highest bid
        // amount of the curret item id
        if (!(item_map[itemId].size() == 0) && item_map.find(itemId) != item_map.end()) {
            pair<int, int> p = *item_map[itemId].rbegin();
            return p.second;
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */