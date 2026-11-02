
class Solution {
public:
    using ll = long long;

    long long minActivationCost(vector<vector<int>>& edges,
                                vector<int>& values) {
        int n = values.size();

        const ll INF = LLONG_MAX / 4;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Calculate parity of each node
        vector<int> parity(n);

        for (int i = 0; i < n; i++) {
            parity[i] = __builtin_popcount(
                (unsigned int)values[i]
            ) % 2;
        }

        // Build traversal order iteratively
        vector<int> parent(n, -1);
        vector<int> order;
        vector<int> st;

        st.push_back(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            order.push_back(u);

            for (auto [v, w] : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                st.push_back(v);
            }
        }

        // dp[u][0] = minimum distance from u
        // to a node with even path XOR parity.
        //
        // dp[u][1] = minimum distance from u
        // to a node with odd path XOR parity.

        vector<array<ll, 2>> dp(n, {INF, INF});

        ll ans = INF;

        // Process nodes bottom-up
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            ll best[2] = {INF, INF};

            // The node itself is also an endpoint
            best[parity[u]] = 0;

            // Process every child
            for (auto [v, w] : adj[u]) {
                if (parent[v] != u)
                    continue;

                // Query before updating
                for (int p = 0; p < 2; p++) {
                    if (dp[v][p] == INF)
                        continue;

                    ll dist = dp[v][p] + w;

                    int currentParity = parity[u] ^ p;

                    int requiredParity = p;

                    // Find a compatible endpoint
                    if (best[requiredParity] != INF) {
                        ans = min(ans,
                                  dist + best[requiredParity]);
                    }

                    // Update minimum distance
                    best[currentParity] =
                        min(best[currentParity], dist);
                }
            }

            dp[u][0] = best[0];
            dp[u][1] = best[1];
        }

        return ans == INF ? -1 : ans;
    }
};
