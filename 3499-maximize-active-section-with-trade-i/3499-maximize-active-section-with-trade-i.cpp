class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       
        string t = '1' + s + '1';
        int n = t.length();
        vector<pair<char,int>> seg;
        int i = 0;
        while(i < n){
            char ch = t[i];
            int cnt = 0;
            while(i<n && t[i] == ch){
                cnt++;
                i++;
            }
            seg.push_back({ch,cnt});
            
        }
        int delta = 0;
        for(int i=1;i+1<seg.size();i++){
            if(seg[i].first == '1' && seg[i-1].first == '0' && seg[i+1].first == '0'){
                delta = max(delta,seg[i-1].second + seg[i+1].second);
            }
        }
        int ones = 0;
        for(char ch:s){
            if(ch == '1') ones++;
        }
        return ones + delta;
    }
};