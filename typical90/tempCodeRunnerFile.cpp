//025
//*7
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

ll n,b;
string ns;
int sz;
ll ans = 0;

bool judge(string s)
{
    s = to_string(stoll(s));
    ll fs = 1;
    for(auto c:s) fs*= (ll)(c-'0');
    ll t = fs + b;
    if(t > n) return false;
    string ts = to_string(t);
    sort(ts.begin(),ts.end());
    return (ts == s);
}
void dfs(string s, int num)
{ 
    if(s.size() == sz)
    {
        if (judge(s)) ++ans;
        return;
    }
    for(int i = num;i<10;++i)
    {
        string tmp = s;
        tmp += (i + '0');
        dfs(tmp,i);
    }
    return;
}
int main()
{
    cin >> ns >> b;
    n = stoll(ns);
    sz = ns.size();
    dfs("",0);
    cout << ans << endl;
    return 0;
}