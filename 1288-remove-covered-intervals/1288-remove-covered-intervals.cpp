class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int m = intervals[0].size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>&last = ans.back();
            if(last[0] <= intervals[i][0] && intervals[i][1] <= last[1]){
                continue;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans.size();
    }
};