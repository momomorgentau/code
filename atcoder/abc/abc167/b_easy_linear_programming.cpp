//7
//abc167b_easy_linear_programming
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans;
    if (k <= a) ans = k;
    else if (k <= a + b) ans = a;
    else ans = a - (k - a - b);

    cout << ans << endl;

    return 0;
}
