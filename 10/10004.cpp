#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E, u, v;
    vector<vector<int> > adj;
    int color[205];
    queue<int> q;
    bool isbipartite;
    string res;

    while (scanf("%d", &V), V) {
        scanf("%d", &E);

        isbipartite = true;
        adj.clear();
        adj.resize(V);
        queue<int> clear;
        swap(q, clear);
        memset(color, -1, sizeof(color));
        color[0] = 1;

        for (int i = 0; i < E; i++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            q.push(i);
        }

        while(!q.empty() && isbipartite) {
            u = q.front();
            q.pop();
            if (color[u] == -1) {
                q.push(u);
                continue;
            }
            for (int i = 0; i < adj[u].size(); i++) {
                v = adj[u][i];
                if (color[v] == color[u]) {
                    isbipartite = false;
                    break;
                }
                color[v] = 1 - color[u];
            }
        }

        res = isbipartite ? "BICOLORABLE." : "NOT BICOLORABLE.";
        printf("%s\n", res.c_str());
    }
    return 0;
}