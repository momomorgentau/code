//066
//Base 8 to 9
//*2

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    string n;
    ll k;
    cin >> n >> k;

    if (n == "0")
    {
        cout << 0 << endl;
        return 0;
    }

    rep(i, k)
    {
        ll now = 0;
        for (char& c : n)
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
        n = res;
    }
    cout << n << endl;

    return 0;
}