//15
//abc143_a_curtain
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = max(0, a - 2 * b);
    cout << ans << endl;
    return 0;
}