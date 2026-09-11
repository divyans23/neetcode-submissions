// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         int slow =nums[0];
//         int fast =nums[0];
//         do{
//             slow=nums[slow];
//             fast=nums[nums[fast]];
//         }
//         while(slow!=fast);
//         int slow=nums[0];
//         while(slow!=fast){
//             slow=nums[slow];
//             fast=nums[fast];
//         }
//         return slow;
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        //  basically i haver to return the no which appears more than once 
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        slow=nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};