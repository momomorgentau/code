//ABC_117_D_XXOR
//1423
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> bit_hist(60);
    rep(i,n)
    {
        ll ai = a[i];
        int bit = 0;
        while(ai >=  (ll(1)<<bit))
        {
            if(ai & (ll(1)<<bit)) bit_hist[bit]++;
            ++bit;
        }
    }
    vector<pair<ll,ll>> bit_ness;
    for(int key = bit_hist.size()-1; key >=0;--key)
    {
        ll add = (ll(1)<<key);  
        if(2*bit_hist[key] < n && add <= k)
        {
             bit_ness.emplace_back(add,add*(n-2*bit_hist[key]));
        }
    }

    ll ans = 0;
    queue<tuple<int,ll,ll>> q;
    int s = bit_ness.size();
    q.emplace(0,k,0);
    if(s == 0) q.pop();

    while(!q.empty())
    {
        int key;
        ll rem,score;
        tie(key,rem,score) = q.front();
        q.pop();
        if(bit_ness[key].first <= rem)
        {
            //keyを選択しない
            ll now = 0;
            for(int i = key+1; i < s; ++i)
            {
                now += bit_ness[i].second;
            }
            ans = max(ans,score+now);
            //keyを選択
            rem -= bit_ness[key].first;
            score += bit_ness[key].second;
            ans = max(ans,score);
            if(rem > 0 && key+1 < s)
            {
                q.emplace(key+1,rem,score);
            }
        }
        else
        {
            if(key+1 < s) q.emplace(key+1,rem,score);
        }
    }
    rep(i,n) ans += a[i];
    cout << ans << endl;
    return 0;
}
/*
7 : 0 1 1 1
4 : 0 1 0 0
0 : 0 0 0 0
3 : 0 0 1 1



*/