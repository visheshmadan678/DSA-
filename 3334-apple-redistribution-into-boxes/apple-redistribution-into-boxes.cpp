class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // we need the minimum number of boxes why not a greedy approach to solve this ?
        sort(apple.rbegin(),apple.rend());
        sort(capacity.rbegin(),capacity.rend()); // sort all of them on decending order pattern
        int size = apple.size(); int sizec = capacity.size();
        //now just use the two pointers appraoch
        int i = 0, j = 0, count = 0;
        while(i < size){
            if(j < sizec && capacity[j] >= apple[i]){
                capacity[j] -= apple[i]; // subtract that many apples from this bucket
                if(capacity[j] == 0){
                    count++;
                    j++; // go to the new box
                }
                else if(i == size-1 && capacity[j]!=0){
                    count++;
                }
                i++;
            }
            else if(capacity[j]!=0 && apple[i] > capacity[j]){
                apple[i] -= capacity[j]; // update the current pack of apples
                capacity[j] = 0;
                j++; // take a new box
                count++; // increase the count
            }
        }

        // if(j<sizec && capacity[j]!=0)count++;
        return count;
    }
};