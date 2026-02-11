// #include <bits/stdc++.h>
// #include "testlib.h"
// using namespace std;
// const int MAXN = 1e5 + 10;
// int fa[MAXN];
// int get(int x) {
//     if (fa[x] == x) return x;
//     return fa[x] = get(fa[x]);
// } 
// void merge(int x, int y) {
//     x = get(x), y = get(y);
//     fa[x] = y;
// }
// int main(int argc, char* argv[]) {
//     registerValidation(argc, argv);

//     int n = inf.readInt(1, 1e5);
//     inf.readSpace();
//     int m = inf.readInt(1, 1e5);
//     inf.readSpace();
//     int t = inf.readInt(0, 5e4);
//     inf.readEoln();
//     vector< unordered_map<int, int> > G(n + 10);
//     for (int i = 1; i <= n; i++) fa[i] = i;
//     for (int i = 1; i <= m; i++) {
//         int u = inf.readInt(1, n);
//         inf.readSpace();
//         int v = inf.readInt(1, n);
//         inf.readSpace();
//         int w = inf.readInt(0, 1e9);
//         inf.readEoln();

//         if (G[u].count(v) || G[v].count(u)) ensuref(0, "Multiple Edges");
//         if (u == v) ensuref(0, "Self-loop");
//         G[u][v] = G[v][u] = w;
//         merge(u, v);
//     }
//     int root = get(1);
//     bool flag = 1;
//     for (int i = 1; i <= n; i++) {
//         if (get(i) != root) {
//             flag = 0;
//             break;
//         }
//     }
//     if (!flag) ensuref(0, "Graph is not connected.");
//     inf.readEof();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int fa[MAXN];
int get(int x) {
    if (fa[x] == x) return x;
    return fa[x] = get(fa[x]);
} 
void merge(int x, int y) {
    x = get(x), y = get(y);
    fa[x] = y;
}
int error(const char* str) {
    cerr << str << endl;
    return 1;
}
int main(int argc, char* argv[]) {
    int n, m, t;
    cin >> n >> m >> t;
    if (n < 1 || n > MAXN || m < 1 || m > MAXN || t < 0 || t > 50000) error("The data on the first line is not within the specified range.");
    vector< unordered_set<int> > G(n + 10);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 1 || u > n || v < 1 || v > n || w < 0 || w > 1e6) error("The data is not within the specified range.");
        if (G[u].count(v) || G[v].count(u)) return error("Multiple Edges");
        if (u == v) return error("Self-loop");
        G[u].insert(v), G[v].insert(u);
        merge(u, v);
    }
    int root = get(1);
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (get(i) != root) {
            flag = 0;
            break;
        }
    }
    if (!flag) return error("Graph is not connected.");
    return 0;
}