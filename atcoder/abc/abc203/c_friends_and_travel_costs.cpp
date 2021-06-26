//ABC_203_C
//Friends_and_Travel_costs
//168
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() 
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab;
    rep(i, n)
    {
        ll ai, bi;
        cin >> ai >> bi;
        ab.emplace_back(ai, bi);
    }
    sort(ab.begin(), ab.end());
    ll now = 0;
    for (auto [a, b] : ab)
    {        
        if (a - now <= k)
        {
            k -= a - now;
            k += b;
            now = a;
        }
        else break;
    }
    cout << now + k << endl;
    return 0;
}

