class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum = 0, x = 0, place = 1;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            if (digit != 0) {
                x += digit * place;
                place *= 10;
            }
            n /= 10;
        }
        return (long long)x*sum;
    }
};