//47
//abc134_b_golden_apple
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int s = 2 * d + 1;
    int ans = (n + s - 1) / s;
    cout << ans << endl;
    return 0;
}


