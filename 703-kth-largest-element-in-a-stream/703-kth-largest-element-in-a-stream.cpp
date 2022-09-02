class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int z;
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums){
            q.push(x);
        }
        z=k;
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>z) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */