class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        vector<vector<int>>ans;
        int n=points.size();
        for(auto point:points){
            int x=point[0];
            int y=point[1];
            int dist =x*x+y*y;
            pq.push({dist,point});
        }
        while(pq.size() >k){
            pq.pop();
        }
        while(! pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};