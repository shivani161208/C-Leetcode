class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int rank = 1;
        for(auto it:temp){
            if(mp.find(it) == mp.end()){
                mp[it] = rank++;
            }
        }
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};