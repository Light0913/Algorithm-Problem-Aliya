#include <bits/stdc++.h>
namespace FastIO {
    const int BUF_SIZE = 1 << 20;// 缓冲区大小，可根据需要调整

    // 输入缓冲区
    char ibuf[BUF_SIZE], *iptr = ibuf, *iend = ibuf;
    // 输出缓冲区
    char obuf[BUF_SIZE], *optr = obuf;

    // 从输入缓冲区读一个字符（若为空则调用 fread 填充）
    inline char getc() {
        if (iptr == iend) {
            iend = ibuf + fread(ibuf, 1, BUF_SIZE, stdin);
            iptr = ibuf;
            if (iptr == iend) return EOF;// 无数据可读
        }
        return *iptr++;
    }

    // 向输出缓冲区写一个字符（若满则调用 fwrite 刷新）
    inline void putc(char c) {
        if (optr == obuf + BUF_SIZE) {
            fwrite(obuf, 1, BUF_SIZE, stdout);
            optr = obuf;
        }
        *optr++ = c;
    }

    // 手动刷新输出缓冲区（程序结束时会自动调用，一般无需手动调用）
    inline void flush() {
        if (optr != obuf) {
            fwrite(obuf, 1, optr - obuf, stdout);
            optr = obuf;
        }
    }

    // 读取一个整数，成功返回 true，失败（遇到 EOF）返回 false
    template<typename T> bool rData(T &x) {
        x = 0;
        T f = 1;
        char c = getc();
        if (c == EOF) return false;// 无任何字符，直接返回失败

        // 跳过非数字字符（包括可能的空白和负号）
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = getc();
            if (c == EOF) return false;// 非数字过程中遇到 EOF，认为读取失败
        }

        // 读取数字部分
        while (isdigit(c)) {
            x = x * 10 + (c - '0');
            c = getc();
            if (c == EOF) break;// 数字后直接 EOF，数字解析完毕，仍返回成功
        }
        x *= f;
        return true;
    }

    // 写入一个整数（递归写法）
    template<typename T> void wData(T x) {
        if (x < 0) {
            putc('-');
            x = -x;
        }
        if (x > 9) wData(x / 10);
        putc(x % 10 + '0');
    }

    // 自动刷新输出缓冲区的辅助类（程序退出时调用 flush）
    struct Flusher {
        ~Flusher() { flush(); }
    } flusher;
}
using namespace FastIO;
using namespace std;
const int MAXN = 1e5 + 10;
const long long INF = LONG_LONG_MAX;
struct Edge {
	int v, w, id;
};
vector<Edge> G[MAXN];
int n, m, t;
long long H[MAXN];
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
        
		for (const auto& [v, w, id] : G[u]) {
			if (H[v] > H[u] + w) {
				H[v] = H[u] + w;
				q.emplace((Data){v, H[v]});
			}
		} 
	}
}
void A_star() {
	struct Data {
		int pos, idx, last;
		long long dis, f;
		Data (int _pos, int _idx, int _last, long long _dis) {
			pos = _pos, idx = _idx, last = _last, dis = _dis;
			f = llabs(dis + H[pos] - t);
		}
		bool operator < (const Data& x) const {
			return x.f < f;
		}
	};
	struct Que {
		int pos, pre;
	};
	long long ans = INF;
	int idx = 0;
	priority_queue<Data> q;
    vector<int> path;
	vector<Que> que;
	vector< unordered_set<long long> > vis(m + 3);
    
	q.emplace(Data(n, 1, 0, 0));
	que.emplace_back((Que){0, 0});// 占位符
	que.emplace_back((Que){n, 0});
	while (q.size()) {
		Data f = q.top(); q.pop();
		const int& u = f.pos, idx_u = f.idx;

        if (u == 1) {
    		if (llabs(f.dis - t) < ans) {
    			ans = llabs(f.dis - t);
    			idx = idx_u;
    			if (!ans) break;
    		}
    	}
        
		for (const auto& [v, w, id] : G[u]) {
			Data tmp(v, que.size(), u, f.dis + w);
            
            if (tmp.dis + H[v] - t >= ans) break;
			else if (v == f.last) continue;
            else if (vis[id].insert(tmp.f).second) {
                que.emplace_back((Que){v, idx_u});
    			q.emplace(tmp);
    		}
		}
	}
	wData(ans), putc('\n');
	for (int x = idx; x; x = que[x].pre) path.emplace_back(que[x].pos);
	reverse(path.begin(), path.end());
	for (const int& i : path) wData(i), putc(' ');
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	rData(n), rData(m), rData(t);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		rData(u), rData(v), rData(w);
		G[u].emplace_back((Edge){v, w, i});
        G[v].emplace_back((Edge){u, w, i});
	}
    Dijkstra(1);
    for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end(), [](const Edge& x, const Edge& y) {
			return H[x.v] < H[y.v];
		});
	}
	A_star();
	return 0;
}
