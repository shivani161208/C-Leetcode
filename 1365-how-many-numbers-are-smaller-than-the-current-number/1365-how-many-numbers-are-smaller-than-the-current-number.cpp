class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        
        for(int i=0;i<temp.size();i++){
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = i;
            }
        }
        vector<int>ans;
        for(auto x: nums){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};