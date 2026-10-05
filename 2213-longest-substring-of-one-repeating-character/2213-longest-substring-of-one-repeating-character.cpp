class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int len;
        int prefix;
        int suffix;
        int mx;

        Node() {
            leftChar = rightChar = '#';
            len = prefix = suffix = mx = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            len = 1;
            prefix = suffix = mx = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.prefix = a.prefix;

        if (a.prefix == a.len && a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        // Suffix
        res.suffix = b.suffix;

        if (b.suffix == b.len && a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }

        // Maximum
        res.mx = max(a.mx, b.mx);

        // If the characters at the boundary are equal,
        // we can join the suffix of a and prefix of b.
        if (a.rightChar == b.leftChar) {
            res.mx = max(res.mx, a.suffix + b.prefix);
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, 2 * node, l, mid);
        build(s, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, c);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.length();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};