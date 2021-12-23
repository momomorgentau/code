//------------------------------
//ABC_216_A
//Signed Difficulty
//17
//------------------------------
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
    int idx = 1;
    if (s[2] == '.')idx = 2;
    string x = s.substr(0, idx);
    int y = s[idx + 1] - '0';
    if (y <= 2)cout << x << '-' << endl;
    else if (y <= 6)cout << x << endl;
    else cout << x << '+' << endl;
    return 0;
}