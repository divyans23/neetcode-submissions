class Solution {
public:
    
    int rob(vector<int>& nums) {
        // lets first undersand the state if i rob at i state the dp[i]=nums[i]+dp[i-2]
        // or if not then dp[i-1]
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};