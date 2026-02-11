#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int MAXN = 1e5 + 10;
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    // 读取输入
    int n = inf.readInt(), m = inf.readInt(), t = inf.readInt();
    vector< unordered_map<int, int> > G(n + 10);
    for (int i = 1; i <= m; i++) {
        int u = inf.readInt(), v = inf.readInt(), w = inf.readInt();
        G[u][v] = G[v][u] = w;
    }

    // 读取输出
    int score = 0, x;
    long long out_ans = -1, ans_ans = ans.readLong();
    vector<int> path;

    string str = ouf.readLine();
    stringstream line1(str);
    line1 >> out_ans;

    str = ouf.readLine();
    stringstream line2(str);
    while (line2 >> x) path.push_back(x);


    // 判断输出是否正确
    if (out_ans == ans_ans) score += 4;
    bool correct = 1;
    long long sum = 0;
    for (int i = 0; i < path.size(); i++) {
        int u = path[i];
        if (i != path.size() - 1 && u == 1) {
            correct = 0;
            break;
        }
        if (u < 1 || u > n || path[0] != n || path[path.size() - 1] != 1) {
            correct = 0;
            break;
        }
        if (i + 2 < path.size() && u == path[i + 2]) {
            correct = 0;
            break;
        }
        if (i < path.size() - 1) {
            int v = path[i + 1];
            if (!G[u].count(v)) {
                correct = 0;
                break;
            }
            sum += G[u][v];
        }
    }
    if (!path.size()) correct = 0;
    if (llabs(sum - t) != ans_ans) correct = 0;
    if (correct) score += 6;

    // 返回成绩
    if (score == 0) quitf(_wa, "Wrong answer.");
    if (score == 4) quitp(0.5, "Wrong path on the second line.");
    if (score == 6) quitp(0.5, "Wrong answer on the first line.");
    if (score == 10) quitf(_ok, "Accepted.");
    return 0;
}
