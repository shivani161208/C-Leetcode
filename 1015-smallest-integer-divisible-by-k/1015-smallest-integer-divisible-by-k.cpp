class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<long long> n(k);
        n[0] = 1;
        for(int i=1;i<k;i++){
            n[i] = (n[i-1]*10 + 1)% k;
        }
        for(int i=0;i<k;i++){
            if(n[i] % k == 0) return i+1;
        }
      return -1;
    }
};