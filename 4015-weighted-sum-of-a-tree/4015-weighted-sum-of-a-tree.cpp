class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int>d(n,0);
        int h = 0;
        queue<int>q;
        d[0] = 0;
        q.push(0);

        while(!q.empty()){
            int c = q.front();
            q.pop();
            h = max(h,d[c]);

            for(int x:adj[c]){
                d[x] = d[c]+1;
                q.push(x);
            }
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long w = (long long)nums[i]*(h-d[i]+1);
            sum += w;
        }
        return sum;
    }
};