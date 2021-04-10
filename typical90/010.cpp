//010
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n,q;
    cin >> n;
    vector<int> A(n+1),B(n+1);
    rep(i,n)
    {
        int c,p;
        cin >> c >> p;
        --c;
        A[i+1] += A[i];
        B[i+1] += B[i];

        if(c == 0) A[i+1] += p;
        else B[i+1] += p;
    }
    cin >> q;
    vector<int> L(q),R(q);
    rep(i,q) cin >> L[i] >> R[i];
    
    rep(i,q)
    {
        int l = L[i],r = R[i];
        cout << A[r]-A[l-1] << " " << B[r] - B[l-1] << endl;
    }
    return 0;
}