#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x > 0) {
        pos += 1;
      } else if (x < 0) {
        neg += 1;
      } else {
        zero += 1;
      }
    }
    int ans = std::abs(pos - m);
    if ((pos > m && !zero && !neg) || (pos < m && pos + neg - 1 < m)) {
      ans = -1;
    }
    std::cout << ans << '\n';
  

  return 0;
}
