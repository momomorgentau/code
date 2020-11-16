//645
//abc166d_i hate factorization

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
int main()
{
    int x; cin >> x;
    int ans_a,ans_b;
    for(int i= -1000;i<10000;++i)
    {
        ll a = pow((ll)i,5);
        for(int j=-1000;j<1000;++j)
        {
            ll b= pow((ll)j,5);
            if(a-b == x)
            {
                ans_a = i;
                ans_b = j;
                break;
            }

        }
    }
    cout << ans_a << " " << ans_b << endl;


    return 0;
}

/*
a5-b5
= (a-b)(a4+a3b+a2b2+ab3+b4)
*/