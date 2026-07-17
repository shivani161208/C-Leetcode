class Solution {
public:
    int f(int idx,int t,vector<int>& coins,vector<vector<int>>&dp){
        
        if(idx == 0){
            if(t % coins[0] == 0) return t / coins[0];
            return 1e9;
        }
        if(dp[idx][t] != -1) return dp[idx][t];
        int nt = 0 + f(idx-1,t,coins,dp);
        int take = 1e9;
        if(coins[idx] <= t)
           take = 1 + f(idx, t - coins[idx], coins,dp);

        return dp[idx][t] = min(nt,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};