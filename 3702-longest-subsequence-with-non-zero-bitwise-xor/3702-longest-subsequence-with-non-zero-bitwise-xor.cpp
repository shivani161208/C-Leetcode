class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans;
        int tot = 0;
        int cnt = 0;
        for(int x:nums){
            tot ^= x;
            if(x != 0) cnt++;
        }
        if(tot != 0) ans = n;
        else{
            if(cnt != 0) ans = n-1;
            else ans = 0;
        }
        return ans;
    }
};