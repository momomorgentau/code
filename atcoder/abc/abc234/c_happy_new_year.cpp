//----------------------------
//ABC234 C
//Happy New Year!
//155
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll k;
    cin >> k;
    string ans = "";
    while (k > 0)
    {
        ans += (k % 2 == 0) ? '0' : '2';
        k /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}