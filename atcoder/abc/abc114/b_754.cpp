//ABC_114_B_754
//148
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    string s;
    cin >> s;
    int ans = 1e9;
    for(int i = 0;i <s.size()-2;++i)
    {
        int now = 0;
        rep(j,3)
        {
            now += s[i+j]-'0';
            now *= 10;
        }
        ans = min(ans,abs(753-now/10));
    }
    cout << ans << endl;
    return 0;
}