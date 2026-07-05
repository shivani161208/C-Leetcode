class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        //score[i][j] = max score to reach this cell from E
        vector<vector<int>>score(n,vector<int>(n,-1));

        //ways[i][j] = no of max score path
        vector<vector<int>>ways(n,vector<int>(n,0));

        //base case
        score[0][0] = 0;
        ways[0][0] = 1;

        //traverse from top-left to bottom-right
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                //skip starting cell
                if(i==0 && j==0) continue;
                if(board[i][j] == 'X') continue;

                int best = -1;
                long long cnt = 0;

                //from top
                if(i>0 && score[i-1][j] != -1){
                    if(score[i-1][j] > best){
                        best = score[i-1][j];
                        cnt = ways[i-1][j];
                    }
                    else if(score[i-1][j] == best){
                        cnt = (cnt+ways[i-1][j]) % MOD;
                    }
                }

                //from left
                if(j>0 && score[i][j-1] != -1){
                    if(score[i][j-1] > best){
                        best = score[i][j-1];
                        cnt = ways[i][j-1];
                    }
                    else if(score[i][j-1] == best){
                        cnt = (cnt+ways[i][j-1]) % MOD;
                    }
                }
                //from diagonal
                if(i>0 && j>0 && score[i-1][j-1] != -1){
                    if(score[i-1][j-1] >best){
                        best = score[i-1][j-1];
                        cnt = ways[i-1][j-1];
                    }
                    else if(score[i-1][j-1] == best){
                        cnt = (cnt+ways[i-1][j-1]) % MOD;
                    }
                }
                if(best == -1) continue;

                score[i][j] = best;
                ways[i][j] = cnt % MOD;

                //add current cell value
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    score[i][j] += board[i][j] - '0';
                }
            }
        }
        if(ways[n-1][n-1] == 0){
            return {0,0};
        }
        return {score[n-1][n-1] , ways[n-1][n-1]};
    }
};