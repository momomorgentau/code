//13
//abc147_a_blackjack
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;
    int s = a1+a2+a3;

    if(s <= 21) cout << "win" << endl;
    else cout << "bust" << endl;

    return 0;
}