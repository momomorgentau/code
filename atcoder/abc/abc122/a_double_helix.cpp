//ABC_122_A_Double_Helix
//20
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    char b;
    cin >> b;
    if(b == 'A') cout << 'T' << endl;
    else if(b == 'T') cout << 'A' << endl;
    else if(b == 'C') cout << 'G' << endl;
    else cout << 'C' << endl;

    return 0;
}