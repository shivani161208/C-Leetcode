class Solution {
public:

    bool better(pair<long long, vector<int>>& a,
                pair<long long, vector<int>>& b) {

        if (a.first != b.first)
            return a.first > b.first;

        return a.second < b.second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // original index
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        // sort by end
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {

                if (a[1] != b[1])
                    return a[1] < b[1];

                if (a[0] != b[0])
                    return a[0] < b[0];

                return a[3] < b[3];
            });

        // dp[r][i]
        vector<vector<pair<long long, vector<int>>>> dp(
            5,
            vector<pair<long long, vector<int>>>(n + 1)
        );

        for (int r = 1; r <= 4; r++) {

            for (int i = 1; i <= n; i++) {

                // 1. Skip current interval
                dp[r][i] = dp[r][i - 1];

                // 2. Find previous compatible interval
                int start = intervals[i - 1][0];

                int lo = 0, hi = i - 2;
                int j = -1;

                while (lo <= hi) {

                    int mid = lo + (hi - lo) / 2;

                    if (intervals[mid][1] < start) {
                        j = mid;
                        lo = mid + 1;
                    }
                    else {
                        hi = mid - 1;
                    }
                }

                int prev = j + 1;

                // Take current interval
                pair<long long, vector<int>> candidate =
                    dp[r - 1][prev];

                candidate.first += intervals[i - 1][2];

                candidate.second.push_back(intervals[i - 1][3]);

                sort(candidate.second.begin(),
                     candidate.second.end());

                // Compare
                if (better(candidate, dp[r][i])) {
                    dp[r][i] = candidate;
                }
            }
        }

        return dp[4][n].second;
    }
};