#include <bits/stdc++.h> #define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<int> hab(n + 1, 0);
    rep(i, n + 1) ++hab[a[i]], ++hab[b[i]];

    int mst = 0;
    rep(i, n + 1) mst = max(mst, hab[i]);

    if (mst > n) {
        cout << "No" << endl;
        return 0;
    }
    //降順にソート
    sort(b.begin(), b.end(), greater<int>());
    //かぶっている文字を求める
    int same;
    rep(i, n) {
        if (a[i] == b[i]) {
            same = a[i];
            break;
        }
    }

    //交換可能な場所を求める。
    vector<int> sw;
    rep(i, n) {
        if (a[i] == same || b[i] == same) continue;
        sw.emplace_back(i);
    }

    //交換する.
    int idx = 0;
    rep(i, n) {
        if (a[i] == same && b[i] == same) {
            int p = sw[idx];
            swap(b[i], b[p]);
            ++idx;
        }
    }

    cout << "Yes" << endl;
    rep(i, n) cout << b[i] << " ";
    cout << endl;

    return 0;
}