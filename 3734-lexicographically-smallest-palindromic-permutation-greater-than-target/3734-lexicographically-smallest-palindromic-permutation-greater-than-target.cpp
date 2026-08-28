class Solution {
public:
    bool check(int f[]){
        for(int i=0;i<26;i++)
            if(f[i]<0) return false;
           
         return true;   
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int freq[26] = {0};
        for(char c:s)
           freq[c-'a']++;

        char mid = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2){
                if(mid != 0) return "";
                mid = 'a' + i;
                freq[i]--;
            }
        }
        int half = n/2;
        for(int i=0;i<half;i++)
            freq[target[i]-'a'] -= 2;

        if(check(freq)){
            string head = target.substr(0,half);
            string rev = head;
            reverse(rev.begin(),rev.end());
            string tail = "";
            if(mid != 0) tail += mid;
            tail += rev;
            if(tail>target.substr(half)) return head+tail;
        }

        for(int i=half-1;i>=0;i--){
            char x = target[i];
            freq[x -'a'] += 2;
            if(!check(freq)) continue;
            for(int j=(x-'a')+1;j<26;j++){
                if(freq[j] ==0) continue;
                freq[j] -= 2;
                string res = target.substr(0,i+1);
                res[i] = 'a'+j;

                for(int k=0;k<26;k++){
                    int cnt = freq[k]/2;
                    if(cnt>0) res.append(cnt,'a'+k);
                }
                string part = res;
                reverse(part.begin(),part.end());
                if(mid != 0 ) res.push_back(mid);
                res += part;
                return res;
           }
        }
        return "";
    }
};