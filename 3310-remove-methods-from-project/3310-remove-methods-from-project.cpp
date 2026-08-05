class Solution {
public:
    void dfs(vector<int>&vis,int node,vector<vector<int>>& adj){
        vis[node] = 1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &e:invocations) adj[e[0]].push_back(e[1]);
        vector<int>vis(n,0);
        dfs(vis,k,adj);
        for(auto &it:invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        //return remaining method
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};