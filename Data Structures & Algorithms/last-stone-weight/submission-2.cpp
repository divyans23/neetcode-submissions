class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
         priority_queue<int>pq;
         for(int i=0;i<n;i++){
            pq.push(stones[i]);
         }
         while(n!=1 && n>0){
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            if((t1-t2)!=0){
                pq.push(t1-t2);
                n--;
            }
            else {
                pq.push(0);
                n=n-2;
            }
            
         }
         return pq.top();
    }
};
