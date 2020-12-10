//686
//abc144_d_triangles
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;


int main() {

    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;

    rep(i, n - 2) {
        int lmax = l[i];
        for (int j = i + 1; j < n - 1; j++) {
            int dif = lmax - l[j];
            for (int k = j + 1; k < n; ++k) {
                if (l[k] <= dif) break;
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}