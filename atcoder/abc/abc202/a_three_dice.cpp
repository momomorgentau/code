//ABC_202_A
//Three_Dice
//4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 21 - (a + b + c);
    cout << ans << endl;
    return 0;
}