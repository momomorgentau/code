//51
//abc132_b_ordibary_number
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& e : p) cin >> e;
    int ans = 0;
    rep(i, n - 2)
    {
        int p1, p2, p3;
        p1 = p[i];
        p2 = p[i + 1];
        p3 = p[i + 2];
        if (p1 < p2 && p2 < p3) ++ans;
        if (p1 > p2 && p2 > p3) ++ans;

    }
    cout << ans << endl;
    return 0;
}

