//23
//abc131_a_security
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ok = true;
    rep(i,3) if(s[i]==s[i+1])ok = false;
    if(ok) cout << "Good" << endl;
    else cout << "Bad" << endl;
    return 0;
}