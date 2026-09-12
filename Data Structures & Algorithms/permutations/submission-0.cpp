class Solution {
public:
    vector<vector<int>>ans;
    vector<int>current;
    vector<bool>used;
    void backtrack(vector<int>&nums){
        int n=nums.size();
        if(current.size()==n){
            ans.push_back(current);
            return;
        }
        // exploring and undoing when the dead end is achieved
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            used[i]=true;
            current.push_back(nums[i]);
            backtrack(nums);
            current.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),false);
        backtrack(nums);
        return ans;
    }
};