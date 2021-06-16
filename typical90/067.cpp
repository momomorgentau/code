//066
//*2

//TLE‚µ‚Ü‚·
//Sample  3/3 AC
//All    25/28 AC
//        3/28 TLE
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    string s = to_string(n);
    rep(i, k)
    {
        ll now = 0;
        for (char& c : s)
        {
            now *= 8;
            now += (ll)(c - '0');
        }
        string res = "";
        while (now > 0)
        {
            res += (now % 9) + '0';
            now /= 9;
        }
        reverse(res.begin(), res.end());

        rep(j, res.size())
        {
            if (res[j] == '8') res[j] = '5';
        }
        s = res;
    }
    cout << s << endl;

    return 0;
}