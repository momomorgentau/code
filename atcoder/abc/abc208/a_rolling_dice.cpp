//ABC_208_A
//Rolling Dice
//28
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a <= b && b <= 6 * a)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}