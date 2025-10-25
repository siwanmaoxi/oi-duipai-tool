#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

void init(int c, char** v) {
    rng.seed(time(0) + clock() + (c > 1 ? atoi(v[1]) * 10007 : 0));
}

int rd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 生成随机字符串
string rs(int len, string s = "abcdefghijklmnopqrstuvwxyz") {
    string ret;
    for (int i = 0; i < len; i++) ret += s[rd(0, s.size() - 1)];
    return ret;
}

int main(int c, char** v) {
    init(c, v);

    cout << rs(8) << "\n";                      // 小写字母
    cout << rs(6, "01") << "\n";                // 二进制
    cout << rs(12, "ABCDEF0123456789") << "\n"; // 十六进制
}
