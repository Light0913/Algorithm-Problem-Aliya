#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Data {
    int u, v, w;
} edge[MAXN];
int main() {
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(edge + 1, edge + m + 1, default_random_engine(seed));

    cout << n << ' ' << m << ' ' << t << endl;
    for (int i = 1; i <= m; i++) cout << edge[i].u << ' ' << edge[i].v << ' ' << edge[i].w << endl;
    return 0;
}