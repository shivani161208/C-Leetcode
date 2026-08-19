class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,set<int>>mp;
        for(auto it:reservedSeats)
            mp[it[0]].insert(it[1]);

        int ans = 2*n;
        for(auto it:mp){
            set<int>res = it.second;
            bool left = false;
            bool mid = false;
            bool right = false;
            //left
            for(int i=2;i<=5;i++){
                if(res.count(i)){
                    left = true; break;
                }
            }
            //mid
            for(int i=4;i<=7;i++){
                if(res.count(i)){
                    mid = true; break;
                }
            }
            //right
            for(int i=6;i<=9;i++){
                if(res.count(i)){
                    right = true; break;
                }
            }
            if(!left && !right) continue;
            if(!left && right){
                ans--; continue;
            }
            if(!left && mid){
                ans--; continue;
            }
            if(!mid && left && right){
                ans--;  continue;
            }
            if(!right && left){
                ans--; continue;
            }
            if(!right && mid){
                ans--; continue;
            }
            ans -= 2;
        }
        return ans;
    }
};