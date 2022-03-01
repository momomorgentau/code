//----------------------------
//ABC 231 C
//Counting 2
//194
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    while (q--)
    {
        int x; cin >> x;
        int d = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << n - d << endl;
    }
    return 0;
}

