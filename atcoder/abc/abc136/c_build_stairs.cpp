//308
//abc136_c_build_stairs
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
    for (auto& e : a) cin >> a;
    int mn = a[0]-1;
    bool ok = true;
    for (auto ai : a)
    {
        if (ai - 1 < mn) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
