//----------------------------
//ABC 242 A
//T-shirt
//37
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
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double ans = -1;
    if (x <= a)
    {
        ans = 1.0;
    }
    else if (x <= b)
    {
        ans = (double)c / (b - a);
    }
    else
    {
        ans = 0.0;
    }
    printf("%.7f\n", ans);
    return 0;
}