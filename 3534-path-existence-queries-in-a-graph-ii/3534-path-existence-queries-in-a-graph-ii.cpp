class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        vector<int>ans;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());

        vector<int>val(n);
        vector<int>pos(n);
           
        for(int i=0;i<n;i++){
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        vector<int>next(n);
        int r = 0;
        for(int i=0;i<n;i++){
            if(r<i) r=i;
            while(r+1 < n && val[r+1]-val[i] <= maxDiff) r++;
            next[i] = r;
        }
        int LOG=1;
        while((1 << LOG) <= n){
            LOG++;
        }
        vector<vector<int>>up(LOG,vector<int>(n));
        for(int i=0;i<n;i++){
            up[0][i] = next[i];
        }
        for(int p=1;p<LOG;p++){
            for(int i=0;i<n;i++){
                up[p][i] = up[p-1][up[p-1][i]];
            }
        }
        for(auto &q:queries){
            int u = q[0];
            int v = q[1];
            int left = pos[u];
            int right = pos[v];
            if(left > right){
                swap(left,right);
            }
            if(left == right){
                ans.push_back(0);
                continue;
            }
            
            int curr = left;
            int step = 0;
            for(int p = LOG-1; p >= 0; p--){
                if(up[p][curr] < right){
                    curr = up[p][curr];
                    step += (1 << p);
                }
            }
            if (up[0][curr] >= right)
                ans.push_back(step + 1);
            else
                ans.push_back(-1);
        }
        
        return ans;
    }

};