//------------------------------
//ABC_216_B
//Same Name
//38
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
    int n;
    cin >> n;
    set<pair<string, string>> s;
    rep(i, n)
    {
        string s1, s2;
        cin >> s1 >> s2;
        s.insert(make_pair(s1, s2));
    }
    if (s.size() != n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}