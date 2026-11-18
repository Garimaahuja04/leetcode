
class Solution {
public:
    long long maxScore(vector<int>& parent, vector<int>& op,
                       vector<int>& score) {

        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build tree
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> order;
        vector<int> st = {0};

        // Iterative DFS
        while(!st.empty()) {
            int u = st.back();
            st.pop_back();

            order.push_back(u);

            for(int v : adj[u]) {
                st.push_back(v);
            }
        }

        vector<long long> dp(n, 0);

        // Process nodes in reverse order
        for(int k = n - 1; k >= 0; k--) {

            int u = order[k];

            long long sum = score[u];
            long long mini = LLONG_MAX;

            for(int v : adj[u]) {
                sum += dp[v];
                mini = min(mini, dp[v]);
            }

            // Leaf node
            if(adj[u].empty()) {
                dp[u] = score[u];
            }

            // Optional operation
            else if(op[u] == 0) {
                dp[u] = sum - min(0LL, mini);
            }

            // Mandatory operation
            else {
                dp[u] = sum - mini;
            }
        }

        return dp[0];
    }
};
