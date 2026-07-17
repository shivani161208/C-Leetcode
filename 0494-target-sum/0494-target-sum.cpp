class Solution {
public:
    int f(int idx,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(idx == 0){
            if(sum == 0 && nums[0] == 0) return 2;
            if(sum == 0 || sum == nums[0]) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int ntTake = f(idx-1,sum,nums,dp);
        int take = 0;
        if(nums[idx] <= sum)
            take = f(idx-1,sum - nums[idx],nums,dp);

        return dp[idx][sum] = take + ntTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        for(int x:nums) tot += x;
        if(abs(target) > tot) return 0;
        if((tot + target) % 2) return 0;
        int ans = (tot + target) / 2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(ans+1,-1));
        return f(n-1,ans,nums,dp);
    }
};