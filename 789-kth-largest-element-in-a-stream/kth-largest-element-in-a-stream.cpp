class KthLargest {
public:
    //code by vishu badmos
    int limit; vector<int>vec;
    priority_queue<int,vector<int>,greater<int>>qt;
    KthLargest(int k, vector<int>& vec) {
        this->limit = k;
        this->vec = vec;
        for(auto it:vec){
            if(qt.size()<k)qt.push(it); 
            else{
                if(it>qt.top()){
                    qt.pop();
                    qt.push(it);
                }
            }
        }
    }
    int add(int val) {
        // push three elements into the q
        if(qt.size()<limit)qt.push(val); // insert the value as it 
        else if(qt.top()<val){
            qt.pop();
            qt.push(val);
        }
        return qt.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


  