//ARC_121_A
//2nd_Greatest_Distance
//459
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int,int,int>> xy,yx;

    rep(i, n)
    {
        int x, y; cin >> x >> y;
        xy.emplace_back(x, y, i);
       
    }
    sort(xy.begin(), xy.end());
    set<tuple<int,int,int>> s;
    rep(i, 3)
    {
        s.insert(xy[i]);
        s.insert(xy[xy.size() - i - 1]);
    }
    sort(xy.begin(), xy.end(), [](tuple<int,int,int>& a, tuple<int,int,int>& b)
        {return get<1>(a) < get<1>(b);});
    rep(i, 3)
    {
        s.insert(xy[i]);
        s.insert(xy[xy.size() - i - 1]);
    }
    vector<tuple<int,int,int>> t;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        t.emplace_back(*it);
    }


    vector<int> ans;
    rep(i, t.size())rep(j, t.size())
    {
        if (i < j) continue;
        int x1, y1,x2,y2;
        tie(x1, y1,ignore) = t[i];
        tie(x2, y2,ignore) = t[j];
        int now = max(abs(x1-x2),abs(y1-y2));
        ans.emplace_back(now);
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[1] << endl;
    return 0;
}