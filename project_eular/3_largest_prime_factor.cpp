//5%
//project_eular_3_largest_prime_factor

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    ll n = 600851475143;

    ll i = 2;
    while (i * i <= n)
    {
        if (n % i == 0) {
            while (1)
            {
                n /= i;
                if (n % i != 0) break;
            }
        }
        ++i;
    }
    cout << n << endl;
    return 0;
}
