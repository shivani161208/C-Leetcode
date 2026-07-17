class Solution {
public:
    int f(int idx,int sum,vector<int>&nums, int tar){
        if(idx == nums.size()){
            if(sum == tar) return 1;
            return 0;
        }
        int plus = f(idx+1,sum + nums[idx],nums,tar);
        int minus = f(idx+1,sum - nums[idx],nums,tar);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,0,nums,target);
    }
};