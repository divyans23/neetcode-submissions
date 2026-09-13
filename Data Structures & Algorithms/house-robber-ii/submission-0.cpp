class Solution {
public:
    int roblinear(vector<int>&nums,int start,int end){
        int prev2=0;
        int prev1=0;
         for(int i=start;i<=end;i++){
            int current=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n);
        if(n==0) return 0;
        if(n==1) return nums[0];
        //  basically if the last and the first can be picked so 
        // we have to find the max of h[1]-h[n-1] and h[2]-h[n-2];
        // so for the our example: 1st=2,2nd=0
        int max1=roblinear(nums,0,n-2);
        int max2=roblinear(nums,1,n-1);
        return max(max1,max2);
    }
};