//12
//abc132_a_fifty_fifty
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2])
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}

