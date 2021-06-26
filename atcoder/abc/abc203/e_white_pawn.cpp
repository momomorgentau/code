//ABC_203_E
//White_Pawn
//1750
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() 
{
    int n, m;
    cin >> n >> m;
    map<int,vector<int>> XY;
    rep(i, m)
    {
        int x, y; cin >> x >> y;
        XY[x].emplace_back(y);
    }
    set<int> ans;
    ans.insert(n);

    for (auto [ignore,XYi] : XY)
    {
        vector<int> add;
        vector<int> era;
        for (auto y : XYi)
        {
            if(ans.count(y-1) || ans.count(y+1))
            { 
                add.emplace_back(y);
            }
            era.emplace_back(y);
        }
        for (auto e : era) ans.erase(e);
        for (auto a : add) ans.insert(a);
    }
    cout << ans.size() << endl;
 
    return 0;
}

