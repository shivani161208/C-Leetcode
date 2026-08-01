class Solution {
public:

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i] = nums[i];
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int left = nums[i] - dp[i+1][j];
                int right = nums[j] - dp[i][j-1];
                dp[i][j] = max(left,right);
            }
        }
        return dp[0][n-1] >= 0;
    }
};