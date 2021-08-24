//ABC_214_A
//New Generation ABC
//4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    int ans = -1;
    if (n <= 125) ans = 4;
    else if (n <= 211) ans = 6;
    else ans = 8;
    cout << ans << endl;
    return 0;
}