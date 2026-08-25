class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(auto x:nums)
            st.insert(x);

        int x = k;
        while(st.find(x) != st.end()){
            x += k;
        }
        return x;
    }
};