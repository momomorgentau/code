//ABC_206_A
//Mixi-Buying
//5

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    n = 108 * n;
    n /= 100;
    if (n < 206) cout << "Yay!" << endl;
    else if (n > 206) cout << ":(" << endl;
    else cout << "so-so" << endl;

    return 0;
}