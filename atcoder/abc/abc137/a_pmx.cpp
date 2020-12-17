//19
//abc137_a_+-x
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = max({ a + b,a - b,a * b });
    cout << ans << endl;
    return 0;
}
