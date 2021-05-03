//ABC_196_B_Round_Down
//39
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    for(auto c:s)
    {
        if(c =='.') break;
        else cout << c;
    }
    cout << endl;
    return 0;
}
