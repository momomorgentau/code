//10
//abc_157_a_duplex_printing
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int ans = n/2;
    if(n&1) ++ans;
    cout << ans << endl;
    return 0;
} 
