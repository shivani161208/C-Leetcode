class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
    
        map<char,int>mp;;
        for(char ch : s){
            mp[ch]++;
        }
        string left = "", right = "";
        char mid = '\0';
        for(auto &it : mp){
            //left ha;f
            left += string(it.second/2, it.first);

            //mid
            if(it.second % 2){
                mid = it.first;
            }
        }
        right = left;
        reverse(right.begin(),right.end());
        if(mid != '\0') return left + mid + right;
        return left + right;
    }
};