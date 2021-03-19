//ABC_126_C_Dice_and_Coin
//638
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 1;
    int now = 1;
    double ans = 0;
    rep(i, n)
    {
        int tn = n - i;
        now *= tn;
        while (now < k)
        {
            now *= 2;
            cnt *= 2;
        }
        ans += 1.0 / cnt;
        now /= tn;
    }
    ans /= (double)n;
    printf("%.10f", ans);
    return 0;
}