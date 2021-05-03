//ABC_191_A_Vanishing_Pitch
//25
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    if (v * t <= d && d <= v * s) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}