//028
//Cluttered_Paper
//*4

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int imos[1005][1005];
int M = 1000;
int main()
{
    int n; cin >> n;
    rep(i, n)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int j = ly; j < ry; ++j)
        {
            ++imos[j][lx];
            --imos[j][rx];
        }
    }
    rep(i, M)rep(j, M)
    {
        imos[i][j + 1] += imos[i][j];
    }
    vector<int> ans(n + 1);
    rep(i, M)rep(j, M)
    {
        ++ans[imos[i][j]];
    }
    reps(i, 1, n + 1) cout << ans[i] << endl;
    return 0;
}