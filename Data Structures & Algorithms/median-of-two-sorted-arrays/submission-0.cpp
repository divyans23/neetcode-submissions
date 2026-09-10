class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
    //  so here my key agenda is to sort the merging of two. sorted array in the log(n) time where n is the merged array
        int i=0;
        int j=0;
        int m1=0;
        int m2=0;
        for(int count=0;count<=(m+n)/2;count++){
            m2=m1;
            if(i!=m && j!=n){
                if(nums1[i]>=nums2[j]){
                    m1=nums2[j++];
                }
                else{
                    m1=nums1[i++];
                }
            }
            else if( i<m){
                m1=nums1[i++];
            }
            else{
                m1=nums2[j++];
            }
        }
        //  check the sum of m+n is odd or even
        if((m+n)%2==1){
            return static_cast<double>(m1);
        }
        else {
            double ans =static_cast<double>(m1)+static_cast<double>(m2);
            return ans/2.0;
        }
        
    }
};