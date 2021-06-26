//ABC_203_B
//AtCoder_Condominium
//12
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() 
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    reps(i, 1, n + 1)reps(j, 1, k+1)
    {
        ans += 100 * i + j;
    }
    cout << ans << endl;
    return 0;
}

