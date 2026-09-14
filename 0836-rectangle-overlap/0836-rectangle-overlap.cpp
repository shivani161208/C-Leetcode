class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int l = max(rec1[0],rec2[0]);
        int r = min(rec1[2],rec2[2]);

        int b = max(rec1[1],rec2[1]);
        int t = min(rec1[3],rec2[3]);

        return l < r && b < t;
    }
};