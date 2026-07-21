class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       
        string t;
        t.reserve(s.size()+2);
        t.push_back('1');
        t += s;
        t.push_back('1');
        int n = t.length();
        vector<pair<char,int>> seg;
        seg.reserve(t.size());
        int i = 0;
        int ones = 0;
        while(i < n){
            char ch = t[i];
            int cnt = 0;
            while(i<n && t[i] == ch){
                if(ch == '1' && i>0 && i < n-1) ones++;
                cnt++;
                i++;
            }
            seg.push_back({ch,cnt});
            
        }
        int delta = 0;
        int m = seg.size();
        for(int i=1;i<m-1;i++){
            if(seg[i].first == '1' && seg[i-1].first == '0' && seg[i+1].first == '0'){
                delta = max(delta,seg[i-1].second + seg[i+1].second);
            }
        }
        return ones + delta;
    }
};