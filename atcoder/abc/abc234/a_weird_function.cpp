//----------------------------
//ABC 234 A
//Weird Function
//7
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int t;
    cin >> t;
    auto f = [](int x)
    {
        return x * x + 2 * x + 3;
    };
    cout << f(f(f(t) + t) + f(f(t))) << endl;

    return 0;
}