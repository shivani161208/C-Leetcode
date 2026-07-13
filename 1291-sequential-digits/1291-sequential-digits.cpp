class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        for(int len=to_string(low).size();len<=to_string(high).size();len++){
            for(int i=0;i+len<=9;i++){
                int num = stoi(s.substr(i,len));
                if(num>=low && num<=high){
                    ans.push_back(num);
                }             
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};