class Solution {
public:
   
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();  
        unordered_set<int>pairXr;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int xr = nums[i]^nums[j];
                pairXr.insert(xr);
            }
        }
        unordered_set<int>ans;
        for(int xr:pairXr){
            for(int num : nums){
                ans.insert(xr^num);
            }
        }
        return ans.size();
    }
};