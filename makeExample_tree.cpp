#include <bits/stdc++.h>
using namespace std;

mt19937 gen;

// 生成 [l, r] 的随机整数
int rdm(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

// 初始化随机数种子（可传命令行参数）
// 参数解释：
//   - 默认用 time + clock 播种，确保每次运行不同
//   - 如果命令行有参数（例如对拍时），则根据参数修正种子，实现“可复现”随机
void initRand(int argc, char* argv[]) {
    int seed = time(0) + clock();
    if (argc > 1) seed += atoi(argv[1]) * 10007; // 对拍用：不同参数不同种子
    gen.seed(seed);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initRand(argc, argv); // ★ 一行搞定随机初始化

    int n = rdm(1, 10); // 随机生成 n

    if (n == 1) { cout << 1 << "\n"; return 0; }

    // --- 生成随机 Prüfer 序列 ---
    vector<int> prufer;
    if (n >= 2) {
        prufer.resize(n - 2);
        for (int i = 0; i < n - 2; ++i) prufer[i] = rdm(1, n);
    }

    // --- 构建树 ---
    vector<int> deg(n + 1, 1);
    for (int x : prufer) ++deg[x];

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 1) pq.push(i);

//替换开始
    cout << n << "\n";
    for (int x : prufer) {
        int u = pq.top(); pq.pop();
        cout << u << " " << x << "\n";
        if (--deg[x] == 1) pq.push(x);
    }
    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();
    cout << u << " " << v << "\n";
//替换结束
    return 0;
}

/*

树，形式：
5
3 5 2 3


    vector<int> parent(n + 1, 0);

    for (int x : prufer) {
        int u = pq.top(); pq.pop();
        parent[u] = x; // u 的父亲是 x
        if (--deg[x] == 1) pq.push(x);
    }

    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();
    parent[u] = v;
    parent[v] = u; // 因为是无向树，互为父子

    cout << n << "\n";
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << (i == n ? '\n' : ' ');
    }

*/

