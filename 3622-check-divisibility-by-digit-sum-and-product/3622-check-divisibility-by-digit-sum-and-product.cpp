class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1;
        int num = n;
        while(num > 0){
            int d = num%10;
            sum += d;
            pro *= d;
            num /= 10;
        }
        int ans = sum+pro;
        return (n%ans)==0;
    }
};