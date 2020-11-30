//8
//abc164_a_sheep_and_wolves

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{
    int s,w;
    cin >> s >> w; 
    string ans = s <= w ? "unsafe" : "safe";
    cout << ans << endl;
    return 0;
}

