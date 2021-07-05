//ABC_208_B
//Factorial Yen Coin
//51
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int p;
    cin >> p;
    vector<int> c(10, 1);
    rep(i, 9)
    {
        c[i + 1] = c[i] * (i + 2);
    }
    int ans = 0;
    for (int i = 9; i >= 0; --i)
    {
        while (p - c[i] >= 0)
        {
            p -= c[i];
            ++ans;
        }
        if (p == 0) break;
    }
    cout << ans << endl;
    return 0;
}