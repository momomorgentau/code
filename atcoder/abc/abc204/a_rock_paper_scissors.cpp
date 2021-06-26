//ABC_204_A
//Rock-paper-scissors
//7
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() 
{
    int x, y;
    cin >> x >> y;
    if (x == y) cout << x << endl;
    else cout << 3 - x - y << endl;
    return 0;
}

