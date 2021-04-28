//024
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n,k;
    cin >> n >> k;
    int d = 0;
    vector<int> A(n),B(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(i,n)
    {
        d += abs(A[i]-B[i]);
    }
    if(d<=k && ((d&1) == (k&1)))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}