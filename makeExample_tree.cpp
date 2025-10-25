#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

void init(int c, char** v) {
    rng.seed(time(0) + clock() + (c > 1 ? atoi(v[1]) * 10007 : 0));
}

int rd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(int c, char** v) {
    init(c, v);

    int n = rd(2, 10);

    // 生成 Prüfer 序列
    vector<int> p(n - 2), d(n + 1, 1);
    for (int& x : p) x = rd(1, n), d[x]++;

    // 构建树
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) if (d[i] == 1) q.push(i);

    // 输出格式1：边的形式（每行两个数字）
    // 注释开始
    cout << n << "\n";
    for (int x : p) {
        int u = q.top(); q.pop();
        cout << u << " " << x << "\n";
        if (--d[x] == 1) q.push(x);
    }
    cout << q.top() << " ";
    q.pop();
    cout << q.top() << "\n";
    // 注释结束

    // 输出格式2：父节点数组形式（一行输出所有父节点）
    // 注释开始
    // vector<int> pa(n + 1);
    // for (int x : p) {
    //     int u = q.top(); q.pop();
    //     pa[u] = x;
    //     if (--d[x] == 1) q.push(x);
    // }
    // int a = q.top(); q.pop();
    // int b = q.top(); q.pop();
    // pa[a] = b; pa[b] = a;

    // cout << n << "\n";
    // for (int i = 2; i <= n; i++) cout << pa[i] << " \n"[i == n];
    // 注释结束
    
}
