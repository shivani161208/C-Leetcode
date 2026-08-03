class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int>dp(n+3,0);
        for(int i=n-1;i>=0;i--){
            int tk1 = stone[i] - dp[i+1];

            int tk2 = INT_MIN;
            if(i+1 < stone.size())
                tk2 = stone[i] + stone[i+1] - dp[i+2];

            int tk3 = INT_MIN;
            if(i+2 < stone.size())
                tk3 = stone[i] + stone[i+1] + stone[i+2] - dp[i+3];

            dp[i] = max({tk1,tk2,tk3});
        }
        int ans = dp[0];
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};