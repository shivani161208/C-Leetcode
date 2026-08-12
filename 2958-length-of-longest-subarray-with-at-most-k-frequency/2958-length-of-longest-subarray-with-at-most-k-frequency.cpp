class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        unordered_map<int,int>freq;
        int ans = 0;
        for(int j=0;j<n;j++){
            freq[nums[j]]++;
            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};