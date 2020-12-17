//75
//abc136_b_uneven_numbers
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d{ 1,10,100,1000,10000,100000 };
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i < d[1]) ++ans;
        else if (i < d[2]) continue;
        else if (i < d[3]) ++ans;
        else if (i < d[4]) continue;
        else if (i < d[5]) ++ans;
    }
    cout << ans << endl;
    return 0;
}

