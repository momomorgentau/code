//926
//abc134_d_preparing_boxes
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    vector<int> s(n);
    vector<int> ans;

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == s[i] % 2) continue;
        int ni = i + 1;
        vector<int> g;
        for (ll j = 1; j * j <= ni; ++j)
        {
            if (ni % j != 0) continue;
            g.emplace_back(j);
            if (j * j == ni) continue;
            g.emplace_back(ni / j);
        }
        int gn = g.size();
        for (auto gi : g) ++s[gi - 1];
        ans.emplace_back(ni);
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto ai : ans) cout << ai << " ";
    cout << endl;
    return 0;
}


