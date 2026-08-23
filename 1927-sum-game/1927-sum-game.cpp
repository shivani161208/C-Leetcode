class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int l = 0, r = 0;
        int lq = 0, rq = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lq++;
            else
                l += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rq++;
            else
                r += num[i] - '0';
        }

        int diff = l - r;
        int qdiff = lq - rq;

        // Odd difference in '?' count
        if (abs(qdiff) % 2 == 1)
            return true;

        // Equal number of '?' on both sides
        if (qdiff == 0)
            return diff != 0;

        // Even difference
        if (qdiff > 0)
            return diff + (qdiff / 2) * 9 != 0;
        else
            return diff - ((-qdiff) / 2) * 9 != 0;
    }
};