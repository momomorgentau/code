//ABC_208_A
//Alloy
//5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b == 0) cout << "Gold" << endl;
    else if (a == 0) cout << "Silver" << endl;
    else cout << "Alloy" << endl;
    return 0;
}