class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char,int>freq;
        for(char ch : word) freq[ch]++;
        vector<pair<int,char>>p;
        for(auto it:freq){
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end(),greater<pair<int,char>>());

        int ans = 0;
        for(int i=0;i<p.size();i++){
            int cnt = (i/8) + 1;
            ans += p[i].first *cnt;
        }
     return ans;
    }
};