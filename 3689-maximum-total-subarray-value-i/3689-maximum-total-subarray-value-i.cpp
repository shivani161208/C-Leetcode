#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
       ll val = 0 ,ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
            val = maxi - mini;
           ans = val*k;
        //    if(sum < 0){
        //     sum = 0;
        //    }
        }
        return ans;
    }
};