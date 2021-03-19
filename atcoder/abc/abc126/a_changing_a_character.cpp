//ABC_126_A_Changing_a_Character
//??
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    --k;
    s[k] = tolower(s[k]);
    cout << s << endl;
    return 0;
}