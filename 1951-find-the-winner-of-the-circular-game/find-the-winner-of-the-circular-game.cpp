class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>qt; // declare the queue to perform the operatonion
        for(int i=1;i<=n;i++)qt.push(i); // push all the elements into the queue
        while(qt.size()>1){
            int counter = k-1; // set the counter to k-1
            while(counter){
                qt.push(qt.front());
                qt.pop();
                counter--;
            }
            //ab main us element par hu jo muje hatana hai 
            qt.pop(); // vo element hata diya maine
        }

        return qt.front();
    }
};