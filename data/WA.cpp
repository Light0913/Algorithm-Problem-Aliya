#include <bits/stdc++.h>
namespace FastIO {
	template<typename T> bool rData(T &x) {
		x = 0;
		T f = 1;
		char c = getchar();
		if (c == EOF) return 0;
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = getchar();
		}
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = getchar();
		}
		x *= f;
		return 1;
	}
	template<typename T> void wData(T x) {
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		if (x > 9) wData(x / 10);
		putchar(x % 10 + '0');
	}
}
using namespace std;
using namespace FastIO;
const int MAXN = 1e5 + 10;
const long long INF = LONG_LONG_MAX;
struct Edge {
	int v, w, id;
};
vector<Edge> G[MAXN];
int n, m, t, tot;
long long H[MAXN];
bool cmp(Edge x, Edge y) {
    return H[x.v] < H[y.v];
}
void add(int u, int v, int w) {
	G[u].emplace_back((Edge){v, w, ++tot});
	G[v].emplace_back((Edge){u, w, tot});
}
void Dijkstra(int start) {
	struct Data {
		int pos;
		long long dis;
		bool operator < (const Data& x) const {
			return x.dis < dis;
		}
	};
	priority_queue<Data> q;
	bitset<MAXN> vis;
	fill(H + 1, H + n + 1, INF);
	H[start] = 0;
	q.emplace((Data){start, 0});
	while (q.size()) {
		Data f = q.top(); q.pop();
		int u = f.pos;
        if (vis[u]) continue;
		vis[u] = 1;
		for (const auto& i : G[u]) {
			const int& v = i.v, w = i.w;
			if (H[v] > H[u] + w) {
				H[v] = H[u] + w;
				q.emplace((Data){v, H[v]});
			}
		} 
	}
}
void A_star() {
	struct Data {
		int pos, last;
		long long dis;
		int idx;
		long long h() const {
			return llabs(dis + H[pos] - t);
		}
		bool operator < (const Data& x) const {
			return x.h() < h();
		}
	};
	struct Que {
		int pos, pre;
	};
	long long ans = INF;
	int idx = 0;
	priority_queue<Data> q;
	vector<Que> que;
	vector< unordered_set<long long> > vis(m + 3);
	q.emplace((Data){n, 0, 0, 1});
	que.emplace_back((Que){0, 0});// Õ¼Î»·û
	que.emplace_back((Que){n, 0});
	while (q.size()) {
		Data f = q.top(); q.pop();
		int u = f.pos, idx_u = f.idx;
		
		Data tmp = f;
		tmp.last = u;
		for (const auto& i : G[u]) {
			const int& v = i.v, w = i.w, id = i.id;
			tmp.pos = v, tmp.dis = f.dis + w, tmp.idx = que.size();
			que.emplace_back((Que){v, idx_u});
			if (v == 1) {
				if (llabs(tmp.dis - t) < ans) {
					ans = llabs(tmp.dis - t);
					idx = que.size() - 1;
					if (!ans) break;
				}
			}
			else {
                if (llabs(tmp.dis + H[v] - t) >= ans) break;
                else if (v != f.last && !vis[id].count(tmp.h())) {
    				q.emplace(tmp);
    				vis[id].insert(tmp.h());
    			}
            }
		}
        if (!ans) break;
	}
	wData(ans), putchar('\n');
	
    vector<int> path;
	for (int x = idx; x; x = que[x].pre) path.emplace_back(que[x].pos);
	reverse(path.begin(), path.end());
	for (const int& i : path) wData(i), putchar(' ');
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	rData(n), rData(m), rData(t);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		rData(u), rData(v), rData(w);
		add(u, v, w);
	}

    Dijkstra(1);
    for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end(), cmp);
	A_star();
	return 0;
}
