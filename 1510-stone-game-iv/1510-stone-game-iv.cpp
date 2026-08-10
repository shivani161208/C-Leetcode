class Solution {
public:
    bool f(int n,vector<int>&dp){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(f(n-i*i,dp) == false) return dp[n] = true;
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};