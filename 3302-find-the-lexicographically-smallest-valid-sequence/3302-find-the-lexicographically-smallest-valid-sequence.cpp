class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int p=0;
        int q=m-1;
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            right[i] = p;
            if(q>=0 && word1[i] == word2[q]){
                q--;
                p++;
            }
        }
        vector<int>ans;
        bool change = false;
        int j=0; // pointer of w2

        for(int i=0;i<n && j<m;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!change && right[i]>=m-1-j){
                ans.push_back(i);
                j++;
                change = true;
            }
        }
        if(j == m) return ans;
        return {};
    }
};
