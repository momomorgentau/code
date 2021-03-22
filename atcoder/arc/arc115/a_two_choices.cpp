//ARC_115_A_Two_Choices
//641
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<int> v(2);
    //0の数をカウント
    rep(i,n)
    {
        string s;
        cin >> s;
        ll now = 0;
        for(char c:s) if(c == '0') ++now;
        v[now%2]++;
    }

    ll ans = ll(v[0])*v[1];
    cout << ans << endl;

    return 0;
}

