class Solution {
public:

    bool isPal(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int f(int i, int k, string &s, vector<int>& dp) {

        if(i < k)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // Don't take
        int nt = f(i - 1, k, s, dp);

        int tk = 0;

        // Take a palindrome ending at i-1
        for(int j = 0; j <= i-k; j++) {

            if(isPal(s, j, i-1)) {
                tk = max(tk, 1 + f(j, k, s, dp));
            }
        }

        return dp[i] = max(tk, nt);
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<int> dp(n + 1, -1);

        return f(n, k, s, dp);
    }
};