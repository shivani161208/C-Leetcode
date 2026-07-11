class Solution {
public:
    void dfs(int node,vector<vector<int>>&edges,vector<int>&vis,vector<vector<int>>&adj,int &degreeSum,int &cnt){
       vis[node] = 1;
       cnt++;
       degreeSum += adj[node].size();
       for(auto it:adj[node]){
           if(!vis[it]){
              dfs(it,edges,vis,adj,degreeSum,cnt);
           }
       }   
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto &e:edges){
          int u=e[0];
          int v = e[1];

          adj[u].push_back(v);
          adj[v].push_back(u);
       }
       int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt=0;
                int degreeSum = 0;
                dfs(i,edges,vis,adj,degreeSum,cnt);
                int edgeInComp = degreeSum / 2;
                if(edgeInComp == cnt*(cnt-1)/2)
                   ans++;
            }
        }
        return ans;
    }
};