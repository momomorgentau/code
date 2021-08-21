//ABC_209_A
//Counting
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
    int a, b;
    cin >> a >> b;
    cout << max(0, b - a + 1) << endl;

    return 0;
}