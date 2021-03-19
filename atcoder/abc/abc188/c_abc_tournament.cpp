//ABC_188_C_ABC_Tournament
//120
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(1<<n);
    rep(i, 1<<n)
    {
        int ai;
        cin >> ai;
        a[i] = make_pair(ai,i);
    }

    while (1)
    {
        vector<pair<int,int>> ta;
        ta = a;
        int s = ta.size()/2;
        if (s == 1) break;
        a.clear();

        rep(i,s)
        {
            int a1 = ta[2 * i].first;
            int a2 = ta[2 * i + 1].first;
            if (a1 > a2) a.emplace_back(ta[2*i]);
            else a.emplace_back(ta[2*i+1]);
        }
    }

    if (a[0].first < a[1].first) cout << a[0].second +1<< endl;
    else cout << a[1].second+1 << endl;

    return 0;
}