class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        // make the min heap
        K=k;
        for(int &num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
                // minimum element will be pop out.
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */