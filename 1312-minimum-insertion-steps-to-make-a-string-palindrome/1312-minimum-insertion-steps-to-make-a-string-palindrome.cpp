class Solution {
public:
    int f(int i,int j,string &s,string &rev,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1)
           return dp[i][j];

        if(s[i] == rev[j]) 
            return dp[i][j] = 1+f(i-1,j-1,s,rev,dp);

        return dp[i][j] = max(f(i-1,j,s,rev,dp),f(i,j-1,s,rev,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        int lps = f(n-1,n-1,s,rev,dp);
        return n-lps;
    }
};