//107
//abc157_b_bingo
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int A[3][3];

int main()
{
    int n;
    rep(i,3)rep(j,3) cin >> A[i][j];
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    rep(p,n)rep(i,3)rep(j,3)
    {
        if(b[p] == A[i][j]) A[i][j] = -1;
    }
    
    bool ok = false;
    rep(i,3)
    {
        if(A[i][0] + A[i][1] + A[i][2] == -3) ok = true;
        if(A[0][i] + A[1][i] + A[2][i] == -3) ok = true;
    }
    if(A[0][0] + A[1][1] + A[2][2] == -3) ok = true;
    if(A[0][2] + A[1][1] + A[2][0] == -3) ok = true;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 
