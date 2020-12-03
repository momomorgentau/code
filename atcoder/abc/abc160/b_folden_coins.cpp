//diff19
//abc_160_b_folden_coins
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{
    int x;
    cin >> x;
    int ans = 0;
    ans += x / 500 * 1000;
    x %= 500;
    ans += x / 5 * 5;
    cout << ans << endl;  
    return 0;
} 
