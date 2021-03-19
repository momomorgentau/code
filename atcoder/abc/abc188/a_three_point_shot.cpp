//ABC_188_A_Three-Point_Shot
//8
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int x, y;
    cin >> x >> y;
    if (x > y)swap(x, y);
    if (x + 3 > y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}