//1007
//abc166E - This Message Will Self-Destruct in 5s
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n),d(n);
    
    rep(i,n)
    {
        s[i] = i+1+a[i];
        d[i] = i+1-a[i];
    }
    map<int,int> mp;

    ll ans = 0;
    rep(i,n)
    {
        ans += mp[d[i]];
        ++mp[s[i]];
    }
    cout << ans << endl;
    return 0;
}

//i2-i1 = a2+a1
//i2-a2 = i1+a1
//d2 = s1
//d > s
/*
|i1-i2| = a1+a2
->
i1-i2 = a1+a2 <=> m1=-m2
or
i2-i1 = a1+a2 <=> 
i1-a1 = m1
i2-a2 = m2
*/