#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    cout << (5 ^ 7) << endl;
    int a = 0;
    cout << (7 & (1 << 0) )<< endl;
    cout << (7 & (1 << 1) )<< endl;
    cout << (7 & (1 << 2)) << endl;

    cout << ((3 << 0) )<< endl;
    cout << ((3 << 1) )<< endl;
    cout << ((3 << 2)) << endl;

    return 0;
}
