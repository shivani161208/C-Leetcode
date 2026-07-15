class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int sumEven, sumOdd;
       sumEven = n * (n + 1);
       sumOdd = n*n;
       return gcd(sumEven,sumOdd);
    }
};