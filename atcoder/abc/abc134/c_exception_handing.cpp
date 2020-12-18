//136
//abc134_c_exception_handing
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
    for (auto& e : a)cin >> e;
    vector<int> sa = a;
    sort(sa.begin(), sa.end());
    int b1 = sa[n - 1];
    int b2 = sa[n - 2];
    if (b1 == b2)
    {
        rep(i, n) cout << b1 << endl;
    }
    else
    {
        rep(i, n)
        {
            if (a[i] != b1) cout << b1 << endl;
            else cout << b2 << endl;
        }
    }
    return 0;
}


