//20
//abc139_a_tenki
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int ans = 0;
    rep(i,3)
    {
        if(s[i] == t[i]) ++ans;
    }
    cout << ans << endl;   

    return 0;
}
