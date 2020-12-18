//12
//abc133_a_t_or_t
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = min(a * n, b);
    cout << ans << endl;
    return 0;
}

