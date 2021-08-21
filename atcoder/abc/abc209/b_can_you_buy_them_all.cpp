//ABC_209_B
//Can you buy them all?
//13
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, x;
    cin >> n >> x;
    rep(i, n)
    {
        int a; cin >> a;
        if ((i + 1) % 2 == 0) --a;
        x -= a;
    }
    if (x >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}