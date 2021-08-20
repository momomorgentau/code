//ABC_208_D
//Querying Multiset
//775
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main()
{
    int q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll base = 0;
    rep(i, q)
    {
        int p, x;
        cin >> p;
        if (p == 1)
        {
            cin >> x;
            pq.emplace(x - base);
        }
        else if (p == 2)
        {
            cin >> x;
            base += x;
        }
        else
        {
            printf("%lld\n", pq.top() + base);
            pq.pop();
        }
    }

    return 0;
}