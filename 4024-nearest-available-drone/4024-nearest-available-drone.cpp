class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& tar) {
        int ans = -1;
        int mini = INT_MAX;
        for(int i=0;i<drones.size();i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int dist = abs(x-tar[0]) + abs(y-tar[1]);
            if(dist<=drones[i][2] && mini>dist){
                mini = dist;
               ans = i;
            }
        }
        return ans;
    }
};