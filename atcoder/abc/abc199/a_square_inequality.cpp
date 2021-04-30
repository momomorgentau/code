//ABC_199_A
//Square_Inequality
//5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a*a+b*b<c*c) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}