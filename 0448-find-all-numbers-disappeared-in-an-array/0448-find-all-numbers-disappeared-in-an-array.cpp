class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for (int num : nums) {
            int idx = abs(num) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};