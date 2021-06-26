//ABC_206_B
//Saving
//14
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
    int sum = 0;
    rep(i, n)
    {
        sum += i + 1;
        if (sum >= n)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}