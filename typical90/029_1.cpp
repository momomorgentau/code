//029
//*5
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int w, n;
    cin >> w >> n;

    vector<int> g(w + 1, 0);
    while (n--)
    {
        int l, r; cin >> l >> r;
        int now = 0;
        reps(i, l, r + 1) now = max(now, g[i]);
        reps(i, l, r + 1) g[i] = now + 1;
        cout << now + 1 << endl;
    }

    return 0;
}