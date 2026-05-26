class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,vector<int>>mp; int size = word.size();
        int ans = 0;
        
        for(int i = 0; i < size; i++){
            
            char ch = word[i];  int value = word[i];
            //because we have to store only the lower case occurences
            if(value >= 97 && value <= 129){
                mp[ch].push_back(i); // to store all the occurrences of indices
            }

        }

        for(int i = 0; i < size; i++){
            int value = word[i]; 

            //now if we hit an uppercase letter we have to verify if its special or not
            if(value >= 65 && value < 95){
                char ch = char(value + 32); // char which is present inside the map
                int last_occurence = -1; // variable to store the last occurence 
                 
                if(mp.find(ch) != mp.end()){
                    last_occurence = mp[ch].back();
                    mp.erase(ch);
                }

                if(last_occurence != -1 && last_occurence < i){
                    ans++; // increment the answer
                }
            }
        }

        return ans;
    }
};