class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int>prefixGcd(n);
        prefixGcd[0] = nums[0];
        for(int i = 0; i < n; i++){
           mx = max(mx, nums[i]);
           prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        
        long long sum = 0;
        for(int i=0;i<n/2;i++){
           sum += gcd(prefixGcd[i],prefixGcd[n-i-1]);                          
        }
        return sum;
    }
};