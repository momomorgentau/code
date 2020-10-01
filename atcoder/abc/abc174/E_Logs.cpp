#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    rep(i, n) cin >> a[i];

    int up = *max_element(a.begin(), a.end());
    int low = 0;
    int mid;
    int cnt = 0;

    while (up - low > 1)
    {
        cnt = 0;
        mid = (up + low) / 2;

        rep(i, n)
        {
            if (a[i] % mid == 0) cnt += a[i] / mid - 1;
            else cnt += a[i] / mid;

            if (cnt > k)
            {
                low = mid;
                break;
            }
        }
        if (cnt <= k) up = mid;
    }
    cout << up;
    return 0;
}