//ABC_192_A_Star
//7
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    int x;
    cin >> x;
    int ans = 100 - x % 100;
    cout << ans << endl;
    
    return 0;
}


