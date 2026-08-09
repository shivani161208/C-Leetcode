class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int i=n-1, j=m-1;
        double ans = 0;
        while(i >= 0){
            if(j >= 0){
                ans += prices[i] * (1.0 - (discounts[j]/ 100.0));
                j--;
            }else{
                ans += prices[i];
            }
            i--;
        }
        return ans;
    }
};