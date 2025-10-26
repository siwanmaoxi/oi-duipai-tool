#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

// 初始化随机数种子
void init(int c, char** v) {
    rng.seed(time(0) + clock() + (c > 1 ? atoi(v[1]) * 10007 : 0));
}

// 返回 [l, r] 的随机整数
int rd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(int c, char** v) {
    init(c, v);

    int n = rd(1, 10);
    cout << n<< "\n";

    vector<int> lis(n,0);

    for (int i = 0; i < n; i++){
        lis[i]=i+1;
    }

    for (int i = 0; i < n; i++){
        int tp = rd(0,n-1);
        int tmp;
        tmp=lis[tp];
        lis[tp]=lis[i];
        lis[i]=tmp;
    }




    for (int i = 0; i < n; i++) {
        cout<<lis[i]<<" ";
    }
    // cout<<"yes";
}
