//176
//abc166_c_peaks
#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<int> > route(n);
    rep(i,m)
    {
        int a,b;cin>> a >> b;
        --a; --b;
        route[a].emplace_back(b);
        route[b].emplace_back(a);
    }
    

    int ans = 0;
    rep(i,n)
    {
        int th = h[i];
        bool ok = true;
        for(auto sh : route[i])
        {
            if(th <= h[sh])
            {
                ok = false;
                break;
            }

        }
        if(ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}   