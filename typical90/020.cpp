//020
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll d = 1;
    while(b--) d *= c; 
    if(a<d) cout << "Yes" << endl;
    else cout << "NO" << endl; 
    return 0;
}