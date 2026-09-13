class Solution {
public:
    vector<vector<int>>ans;
    vector<int>current;
    void backtrack(vector<int>&nums,int start){
        int n=nums.size();
        ans.push_back(current);
        for(int i=start;i<n;i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums,i+1);
            // undoing where the dead end is achieved
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        backtrack(nums,0);
        return ans;
    }
};
