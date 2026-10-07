class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // If this level contains valid strings,
            // don't generate strings with more removals.
            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            if (found)
                continue;

            // Generate next level by removing one parenthesis
            for (int i = 0; i < current.size(); i++) {

                // Only remove parentheses, never letters
                if (current[i] != '(' && current[i] != ')')
                    continue;

                string next = current.substr(0, i) +
                              current.substr(i + 1);

                // Avoid duplicate strings
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};