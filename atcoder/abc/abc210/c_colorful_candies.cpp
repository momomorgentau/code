//ABC_210_C
//Colorful Candies
//359
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    queue<int> q;
    map<int, int> mp;
    int now = 0;
    rep(i, k)
    {
        if (mp[c[i]] == 0) ++now;
        mp[c[i]]++;
        q.emplace(c[i]);
    }
    int ans = now;
    reps(i, k, n)
    {
        int p = q.front();
        q.pop();
        --mp[p];
        if (mp[p] == 0) --now;

        if (mp[c[i]] == 0) ++now;
        ++mp[c[i]];
        q.emplace(c[i]);
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}