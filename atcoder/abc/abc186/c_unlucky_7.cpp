//ABC_186_C_Unlucky_7
//131
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    reps(i, 1, n + 1)
    {
        int tnt = i;
        bool ok = true;
        while (tnt > 0)
        {
            int d = tnt % 10;
            if (d == 7) ok = false;
            tnt /= 10;
        }
        if (!ok) continue;

        int tne = i;
        
        while (tne > 0)
        {
            int d = tne % 8;
            if (d == 7) ok = false;
            tne /= 8;
        }
        

        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}