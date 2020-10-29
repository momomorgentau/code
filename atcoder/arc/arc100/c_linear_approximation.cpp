//1098
//arc100c_linear_approximation
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        int ta; cin >> ta;
        a[i] = ta - (i + 1);
    }
    sort(a.begin(), a.end());
    int b = a[a.size() / 2];

    ll ans = 0;
    rep(i, n) ans += abs(a[i] - b);

    cout << ans << endl;

    return 0;
}