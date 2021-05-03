//ABC_119_B_Digital_Gifts
//71
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    const double BTC = 380000.0;
    double ans = 0.0;
    rep(i,n)
    {
        double x;
        string s;
        cin >> x >> s;
        if(s == "JPY") ans += x;
        else ans += x * BTC;
    }

    printf("%.6f\n", ans);

    return 0;
}