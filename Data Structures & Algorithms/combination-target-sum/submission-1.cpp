class Solution {
public:
    vector<vector<int>>ans;
    vector<int>current;
    int sum=0;
    void backtrack(vector<int>&candidates,int target,int start){
        int n=candidates.size();
        if(sum==target){
            ans.push_back(current);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=start;i<n;i++){
            current.push_back(candidates[i]);
            sum+=candidates[i];
            backtrack(candidates,target,i);
            sum-=candidates[i];
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,0);
        return ans;
    }
};
