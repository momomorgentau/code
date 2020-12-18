//165
//abc133_b_good_distance
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n)rep(j, d) cin >> x[i][j];

    int ans = 0;
    rep(i, n)rep(j, n)
    {
        if (i >= j) continue;
        int sum = 0;
        rep(k, d)
        {
            sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        }
        for (int k = 1; k * k <= sum; ++k)
        {
            if (k * k == sum) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}

