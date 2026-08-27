class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        // sort(s.begin(),s.end());
        string ans = "";
        vector<int>freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(int i=n-1;i>=0;i--){
            vector<int>rem = freq;
            bool pos = true;
            for(int j=0;j<i;j++){
                int x = target[j]-'a';
                if(rem[x] == 0){
                    pos = false;
                    break;
                }
                rem[x]--;
            }
            if(!pos) continue;
            int tar = target[i]-'a';
            for(int c=tar+1;c<26;c++){
                if(rem[c]==0) continue;
                string ans = target.substr(0,i);
                ans += char('a'+c);
                rem[c]--;
                for(int x=0;x<26;x++){
                    ans.append(rem[x],char('a'+x));
                }
                return ans;
            }
        }
        
        return "";
    }
};