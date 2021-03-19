//ABC088_C_Takahashi's_Information
//477
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    vector<vector<int>> c(3,vector<int> (3));
    rep(i,3)rep(j,3) cin >> c[i][j];
    bool ok = true;

    if(c[0][0]-c[0][1] != c[1][0]-c[1][1] 
    || c[2][0]-c[2][1] != c[1][0]-c[1][1]) ok = false;
    if(c[0][1]-c[0][2] != c[1][1]-c[1][2] 
    || c[2][1]-c[2][2] != c[1][1]-c[1][2]) ok = false;

    if(c[0][0]-c[1][0] != c[0][1]-c[1][1] 
    || c[0][2]-c[1][2] != c[0][1]-c[1][1]) ok = false;
    if(c[1][0]-c[2][0] != c[1][1]-c[2][1] 
    || c[1][2]-c[2][2] != c[1][1]-c[2][1]) ok = false;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
} 
/*
a1b1 a1b2 a1b3
a2b1 a2b2 a2b3
a3b1 a3b2 a3b3
*/