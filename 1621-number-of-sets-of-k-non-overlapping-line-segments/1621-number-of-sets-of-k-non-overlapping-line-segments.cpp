class Solution {
public:
    const int MOD = 1e9 + 7;
    int f(int i,int j,vector<vector<int>>&dp){
        if(j==0 || j==i) return 1;
        if(j<0 && j>i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (f(i-1,j-1,dp) + f(i-1,j,dp)) % MOD;
    }
    int numberOfSets(int n, int k) {
        int i = n+k-1;
        int j = 2*k;
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return f(i,j,dp);
    }
};