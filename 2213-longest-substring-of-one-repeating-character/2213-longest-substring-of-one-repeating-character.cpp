class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;

        Node() {
            leftChar = '#';
            rightChar = '#';

            prefix = 0;
            suffix = 0;
            best = 0;
            len = 0;
        }
    };

    vector<Node> seg;

    Node merge(Node A, Node B) {

        if(A.len == 0)
            return B;

        if(B.len == 0)
            return A;

        Node C;

        C.len = A.len + B.len;

        C.leftChar = A.leftChar;
        C.rightChar = B.rightChar;

        // --------------------
        // PREFIX
        // --------------------

        C.prefix = A.prefix;

        // IMPORTANT:
        // A ka poora segment same character ka hona chahiye
        if(A.prefix == A.len &&
           A.rightChar == B.leftChar) {

            C.prefix = A.len + B.prefix;
        }

        // --------------------
        // SUFFIX
        // --------------------

        C.suffix = B.suffix;

        // B ka poora segment same character ka hona chahiye
        if(B.suffix == B.len &&
           A.rightChar == B.leftChar) {

            C.suffix = B.len + A.suffix;
        }

        // --------------------
        // BEST
        // --------------------

        C.best = max(A.best, B.best);

        // Boundary par same character hai
        if(A.rightChar == B.leftChar) {

            C.best = max(C.best,
                         A.suffix + B.prefix);
        }

        return C;
    }


    void build(int node, int l, int r, string &s) {

        if(l == r) {

            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);

        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node],
                          seg[2 * node + 1]);
    }


    void update(int node, int l, int r,
                int idx, char ch) {

        if(l == r) {

            seg[node].leftChar = ch;
            seg[node].rightChar = ch;

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) {

            update(2 * node,
                   l,
                   mid,
                   idx,
                   ch);
        }
        else {

            update(2 * node + 1,
                   mid + 1,
                   r,
                   idx,
                   ch);
        }

        seg[node] = merge(seg[2 * node],
                          seg[2 * node + 1]);
    }


    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();
        int k = queryIndices.size();

        seg.resize(4 * n);

        // Build tree
        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < k; i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            // Update
            update(1, 0, n - 1, idx, ch);

            // Root = complete string
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};