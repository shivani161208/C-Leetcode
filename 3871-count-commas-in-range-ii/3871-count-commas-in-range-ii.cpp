class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long comma = 0;
        long long st = 1000;
        while(st <= n){
            comma += n-st+1;
            st *= 1000;
        }
        return comma;
    }
};