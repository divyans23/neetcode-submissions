class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq; 
        int s=tasks.size();
        vector<int>freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }
        // if(freq.size()> n){
        //     return s;
        // }
        for(int f:freq){
            if(f>0){
                pq.push(f);
            }
        }
        int time=0;
        while(! pq.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    if(f>0){
                        temp.push_back(f);
                    }
                }
                time++;
                if(pq.empty()&& temp.empty()){
                    break;
                }
            }
            for(int t:temp){
                pq.push(t);
            }
        }
        return time;
        
    }
};