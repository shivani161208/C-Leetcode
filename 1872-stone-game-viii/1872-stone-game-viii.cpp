class Solution {
public:
    int f(int i,vector<int>& pre,vector<int>& dp){
        if(i == pre.size()-1) return pre[i];
        if(dp[i] != INT_MIN) return dp[i];
        int tk = pre[i]-f(i+1,pre,dp);
        int skip = f(i+1,pre,dp);
        return dp[i] = max(tk,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>pre(n);
        vector<int> dp(n+1,INT_MIN);
        pre[0] = stones[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + stones[i];
        }
        return f(1,pre,dp);
    }
};