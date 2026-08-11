class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        //sequential prefix sum
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            }else{
                break;
            }
        }
        //find smallest missing integer
        int ans = sum;
        while(find(nums.begin(),nums.end(),ans) != nums.end()){
            ans++;
        }
        return ans;
    }
};