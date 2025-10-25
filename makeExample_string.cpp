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

string randStr(int len, const string& charset = "abcdefghijklmnopqrstuvwxyz") {
    string s;
    int m = charset.size();
    for (int i = 0; i < len; ++i)
        s += charset[rdm(0, m - 1)];
    return s;
}


int main(int argc, char* argv[]){


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initRand(argc, argv); // ★ 一行搞定随机初始化

    cout << randStr(8)<<endl;                       // 随机小写字母串
    cout << randStr(6, "01")<<endl;                 // 随机二进制串
    cout << randStr(12, "ABCDEF0123456789")<<endl;  // 随机十六进制串


}