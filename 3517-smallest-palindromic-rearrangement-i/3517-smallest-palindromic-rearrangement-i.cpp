class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char ch : s)
            freq[ch - 'a']++;

        int n = s.size();
        string ans(n, ' ');

        int l = 0, r = n - 1;

        // Fill pairs from smallest character
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 1) {
                ans[l++] = char(i + 'a');
                ans[r--] = char(i + 'a');
                freq[i] -= 2;
            }
        }

        // Place the middle character (if any)
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                ans[l] = char(i + 'a');
                break;
            }
        }

        return ans;
    }
};