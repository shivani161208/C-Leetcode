class Solution {
public:
    const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefixVal(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<long long> sumDigits(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                prefixVal[i + 1] = (prefixVal[i] * 10 + d) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            } else {
                prefixVal[i + 1] = prefixVal[i];
                cnt[i + 1] = cnt[i];
            }
            sumDigits[i + 1] = sumDigits[i] + d;
        }

        // precompute powers of 10
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {   // reference, no copy
            int l = q[0], r = q[1];

            int c = cnt[r + 1] - cnt[l];  // O(1) count, no binary search

            long long x = (prefixVal[r + 1] - (prefixVal[l] * pow10[c]) % MOD + MOD) % MOD;
            long long digitSum = sumDigits[r + 1] - sumDigits[l];

            ans.push_back((int)((x * digitSum) % MOD));
        }

        return ans;
    }
};