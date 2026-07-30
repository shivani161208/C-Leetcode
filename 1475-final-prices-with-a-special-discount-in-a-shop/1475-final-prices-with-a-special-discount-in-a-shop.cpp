class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int price = prices[i];
            for(int j=i+1;j<n;j++){
                if(prices[j] <= prices[i]){
                    price -= prices[j];
                    break;
                }
            }
            ans.push_back(price);
        }
        return ans;
    }
};