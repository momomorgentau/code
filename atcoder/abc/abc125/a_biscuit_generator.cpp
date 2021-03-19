//ABC_125_A_Biscuit_Generator
//18
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    int a, b, t;
    cin >> a >> b >> t;
    int ans = b * (t / a);
    cout << ans << endl;
    return 0;
}