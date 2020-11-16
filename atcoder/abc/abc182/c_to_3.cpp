//235
//abc182c_to_3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int inf = 1e9;
int solve1()
{
    string s;
    cin >> s;
    vector<int> r3(3,0);
    int l = s.length();
    rep(i,l)
    {
        int d = s[i]-'0';
        ++r3[d%3];
    }
    int r = r3[1] + r3[2]*2;
    
    int ans = inf;
    rep(i1,3)rep(i2,3)
    {
        if(i1 > r3[1]) continue;
        if(i2 > r3[2]) continue;
        int tr = r - i1 - i2*2;
        if(tr % 3 == 0)
        {
            ans = min(ans,i1+i2);
        }
    }
    if(ans == l) ans = -1;
    cout << ans << endl;
    return 0;
}
//bit全探索
int solve2()
{
    string s;
    cin >> s;
    vector<int> d;
    int l = s.length();
    rep(i, l) d.emplace_back(s[l-1-i]-'0');

    int ans = inf;
    reps(i,1,(1<<l))
    {
        ll ts = 0;
        int cnt = 0;
        ll a = 1;
        rep(j,l) 
        {
            if((i & (1<<j)) != 0) 
            {
                ts += d[j]*a;
                a*=10;
            }
            else ++cnt;
        }
        if(ts % 3 == 0) ans = min(ans, cnt);
    }
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}

int main()
{
    solve2();
    return 0;
}