//diff54
//abc183_b_billiards
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

int main()
{
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    gy = -gy;

    double gr = (gy - sy) / (gx - sx);

    double ans = -sy / gr + sx;
    cout << fixed << setprecision(7);
    cout << ans << endl;


    return 0;
}