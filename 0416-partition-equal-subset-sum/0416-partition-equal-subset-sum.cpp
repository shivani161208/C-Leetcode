class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int x : nums){
            sum += x;
        }
        if(sum % 2) return false;
        int tar = sum/2;
        vector<vector<bool>>dp(n,vector<bool>(tar+1,false));
       
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(nums[0] <= tar) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int t=1;t<=tar;t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(nums[i] <= t )
                    take = dp[i-1][t-nums[i]];

                dp[i][t] = take || notTake;
            }
        }
        
        return dp[n-1][tar];
    }
};