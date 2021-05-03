//ABC_115_A_Christmas_Eve_Eve_Eve
//18
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int d;
    cin >> d;
    string ans = "Christmas";
    rep(i,25-d) ans += " Eve";
    cout << ans << endl;
    return 0;
}