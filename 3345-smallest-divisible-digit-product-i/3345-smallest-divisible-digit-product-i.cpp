class Solution {
public:
    int smallestNumber(int n, int t) {
        
        int x = n;
            while(true){
                long long temp = x;
                long long pro = 1;
                while(temp > 0){
                    pro = pro * (temp % 10);
                    temp = temp/10;
                }
                if(pro%t == 0){
                    return x;
                }
               x++;
            }
        
        return -1;
    }
};