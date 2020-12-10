//741
//abc146_c_buy_an_integer
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{

    ll a,b,x;
    cin >> a >> b >> x;
    ll ac = -1;
    ll wa = 1e9+5;
    while(wa-ac > 1)
    {
        ll mid = (wa+ac)/2;
        int d = 0;
        ll tmid = mid;
        while(tmid > 0)
        {
            ++d;
            tmid /= 10;
        }
        ll s = a*mid+b*d;
        if(s <= x) ac = mid;
        else wa = mid;
    }
    ac = min(ll(1e9),max(ll(0),ac));
    cout << ac << endl;
}