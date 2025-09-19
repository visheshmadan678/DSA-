class Spreadsheet {
public:
    unordered_map<string, int> mp;
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { mp[cell] = value; }

    void resetCell(string cell) {
        mp.erase(cell); // actually remove it
    }

    bool check(string& str) {
        int i = 0;
        while (i < str.size() && str[i] == '0')
            i++;
        if (i == str.size())
            str = "0";
        else
            str = str.substr(i);
        return true;
    }

    bool isNumber(const string& s) {
        if (s.empty())
            return false;
        for (char c : s) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    int getValue(string formula) {
        int pos = formula.find('+');
        if (pos == string::npos)
            return 0; // invalid case

        string a = formula.substr(1, pos - 1);
        string b = formula.substr(pos + 1);

        int x = 0, y = 0;

        if (mp.find(a) != mp.end())
            x = mp[a];
        else if (isNumber(a)) {
            check(a);
            x = stoi(a);
        }

        if (mp.find(b) != mp.end())
            y = mp[b];
        else if (isNumber(b)) {
            check(b);
            y = stoi(b);
        }

        return x + y;
    }
};
