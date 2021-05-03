//ABC_190_B_Magic_3
//21
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, s, d;
    cin >> n >> s >> d;
    bool ok = false;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x < s && y > d) ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

