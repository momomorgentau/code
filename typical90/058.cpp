//058
//Original_Calculator
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 1e5;

int main() 
{
    int n;
    ll k;
    cin >> n >> k;
    ll ans = 0;
    int s = 0, t = mod;
    vector<int> used(mod+5,-1);
    vector<int> num(mod+5,-1);
    rep(i, k)
    {
        
        if (used[n] != -1)
        {
            s = used[n];
            t = i;
            break;
        }
        used[n] = i;
        num[i] = n;

        int tmp = n;
        while (tmp > 0)
        {
            n += (tmp % 10);
            tmp /= 10;
        }
        n %= mod;
    }
    if (s == 0 && t == mod)
    {
        cout << n << endl;
    }
    else
    {
        k = (k - s) % (t - s);
        cout << num[k+s] << endl;
       
    }


 
    return 0;
}

