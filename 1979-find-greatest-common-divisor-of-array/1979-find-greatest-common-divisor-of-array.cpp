class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int first = nums[0],second = nums[n-1];
        while(second != 0){
            int rem = first % second;
            first = second;
            second = rem;
        }
        return first;
    }
};