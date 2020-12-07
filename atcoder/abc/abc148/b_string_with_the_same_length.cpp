//30
//abc148_b_string_with_the_same_length
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int n;
    string s,t;
    cin >> n >> s >> t;
    string ans;
    rep(i,n)
    {
        ans += s[i];
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}