//ABC_191_B_Remove_It
//23
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        if (a[i] == x) continue;
        else cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}