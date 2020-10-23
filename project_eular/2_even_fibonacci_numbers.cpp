//5%
//PROJECT_EULAR_2_even_fibonacci_numbers
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int f = 2;
    int pf = 1;

    int end = 4 * 1e6;
    ll ans = 0;

    while (f <= end)
    {
        if (!(f & 1)) ans += f;
        int tmp = f;
        f += pf;
        pf = tmp;
    }
    cout << ans << endl;
    return 0;
}
