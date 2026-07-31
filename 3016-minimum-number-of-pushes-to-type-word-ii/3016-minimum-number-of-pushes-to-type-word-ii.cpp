class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>freq;
        for(char ch : word) freq[ch]++;
        vector<int>counts;
        for(auto it:freq)
            counts.push_back(it.second);
        
        sort(counts.begin(),counts.end(),greater<int>());

        int ans = 0;
        for(int i=0;i<counts.size();i++)
            ans += counts[i] * (i / 8 + 1);
        
         return ans;
    }
};