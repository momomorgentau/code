//960
//abc163_d_sum_of_large_numbers
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1e9+7;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> s1(n+1);
    vector<ll> s2(n+1);
    s1[0] = 0;
    s2[0] = n;
    reps(i,1,n+1)
    {
        s1[i] = s1[i-1] + i; 
        s2[i] = s2[i-1] + n-i;
    }

    ll ans = 0;
    reps(i,k,n+2)
    {
        ans += s2[i-1] - s1[i-1] + 1;
        ans %= mod;

    }
    cout << ans << endl;
    
    return 0;
}