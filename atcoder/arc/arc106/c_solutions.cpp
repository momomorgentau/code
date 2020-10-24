//1198
//arc106c_solutions

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    if (m < 0 || ((m > n - 2) && n > 1))
    {
        cout << -1 << endl;

    }
    else if (m == 0)
    {
        rep(i, n) cout << i * 2 + 1 << " " << i * 2 + 2 << endl;
    }
    else
    {
        int r = 2 * (m + 1) + 2;//I“_
        cout << 1 << " " << r << endl;
        rep(i, m + 1) cout << i * 2 + 2 << " " << i * 2 + 3 << endl;

        n -= (m + 2);
        while (n > 0)
        {
            cout << r + 1 << " " << r + 2 << endl;
            r += 2;
            --n;
        }

    }

    return 0;
}
