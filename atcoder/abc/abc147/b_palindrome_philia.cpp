//44
//abc147_b_palindrome-philia
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int l = s.size();
    int ans = 0;
    rep(i,l/2)
    {
        if(s[i] != s[l-1-i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}