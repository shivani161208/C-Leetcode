class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int component = 0;
        vector<int>comp(n);
        vector<bool>ans;
        comp[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] > maxDiff){
                component++;
            }
            comp[i] = component;
        }
        for(auto &q:queries){
           int u = q[0];
           int v = q[1];

           if(comp[u] == comp[v]){
               ans.push_back(true);
           }else{
            ans.push_back(false);
           }
        }
        return ans;
    }
};