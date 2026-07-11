class Solution{
public:
    int minimumTotal(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<int>front(n,0);
        for(int i=n-1;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=0;j<=i;j++){
                if(i == n-1) curr[j] = triangle[i][j];
                else{
                    int down = front[j];
                    int diag = front[j+1];
                    curr[j] = triangle[i][j] + min(down,diag);
                }
            }
            front = curr;
        }
        return front[0];
    }
};