class Solution {
public:
    const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(mx + 1, vector<int>(mx + 1, 0))
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {

                    if (dp[i][g1][g2] == 0) continue;

                    long long ways = dp[i][g1][g2];

                    // Skip
                    dp[i + 1][g1][g2] =
                        (dp[i + 1][g1][g2] + ways) % MOD;

                    // Put in first subsequence
                    int ng1 = std::gcd(g1, nums[i]);
                    dp[i + 1][ng1][g2] =
                        (dp[i + 1][ng1][g2] + ways) % MOD;

                    // Put in second subsequence
                    int ng2 = std::gcd(g2, nums[i]);
                    dp[i + 1][g1][ng2] =
                        (dp[i + 1][g1][ng2] + ways) % MOD;
                }
            }
        }

        int ans = 0;
        for (int g = 1; g <= mx; g++) {
            ans = (ans + dp[n][g][g]) % MOD;
        }

        return ans;
    }
};