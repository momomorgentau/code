//011
//*6
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int,int,int>> v;
    rep(i,n)
    {
        int d,c,s; cin >> d >> c >> s;
        v.emplace_back(d,c,s); 
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    rep(i,1<<n)
    {
        int bit = i;
        vector<tuple<int,int,int>> tmp;
        rep(j,n)
        {
            if((1<<j)&bit) continue;
            tmp.emplace_back(v[j]);
        }

        do
        {
            ll now = 0;
            ll date = 0;
            for(auto[d,c,s]:tmp)
            {
                if(date+c > d) continue;
                date += c;
                now += s;
            }
            ans = max(ans,now);        
        } while (next_permutation(tmp.begin(),tmp.end()));
    }
    cout << ans << endl;
    return 0;
}