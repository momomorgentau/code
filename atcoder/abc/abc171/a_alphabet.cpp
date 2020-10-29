//0
//abc171_a_alphabet
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    char a;
    cin >> a;
    char ans;
    if (isupper(a)) ans = 'A';
    else ans = 'a';
    cout << ans << endl;

    return 0;
}
