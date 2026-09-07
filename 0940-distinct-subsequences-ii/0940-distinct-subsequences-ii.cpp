class Solution {
public:
    const long long MOD = 1000000007;   
 long long f(int i,vector<int>&prev,vector<long long>&dp){
        if(i < 0) return 1;
        if(dp[i] != -1) return dp[i];
        long long ans = 2 * f(i-1,prev,dp);
        if(prev[i] != -1)
            ans -= f(prev[i]-1,prev,dp);

        ans = (ans % MOD + MOD) % MOD;
        return dp[i] = ans;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>prev(n,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int c = s[i]-'a';
            prev[i] = last[c];
            last[c] = i;
        }
        vector<long long>dp(n,-1);
        long long ans = f(n-1,prev,dp);
        return (ans - 1 + MOD )% MOD;
    }
};