//1197
//abc125_c_gcd_on_blackboard
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//多分嘘です
void solve1()
{
        int n;
    cin >> n;
    vector<int> a;
    map<int,int> mp;
    rep(i,n)
    { 
        int ai; cin >> ai;
        if(mp[ai]== 2) continue;
        a.emplace_back(ai);
        ++mp[ai];
    }
    int ans = 1;
    int len = a.size();
    rep(i,len)
    {
        int g = 0;
        rep(j,len)
        {
            if (i == j) continue;
            g = __gcd(a[j],g);
            if(g<=ans)break;
        }
        ans = max(ans,g);
    }
    cout << ans << endl;
}
//公式解説
void solve2()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> l(n);
    vector<int> r(n);
    rep(i,n-1)
    {
        l[i+1] = __gcd(l[i],a[i]);
        r[n-i-2] = __gcd(r[n-i-1],a[n-i-1]);
    }
    int ans = 1;
    rep(i,n) ans = max(ans, __gcd(l[i],r[i]));
    cout << ans << endl;
}

int main()
{
    //solve1();
    solve2();
    return 0;
}

/*
12345678
 2345678
1 345678
12 45678
*/