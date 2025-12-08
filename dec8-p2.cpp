#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    int sizeOf(int x) {
        return size[find(x)];
    }
};

struct Edge {
    ll dist;
    int u, v;

    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }
};

int main() {
    ifstream file("../input.txt");
    string line;

    vector<vector<int>> points;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        vector<int> point;
        while (getline(ss, token, ',')) {
            point.push_back(stoi(token));
        }
        points.push_back(point);
    }

    int n = points.size();
    cout << "boxes: " << n << endl;

    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dx = points[i][0] - points[j][0];
            ll dy = points[i][1] - points[j][1];
            ll dz = points[i][2] - points[j][2];
            ll dist = dx * dx + dy * dy + dz * dz;
            edges.push_back({dist, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    Edge x;
    for (int i = 0; i < edges.size(); i++) {
        dsu.unite(edges[i].u, edges[i].v);
        int sz = dsu.sizeOf(0);
        if (sz == n) {
            x = edges[i];
            break;
        }
    }

    int x1 = points[x.u][0];
    int x2 = points[x.v][0];

    ll res = (ll) x1 * x2;
    cout << res;
    return 0;
}