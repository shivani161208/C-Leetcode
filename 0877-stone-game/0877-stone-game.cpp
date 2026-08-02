class Solution {
public:
    bool f(int i,int j,vector<int>&piles){
        if(i > j) return true;
        int tk = piles[i] + f(i+1,j,piles);
        int nt = piles[j] + f(i,j+1,piles);

        return tk || nt;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        return f(n-1,n-2,piles);
    }
};