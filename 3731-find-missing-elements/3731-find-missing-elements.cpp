class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mi = nums[0];
        int mx = nums[n-1];
        vector<int>ans;
        int j = 0;
        for(int i=mi;i<mx;i++){
            if(nums[j] == i) j++;
            else ans.push_back(i);
        }
        return ans;
    }
};