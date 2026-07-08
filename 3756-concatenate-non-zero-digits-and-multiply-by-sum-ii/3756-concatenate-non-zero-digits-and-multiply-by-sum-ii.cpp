class Solution {
public:
    const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        // Prefix sum of digits
        vector<long long> sum(n);
        sum[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + (s[i] - '0');

        // Store non-zero digits and their indices
        vector<int> idx;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                idx.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // 10^i % MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix number
        vector<long long> num(m);

        if (m > 0) {
            num[0] = digit[0];

            for (int i = 1; i < m; i++)
                num[i] = (num[i - 1] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto q : queries) {

            int l = q[0];
            int r = q[1];

            // Digit sum
            long long digitSum = sum[r];
            if (l > 0)
                digitSum -= sum[l - 1];

            // Find first and last non-zero digit
            int first = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
            int last = upper_bound(idx.begin(), idx.end(), r) - idx.begin() - 1;

            if (first > last) {
                ans.push_back(0);
                continue;
            }

            int len = last - first + 1;

            long long x;

            if (first == 0)
                x = num[last];
            else
                x = (num[last] - (num[first - 1] * pow10[len]) % MOD + MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};