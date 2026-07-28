class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int idx = abs(nums[i]) - 1;
            nums[idx] = - abs(nums[idx]);
        }

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};