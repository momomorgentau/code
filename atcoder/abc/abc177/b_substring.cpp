#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
int main()
{
    string s, t;
    cin >> s >> t;

    int ls = s.length();
    int lt = t.length();
    int ans = 0;

    rep(i, ls - lt + 1) {
        int cnt = 0;
        rep(j, lt) {
            if (s[j + i] == t[j]) ++cnt;
        }
        ans = max(cnt, ans);
    }
    ans = lt - ans;
    cout << ans << endl;
    return 0;
}