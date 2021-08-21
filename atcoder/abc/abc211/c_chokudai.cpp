//ABC_211_C
//Chokudai
//559

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int mod = 1e9 + 7;
int main()
{
    string s;
    cin >> s;
    map<char, ll> dp;
    dp['X'] = 1;
    for (auto const& c : s)
    {
        if (c == 'c') dp['c'] = (dp['c'] + dp['X']) % mod;
        else if (c == 'h') dp['h'] = (dp['h'] + dp['c']) % mod;
        else if (c == 'o') dp['o'] = (dp['o'] + dp['h']) % mod;
        else if (c == 'k') dp['k'] = (dp['k'] + dp['o']) % mod;
        else if (c == 'u') dp['u'] = (dp['u'] + dp['k']) % mod;
        else if (c == 'd') dp['d'] = (dp['d'] + dp['u']) % mod;
        else if (c == 'a') dp['a'] = (dp['a'] + dp['d']) % mod;
        else if (c == 'i') dp['i'] = (dp['i'] + dp['a']) % mod;
    }
    cout << dp['i'] << endl;
    return 0;
}