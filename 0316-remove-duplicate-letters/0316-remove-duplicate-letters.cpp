class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        
        vector<int>freq(26,0);
        vector<bool>vis(26,false);
        for(char ch:s){
            freq[ch - 'a']++;
        }
        for(char ch:s){
            //curr char is being processed
            freq[ch - 'a']--;
            //already present in ans
            if(vis[ch - 'a']) continue;

            while(!st.empty() && st.top() > ch && freq[st.top()-'a']>0){
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            vis[ch - 'a'] = true;
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};