//ABC_204_B
//Nuts
//9
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() 
{
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a > 10) ans += a - 10;
    }
    cout << ans << endl;
    return 0;
}

