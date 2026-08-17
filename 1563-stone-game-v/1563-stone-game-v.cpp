class Solution {
public:
    int f(int i,int j,vector<int>& stoneValue,vector<int>& pre,vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int mid=i;mid<j;mid++){
            int l = pre[mid+1] - pre[i];
            int r = pre[j+1] - pre[mid+1];
            if(l < r) ans = max(ans,l + f(i,mid,stoneValue,pre,dp));
            else if(l>r) ans = max(ans,r + f(mid+1,j,stoneValue,pre,dp));
            else{
                ans = max(ans,max(l + f(i,mid,stoneValue,pre,dp),r + f(mid+1,j,stoneValue,pre,dp)));
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++)
           pre[i+1] = pre[i] + stoneValue[i];

        return f(0,n-1,stoneValue,pre,dp);
    }
};