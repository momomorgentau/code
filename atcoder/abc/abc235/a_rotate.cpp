//----------------------------
//ABC 235 A
//Rotate
//9
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
    int a; cin >> a;

    int abc = a % 10;
    a /= 10;
    abc += a % 10;
    a /= 10;
    abc += a;
    int ans = 100 * abc + 10 * abc + abc;
    cout << ans << endl;

    return 0;
}