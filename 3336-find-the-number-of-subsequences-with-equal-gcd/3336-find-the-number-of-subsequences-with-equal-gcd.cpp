class Solution {
public:
    const int MOD = 1e9 + 7;
    int f(int idx ,int gcd1, int gcd2, vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(idx == nums.size()){
            if(gcd1 == gcd2 && gcd1 != 0)  return 1;
            return 0;
        }
        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];
        int take1 = f(idx+1, gcd(gcd1,nums[idx]),gcd2,nums,dp);
        int take2 = f(idx+1,gcd1,gcd(gcd2,nums[idx]),nums,dp);
        int skip = f(idx+1, gcd1, gcd2,nums,dp);

        return dp[idx][gcd1][gcd2] = (1LL * take1 + take2 + skip) % MOD ;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(mx+1,vector<int>(mx+1,-1)));
        return f(0,0,0,nums,dp);
    }
};