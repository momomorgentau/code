//36
//abc137_b_one_clue
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int  k, x;
    cin >> k >> x;
    --k;
    const int mn = -1000000;
    const int mx = 1000000;

    int l = max(mn, x - k);
    int r = min(mx, x + k);

    for (int i = l; i <= r; ++i) cout << i << " ";
    cout << endl;

    return 0;
}

