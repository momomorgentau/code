#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
    int main()
{
    int  rem = 0;
    int k;
    cin >> k;
    vector<bool> app(k);

    int cnt = 0;
    while (1)
    {
        cnt++;
        rem = (rem * 10 + 7) % k;

        if (rem == 0) break;
        else if (app[rem - 1])
        {
            cnt = -1;
            break;
        }
        else app[rem - 1] = true;
    }
    cout << cnt << endl;
    return 0;
}