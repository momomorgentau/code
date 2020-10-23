//5%
//project_eular_5_Smallest multiple
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{
    int n = 20;
    multiset<int> p;

    reps(i, 2, n+1)
    {
        int ti = i;
        int m = 2;
        multiset<int> tp;
        while (ti > 1)
        {
            if (ti % m != 0)
            {
                ++m;
                continue;
            }
            ti /= m;
            tp.emplace(m);
        }
        while (!tp.empty())
        {
            int a = *tp.begin();
            int cp = p.count(a);
            int ctp = tp.count(a);
            int d = ctp - cp;

            
            if (d > 0) 
            {
                rep(j, d) 
                {
                    p.emplace(a);
                }
            }

            tp.erase(a);
        }
    }
    ll ans = 1;
    for (auto a : p) ans *= a;
    cout << ans << endl;
    return 0;
}
