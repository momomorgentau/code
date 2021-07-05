//ABC_207_A
//Repression
//6
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = max({ a + b,b + c,c + a });
    cout << ans << endl;
    return 0;
}