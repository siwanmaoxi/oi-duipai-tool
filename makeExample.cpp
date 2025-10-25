#include <bits/stdc++.h>
using namespace std;

// 全局随机引擎
mt19937 gen;

// 初始化随机数种子（可传命令行参数）
void initRand(int argc, char* argv[]) {
    int seed = time(0) + clock();
    if (argc > 1) seed += atoi(argv[1]) * 10007; // 对拍用：不同参数不同种子
    gen.seed(seed);
}

// 返回 [l, r] 的随机整数
    int rdm(int l, int r) {
        uniform_int_distribution<int> dis(l, r);
        return dis(gen);
    }

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initRand(argc, argv); // 初始化随机数种子

    int n = rdm(1, 30),m = rdm(1, 30); // 随机生成 n
    cout << n <<" "<<m<< '\n';

    for (int i = 0; i < n; ++i) {
        cout << rdm(-1, 1) << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
