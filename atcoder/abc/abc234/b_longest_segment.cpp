//----------------------------
//ABC 234 B
//Longest Segment
//46
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    double ans = -1;
    rep(i, n)rep(j, n)
    {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        double l = sqrt(dx * dx + dy * dy);
        ans = max(ans, l);
    }
    printf("%.7f", ans);
    return 0;
}

