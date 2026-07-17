class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<long long>freq(mx+1,0);

        for(int x:nums) freq[x]++;

        vector<long long>gcdCnt(mx+1,0);
        for(int i=mx;i>=1;i--){
            long long cnt = 0;
            for(int j=i;j<=mx;j+=i){
                cnt += freq[j];
            }

            gcdCnt[i] = cnt*(cnt-1)/2;
            for(int j=2*i;j<=mx;j+=i) 
               gcdCnt[i] -= gcdCnt[j];
        }
        vector<long long>prefix(mx+1,0);
        for(int i=1;i<=mx;i++)
           prefix[i] = prefix[i-1] + gcdCnt[i];

        vector<int>ans;
        for(long long q:queries){
            int g = lower_bound(prefix.begin()+1,prefix.end(),q+1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;
    }
};