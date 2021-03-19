//ABC_127_B_Algae
//26
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int r, d, x;
    cin >> r >> d >> x;
    int ans = r * x - d;
    rep(i, 10)
    {
        cout << ans << endl;
        ans = ans * r - d;
    }
    return 0;
}