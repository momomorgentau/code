//1354
//abc128_d_equeue
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];

    vector<int> vf(n+1);
    vector<int> vb(n+1);

    vf[0] = vb[0] = 0;
    rep(i,n) vf[i+1] = vf[i] + v[i];
    rep(i,n) vb[i+1] = vb[i] + v[n-i-1];

    vector<vector<int>> mf(n+1);
    vector<vector<int>> mb(n+1);

    rep(i,n)
    {
        for(auto ai:mf[i])
        {
            mf[i+1].emplace_back(ai);
        }
        if(v[i] < 0) mf[i+1].emplace_back(v[i]);
    }

    rep(i,n)
    {
        for(auto ai:mb[i])
        {
            mb[i+1].emplace_back(ai);
        }
        if(v[n-i-1] < 0) mb[i+1].emplace_back(v[n-i-1]);
    }

    int ans = 0;
    reps(i,1,k+1)
    {
        int ti = min(i,n);
        int tans = 0;
        rep(j,ti+1)
        {
            int tj = j;
            int rtj = ti - j;
            tans = vf[tj] + vb[rtj];

            vector<int> minus = mf[tj];
            minus.insert(minus.end(),mb[rtj].begin(),mb[rtj].end());
            sort(minus.begin(),minus.end());
            int rm_num = k-ti;
            rep(rmi,rm_num) 
            {
                if(rmi < minus.size()) tans -= minus[rmi];
            }
            ans = max(ans,tans);
        }
    }
    cout << ans <<endl;
    return 0;
}