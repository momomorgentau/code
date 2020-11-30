//160
//abc162_c_sum_of_gcd_of_tuples_easy
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{   
    int n;
    cin >> n;
    int ans = 0;

    reps(i,1,n+1)reps(j,1,n+1)reps(k,1,n+1)
    {
        ans += gcd(gcd(i,j),k);
    }
    cout << ans << endl;
    return 0;
}  
