//823
//abc_141_d_powerful_discount_tickets
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    queue<int> q1;
    queue<int> q2;

    rep(i,n) q1.emplace(a[i]);

    rep(i,m)
    {
        int tq1 = -1,tq2 = -1;
        if(!q1.empty())
        {
            tq1 = q1.front();
        }
        if(!q2.empty())
        {
            tq2 = q2.front();
        }
        int tq = max(tq1,tq2);
        if(tq1 >= tq2) q1.pop();
        else q2.pop();
        q2.emplace(tq/2);
    }

    ll ans = 0;
    while(!q1.empty())
    {
        ans += q1.front();
        q1.pop();
    }
    while(!q2.empty())
    {
        ans += q2.front();
        q2.pop();
    }
    cout << ans << endl;
    return 0;
}