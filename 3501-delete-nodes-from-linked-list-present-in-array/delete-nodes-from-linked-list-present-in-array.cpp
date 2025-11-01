/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //code by vishu badmos 
    //badmashi nhi mitar 
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //i can create a new list also right ? who said i cannot do it like this 
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>vec;

        ListNode *temp = head;
        while(temp){
            if(!st.count(temp->val))vec.push_back(temp->val);
            temp = temp->next;
        }

        //now i have all the nodes inside my vector i just have to create a new linked list 
        ListNode *new_head = new ListNode(vec[0]); // create a new head like this
        ListNode *prev = new_head;
        if(vec.size() > 1){
            for(int i=1;i<vec.size();i++){
                ListNode *front = new ListNode(vec[i]);
                prev->next = front;
                prev = front;
            }
        }

        return new_head;
    }
};