//011
//*6
//task2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

void chmax(ll& a,ll b){a = max(a,b);};

const int D = 5000;

ll dp[5010][1<<20];
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
    ll ans = 0;

    set<tuple<int,int,int>> s;
    s.emplace(0,0,0);
    while(!s.empty())
    {
        int m,c,bit;
        tie(m,c,bit) = *s.begin();

        s.erase(make_tuple(m,c,bit));
        bool wei = false;
        rep(i,n)
        {
            int td,tc,ts;
            tie(td,tc,ts) = v[i];
            if(bit&(1<<i)) continue;
            if(c+tc > td) continue;
            s.emplace(m+1,c+tc,bit|(1<<i));
            wei = true;
        }
        if(!wei)
        {
            ll now = 0;
            rep(i,n)
            {
                if((1<<i)&bit) now += get<2>(v[i]);
            }
            ans = max(ans,now);
        }
    }
    
    cout << ans << endl;
    return 0;
}