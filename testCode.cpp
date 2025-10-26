#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define L(i, j, k, len) for(int i = (j); i < (k); i+=(len))
#define R(i, j, k, len) for(int i = (j); i > (k); i-=(len))
#define all(x) (x).begin(),(x).end()
#define allp(x,n) (x).begin()+(n),(x).end()
#define ms(x,y) memset(x,y,sizeof(x))
#define dbg(x) cerr<<__LINE__<<" | "<<#x<<" = "<<x<<"\n"
#define dbgl(i,x) cerr<<__LINE__<<" ["<<#i<<"]: "<<i<<" -> { "<<#x<<" = "<<x<<" }\n"
#define ok cerr<<"ok"<<"\n"
#define YES cout<<"YES"<<"\n"
#define NO  cout<<"NO"<<"\n"
#define Yes cout<<"Yes"<<"\n"
#define No  cout<<"No"<<"\n"

#ifdef KROWFEATHER
    #include<bits/KrowFeather.h>
#endif
#define int long long
using ull = unsigned long long;                                                                              
using ll = long long;
using pii = pair<int,int>;
using psi = pair<string,int>;
constexpr ll MOD = 1e9+7;


inline void solve(){
   int n;
   cin >> n;
   vector<int> arr(n + 2);
   int pl, pr;
   for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) pl = i;
    if (arr[i] == n) pr = i;
   }

   int vl = 1, vr = n;
   vector<pii> ans;

   auto find = [&](int v) {
    for (int i = 1; i <= n; i++) {
        if (v == arr[i]) return i;
    }
    assert(0);
   };

   while (vl < vr) {
    if (pl == arr[pl]) {
        vl++;
        pl = find(vl);
        continue;
    }
    if (pr == arr[pr]) {
        vr--;
        pr = find(vr);
        continue;
    }

    while(pl < vr && arr[pl + 1] < arr[vl]) pl++;
    while(pr > vl && arr[pr - 1] > arr[vr]) pr--;

    int lena = pl - vl + 1, lenb = vr - pr + 1;
    if (lena > lenb) {

        // for (int i = 1; i <= n; i++) {
        //     cerr << arr[i] << " ";
        // }
        // cerr << endl;

        sort(arr.begin() + vl, arr.begin() + pl + 1);
        // cerr << vl << " " << pl << " vlpl \n";
        // for (int i = 1; i <= n; i++) {
        //     cerr << arr[i] << " ";
        // }
        // cerr << endl;
        ans.push_back({vl, pl});
        vl++;
        pl = find(vl);
        pr = find(vr);

    } else {
        ans.push_back({pr, vr});
        for (int i = 1; i <= n; i++) {
            cerr << arr[i] << " ";
        }
        // cerr << endl;
        sort(arr.begin() + pr, arr.begin() + vr + 1);
        // cerr << pr << " prvr " << vr << endl;
        // for (int i = 1; i <= n; i++) {
        //     cerr << arr[i] << " ";
        // }

        vr--;
        pr = find(vr);
        pl = find(vl);
    }
   }

   if (ans.size() <= n/2) {
    cout << "YES\n";
    return;
   }

   cout << ans.size() << endl;
   for (auto [v, u] : ans) {
    cout << v << " " << u << endl;
   }


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(20);

    int T=1;
    while(T--){
        solve();
    }
    return 0;
}