class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        string left="";
        char mid = '\0';

        for(int i=0;i<26;i++){
            left += string(freq[i]/2, char(i + 'a'));

            if(freq[i]%2)
               mid = char(i + 'a');
        }
        string right = left;
        reverse(right.begin(),right.end());
        if(mid != '\0')
            return left + mid + right;

        return left + right;
    }
};