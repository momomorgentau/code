//----------------------------
//ABC 232 A
//QQ Solver
//9
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    string s;
    cin >> s;
    cout << (s[0] - '0') * (s[2] - '0') << endl;
    return 0;
}