//ABC_127_A_Ferris_Wheel
//15
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a <= 5) ans = 0;
    else if (a <= 12) ans = b / 2;
    else ans = b;
    cout << ans << endl;
    return 0;
}