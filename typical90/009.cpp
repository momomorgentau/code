//009
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

const double PI = 3.14159265358979;

typedef struct Position
{
    int x;
    int y;
};

double getAngle(int a,vector<Position> &P)
{
    vector<double> angle;
    int sz = P.size();
    int x = P[a].x;
    int y = P[a].y;

    rep(i,sz)
    {
        if(i == a) continue;
        double theta = atan2(P[i].y-y,P[i].x-x);
        theta *= 180.0/ PI;
        if(theta <= 0) theta += 360.0;
        angle.emplace_back(theta);
    }

    sort(angle.begin(),angle.end());
    double res = 0;
    for(auto t:angle)
    {
        double target = t;
        if(target <= 180.0) target += 180.0;
        else target -= 180.0;
        int idx = lower_bound(angle.begin(),angle.end(),target)-angle.begin();
        int idx1 = idx % angle.size();
        int idx2 = (idx-1 + angle.size()) % angle.size();

        double ans1 = abs(angle[idx1]-t);
        double ans2 = abs(angle[idx2]-t);
        if(ans1 >= 180) ans1 = 360.0 - ans1;
        if(ans2 >= 180) ans2 = 360.0 - ans2;

        res = max({res,ans1,ans2});
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Position> P(n);
    rep(i,n)
    {
        int x,y; cin >> x >> y;
        P[i].x = x;
        P[i].y = y;
    }
    double ans = 0;
    rep(i,n)
    {
        ans = max(ans,getAngle(i,P));
    }
    printf("%.9f\n",ans);
    return 0;
}