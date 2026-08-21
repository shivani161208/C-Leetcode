#include <bits/stdc++.h>
using ll = long long;
class Solution {
public:
    ll Lcm(ll a, ll b) {
        return a / __gcd(a, b) * b;
    }

    ll cntLessThanEqualToX(vector<int>&coins,ll x){
        int m = coins.size();
        int ones = (1<<m) - 1;
        ll cnt = 0;
        for(int mask=1;mask<=ones;mask++){
            ll setBitsLcm = 1;
            for(int j=0;j<m;j++){
                if(mask & (1<<j))
                   setBitsLcm = Lcm(setBitsLcm,coins[j]);

                if (setBitsLcm > x)
                    break;
            }
            if (setBitsLcm > x)
                continue;
            if(__builtin_popcount(mask) & 1)
                cnt += x / setBitsLcm;
            else
               cnt -= x/setBitsLcm; 
        }
        return cnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        ll l = 1,r = 50LL * 1000000000LL;;
        while(l<r){
            ll mid = (l+r)/2;
            ll cnt = cntLessThanEqualToX(coins,mid);
            if(cnt<k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};