class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int dup = -1, miss= -1;
        for(int i=1;i<=n;i++){
            if(mp[i] == 2)
               dup = i;
            else if(mp[i] == 0)
               miss = i;
        }
        return {dup,miss};
    }
};