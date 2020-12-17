//90
//abc135_b_0_or_1_swap
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
    bool ok = false;
    rep(i, n)rep(j, n)
    {
        if (i > j) continue;
        vector<int> tp = p;
        swap(tp[i], tp[j]);
        bool tok = true;
        rep(i, n - 1)
        {
            if (tp[i] >= tp[i + 1])
            {
                tok = false;
                break;
            }

        }
        if (tok) ok = true;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}



