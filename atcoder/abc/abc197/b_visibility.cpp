//ABC_197_B
//Visibility
//96
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h,w,x,y;
    cin >> h>>w>>x>>y;
    --x,--y;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = 1;
    for(int i = x+1; i<=h-1 && s[i][y] != '#';++i) ++ans;
    for(int i = x-1; 0<=i && s[i][y] != '#';--i) ++ans;
    for(int i = y+1; i<=w-1 && s[x][i] != '#';++i) ++ans;
    for(int i = y-1; 0<=i && s[x][i] != '#';--i) ++ans;
    cout << ans << endl;
    return 0;
}