//ABC_213_C
//Reorder Cards
//481
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    map<int, int> mph, mpw;
    rep(i, n)
    {
        mph[A[i]]++;
        mpw[B[i]]++;
    }
    map<int, int> table_h, table_w;
    int idx = 1;
    for (auto const& [a, ignore] : mph)
    {
        table_h[a] = idx;
        ++idx;
    }
    idx = 1;
    for (auto const& [b, ignore] : mpw)
    {
        table_w[b] = idx;
        ++idx;
    }
    rep(i, n)
    {
        cout << table_h[A[i]] << " " << table_w[B[i]] << endl;
    }
    return 0;
}