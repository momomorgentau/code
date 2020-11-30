//10
//abc161_a_abc_swap
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    swap(x,y);
    swap(x,z);
    cout << x << " " << y << " " << z << endl;
    return 0;
}
