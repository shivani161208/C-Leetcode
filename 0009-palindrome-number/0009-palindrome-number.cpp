class Solution {
public:
    bool isPalindrome(int x) {
        long long n = x;
        long long rev = 0;
        while(n > 0){
            long long d = n % 10;
            rev = rev*10 + d;
            n = n/10; 
        }
        if(rev == x) return true;
        return false;
    }
};