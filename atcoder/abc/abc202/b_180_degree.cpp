//ABC_202_B
//180°
//16
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    for (auto c : s)
    {
        if (c == '6') cout << '9';
        else if (c == '9')cout << '6';
        else cout << c;
    }
    cout << endl;
    return 0;
}