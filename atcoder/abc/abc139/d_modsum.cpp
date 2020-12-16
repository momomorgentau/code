//357
//abc139_d_modsum
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{   
    ll n;
    cin >> n;
    ll ans = (n-1)*(n)/2;
    cout << ans << endl;
    return 0;
}

/*
1,2,3,4,5,6,7,8
0, 1,2,3,4,5,6,7
*/