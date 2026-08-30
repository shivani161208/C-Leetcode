class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        //sort by val
        sort(v.begin(),v.end());
        int st = 0;
        while(st<n){
            int end = st;
            while(end+1<n && v[end+1].first - v[end].first <= limit){
                end++;
            }
            vector<int>idx,val;
            for(int i=st;i<=end;i++){
                val.push_back(v[i].first);
                idx.push_back(v[i].second);
            }
            sort(idx.begin(),idx.end());

            for(int i=0;i<val.size();i++){
                nums[idx[i]] = val[i];
            }
            st = end + 1;
        }
        return nums;
    }
};