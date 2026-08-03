class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        for(int i=n-1;i>=0;i--){
            int tk1 = stone[i] - dp1;

            int tk2 = INT_MIN;
            if(i+1 < stone.size())
                tk2 = stone[i] + stone[i+1] - dp2;

            int tk3 = INT_MIN;
            if(i+2 < stone.size())
                tk3 = stone[i] + stone[i+1] + stone[i+2] - dp3;

            int curr = max({tk1,tk2,tk3});

            dp3 = dp2;
            dp2 = dp1;
            dp1 = curr;
        }
        
        if(dp1 > 0) return "Alice";
        if(dp1 < 0) return "Bob";
        return "Tie";
    }
};