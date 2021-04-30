//ABC_197_A
//Rotate
//6
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string ans;
    ans += s[1];
    ans += s[2];
    ans += s[0];
    cout << ans << endl;

    return 0;
}