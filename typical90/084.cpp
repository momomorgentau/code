//084
//There are two types of characters
//*3

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<int, int, int, int>;

int main()
{
    ll n;
    string s;
    cin >> n >> s;
    char pre = 'X';
    ll l = 0;
    ll ans = n * (n + 1) / 2;
    for (auto& c : s)
    {
        if (c == pre) l++;
        else
        {
            ans -= l * (l + 1) / 2;
            l = 1;
            pre = c;
        }
    }
    ans -= l * (l + 1) / 2;

    cout << ans << endl;
    return 0;
}