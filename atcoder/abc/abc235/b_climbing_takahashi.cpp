//----------------------------
//ABC 235 B
//Climbing Takahashi
//20
//----------------------------
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
    int ans = 0;
    rep(i, n)
    {
        int h; cin >> h;
        if (h > ans)
        {
            ans = h;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}