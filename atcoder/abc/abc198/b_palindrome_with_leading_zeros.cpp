//ABC_198_B
//Palindrome_with_leading_zeros
//58
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string n;
    cin >> n;
    reverse(n.begin(),n.end());
    bool ok = false;
    rep(i,15)
    {
        bool tok = true;
        rep(j,n.size())
        {
            if(n[j] != n[n.size()-1-j]) tok = false;
        }
        if(tok) ok = true;
        n += '0'; 
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}