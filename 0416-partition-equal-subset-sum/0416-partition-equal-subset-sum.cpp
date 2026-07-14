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
        vector<bool>prev(tar+1,false);
        prev[0] = true;       
        
        if(nums[0] <= tar) prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            vector<bool>curr(tar+1,false);
            curr[0] = true;
            for(int t=1;t<=tar;t++){
                bool notTake = prev[t];
                bool take = false;
                if(nums[i] <= t )
                    take = prev[t-nums[i]];

                curr[t] = take || notTake;
            }
            prev = curr;
        }
        
        return prev[tar];
    }
};