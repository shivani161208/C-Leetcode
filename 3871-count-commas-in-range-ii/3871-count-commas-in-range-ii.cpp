class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long commas = 1;
        long long st =1000;
        while(st<=n){
            long long end = st*1000-1;
            if(end>n) end = n;
            long long cnt = end-st+1;
            ans += cnt*commas;
            st *= 1000;
            commas++;
        }
        return ans;
    }
};