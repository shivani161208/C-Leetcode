class Solution {
public:
    const long long LIMIT = 1000000;
    long long comb(long long n,long long r){
        if(r < 0 || r > n) return 0;

        r = min(r, n-r);
        if(r == 0) return 1;

        __int128 res = 1;
        for(long long i=1;i<=r;i++){
            res = res * (n - r + i) / i;
            if(res > LIMIT) return LIMIT + 1;

        }
        return (long long) res;
    }
    
    long long cntPer(vector<int>&cnt,int len,long long limit){
        long long rem = 0;
        for(int x : cnt) rem += x;
        long long ans = 1;
        for(int c : cnt){
            if(c == 0) continue;

            long long ways = comb(rem,c);
            ans *= ways;
            if(ans > LIMIT) return LIMIT + 1;
            rem -= c;
        }
        return ans;
    }

    string smallestPalindrome(string s,int k){
        vector<int>freq(26,0);
        for(char ch : s) freq[ch - 'a']++;

        int odd = 0;
        char mid = '#';

        for(int i=0;i<26;i++){
            if(freq[i] % 2){
                odd++;
                mid = char(i +'a');
            }
        }
        if(odd > 1) return "";
        vector<int>halfFreq(26,0);
        int halfLen = 0;
        for(int i=0;i<26;i++){
            halfFreq[i] = freq[i]/2;
            halfLen += halfFreq[i];
        }
        long long K = k;
        long long tot = cntPer(halfFreq,halfLen,LIMIT);
        if(K > tot) return "";
        string left = "";
        int rem = halfLen;

        for(int pos=0;pos<halfLen;pos++){
            for(int c=0;c<26;c++){
                if(halfFreq[c] == 0) continue;
                halfFreq[c]--;
                rem--;

                long long ways = cntPer(halfFreq,rem,K);

                if(ways >= K){
                    left += char(c + 'a');
                    break;
                }else{
                    K -= ways;
                    halfFreq[c]++;
                    rem++;
                }
            }
        }
        string ans = left;
        if(mid != '#') ans += mid;
        reverse(left.begin(),left.end());
        ans += left;
        return ans;
    }
};