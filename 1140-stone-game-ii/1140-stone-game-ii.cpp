class Solution {
public:
    
    int f(int i,int m,vector<int>& piles,vector<int>&suff,vector<vector<int>>&dp){
        int n = piles.size();
        if(i >= n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        if(i+2*m >= n) return suff[i];
        int ans = 0;
        for(int x=1;x<=2*m;x++){
            int tk = suff[i] - f(i+x,max(m,x),piles,suff,dp);
            ans = max(ans,tk);
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i] = suff[i+1] + piles[i];
        }
        return f(0,1,piles,suff,dp);
    }
};