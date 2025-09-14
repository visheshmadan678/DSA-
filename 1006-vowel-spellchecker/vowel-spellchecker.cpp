class Solution {
public:
    //not done by me kyuki mera man nhi tha kuch karne ka aaj 
    // kyuki maine company ke test mein hug diya tha 
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end()); // exact matches
        unordered_map<string, string> caseMap;   // lowercase -> first word
        unordered_map<string, string> vowelMap;  // vowel pattern -> first word

        auto isVowel = [](char c) {
            c = tolower(c);
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        };

        auto vowelPattern = [&](string word) {
            for (auto &ch : word) {
                ch = tolower(ch);
                if (isVowel(ch)) ch = '*';
            }
            return word;
        };

        // Build dictionaries
        for (string &word : wordlist) {
            string lowerWord = word;
            for (auto &ch : lowerWord) ch = tolower(ch);

            if (!caseMap.count(lowerWord)) {
                caseMap[lowerWord] = word; // first occurrence
            }

            string vPat = vowelPattern(word);
            if (!vowelMap.count(vPat)) {
                vowelMap[vPat] = word; // first occurrence
            }
        }

        vector<string> ans;

        for (string query : queries) {
            // Step 1: Exact match
            if (exactSet.count(query)) {
                ans.push_back(query);
                continue;
            }

            // Step 2: Case-insensitive
            string lowerQuery = query;
            for (auto &ch : lowerQuery) ch = tolower(ch);
            if (caseMap.count(lowerQuery)) {
                ans.push_back(caseMap[lowerQuery]);
                continue;
            }

            // Step 3: Vowel-error (optimized)
            string vPat = vowelPattern(query);
            if (vowelMap.count(vPat)) {
                ans.push_back(vowelMap[vPat]);
                continue;
            }

            // Step 4: No match
            ans.push_back("");
        }

        return ans;
    }
};
