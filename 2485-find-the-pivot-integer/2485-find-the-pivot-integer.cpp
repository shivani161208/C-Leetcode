class Solution {
public:
    int pivotInteger(int n) {
        int tot = n * (n + 1)/2;
        int leftSum = 0;
        if(n == 1) return n;
        for(int i=0;i<n;i++){
            leftSum += i;
            int rightSum = tot - leftSum +i;

            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};