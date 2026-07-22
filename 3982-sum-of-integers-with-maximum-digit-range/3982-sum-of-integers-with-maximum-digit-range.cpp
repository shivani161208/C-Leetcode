class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        for (int num : nums) {
            int x = num;
            int mx = 0;
            int mn = 9;

            // Special case for 0
            if (x == 0) {
                mx = mn = 0;
            } else {
                while (x > 0) {
                    int digit = x % 10;
                    mx = max(mx, digit);
                    mn = min(mn, digit);
                    x /= 10;
                }
            }

            int range = mx - mn;

            if (range > maxRange) {
                maxRange = range;
                sum = num;
            } else if (range == maxRange) {
                sum += num;
            }
        }

        return sum;
    }
};