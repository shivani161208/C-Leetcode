class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = *max_element(lights.begin(),lights.end());
        int ans = 0;
        for(int it:arrivalTime){
            int r = it%period;
            if(r<mx) continue;
            int wait = period-r;
            ans = max(ans,wait);
        }
        return ans;
    }
};