//81
//abc_164_c_gacha
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;

using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    rep(i,n)
    {
        string t;
        cin >> t;
        s.emplace(t);
    }
    int ans = s.size();
    cout << ans << endl;
    return 0;
}
