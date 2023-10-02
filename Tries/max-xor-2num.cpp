//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Node{
    public:
    int data;
    Node* lt=NULL;
    Node* rt = NULL;
    Node(){
        lt = NULL;
        rt = NULL;
    }
};

class Solution {
public:
Node* root=NULL;

void insert(int num){
    if(root==NULL) root = new Node();
    Node* curr = root;
    for(int i=31;i>=0;i--){
        int bit = (num>>i) & 1; //extracting bit from number

        if(bit){
            if(curr->rt==NULL) curr->rt=new Node();
            curr = curr->rt;
        }
        else{ //opposite bit is 0
            if(curr->lt==NULL) curr->lt=new Node();
            curr = curr->lt;
        }
    }
}

int maxXor(int num){
    if(root==NULL) root = new Node();
    int ans=0;
    Node* curr = root;
    for(int i=31;i>=0;i--){
        int bit = (num>>i) & 1;
        bit = 1-bit;
        if(bit){
           if(curr->rt){
               ans = ans | (1<<i);
               curr = curr->rt;
           }
           else{
               curr = curr->lt;
           }
        }
        else{
            if(curr->lt){
                ans = ans | (1<<i);
                curr = curr->lt;
            }
            else{
                curr = curr->rt;
            }
        }
    }
    return ans;
}

    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        insert(nums[0]);
        for(int i=1;i<n;i++){
            ans=max(ans,maxXor(nums[i]));
            insert(nums[i]);
        }
        return ans;
    }
};
