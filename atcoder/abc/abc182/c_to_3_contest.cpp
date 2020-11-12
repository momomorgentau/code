//235
//abc182c_to_3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    vector<int> d(3); //—]‚è
    rep(i, l)
    {
        int di = s[i] - '0';
        ++d[di % 3];
    }
    int d1 = d[1];
    int d2 = d[2];

    int md = max(d[1], d[2]);
    d[1] = abs(d[1] - md);
    d[2] = abs(d[2] - md);

    d[1] = d[1] % 3;
    d[2] = d[2] % 3;
    int ans = -1;
    if (d[1] == 0 && d[2] == 0) ans = 0;
    else ans = d[1] + d[2];
    if (ans == l) ans = -1;

    d1 %= 3;
    d2 %= 3;
    int tans = -1;
    if (d1 == 0 && d2 == 0) tans = 0;
    else if (d1 == 1 && d2 == 1) tans = 0;
    else if (d1 == 2 && d2 == 2) tans = 0;
    else tans = d1 + d2;

    ans = min(ans, tans);
    cout << ans << endl;

    return 0;
}

