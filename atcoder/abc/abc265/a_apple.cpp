//----------------------------
//ABC 265 A
//Apple
//18
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    cout << min((n / 3) * y + (n % 3) * x, n * x) << endl;

    return 0;
}