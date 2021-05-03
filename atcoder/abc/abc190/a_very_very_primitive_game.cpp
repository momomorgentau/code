//ABC_190_A_Very_Very_Primitive_Game
//14
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string  ans;
    if (a > b) ans = "Takahashi";
    else if (a < b) ans = "Aoki";
    else
    {
        if (c == 1) ans = "Takahashi";
        else ans = "Aoki";
    }
    cout << ans << endl;
    return 0;
}