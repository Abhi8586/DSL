#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    int start;
    cin >> start;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return 0;
}
