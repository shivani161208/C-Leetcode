class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,prices[i] - buy);
            buy = min(prices[i],buy);
        }
        return maxi;
    }
};