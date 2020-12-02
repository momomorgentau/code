//681
//arc108_b_abbreviate_fox

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;


//stack
void solve1() 
{
    int n;
    string s;
    cin >> n >> s;
    int fox = 0;


    int idx1 = -1;
    int idx2 = 0;

    vector<int> vs;
    int vs_cnt = -1;
    while (idx1 < n - 1)
    {
        idx1++;
        char c = s[idx1];


        if (c == 'f')
        {
            vs.emplace_back(1);
            vs_cnt++;
            continue;
        }
        else if (c == 'o')
        {
            if (vs_cnt != -1)
            {
                if (vs[vs_cnt] == 1)
                {

                    vs[vs_cnt]++;
                    continue;
                }
                else
                {
                    vs.clear();
                    vs_cnt = -1;
                }
            }
            else
            {
                vs.clear();
                vs_cnt = -1;
            }

        }
        else if (c == 'x')
        {
            if (vs_cnt != -1)
            {
                if (vs[vs_cnt] == 2)
                {
                    vs.pop_back();
                    fox++;
                    vs_cnt--;
                }
                else
                {
                    vs.clear();
                    vs_cnt = -1;
                }
            }
            else
            {
                vs.clear();
                vs_cnt = -1;
            }
        }
        else
        {
            vs.clear();
            vs_cnt = -1;
        }
    }
    int ans = n - fox * 3;
    cout << ans << endl;

}
//string
void solve2()
{
    int n;
    string s;
    cin >> n >> s;
    int fox = 0;
    string t;
    int lt = 0;

    while (!s.empty())
    {
        t += s[0];
        s.erase(0, 1);
        lt++;
        if (lt >= 3 && t.substr(lt - 3, 3) == "fox")
        {
            ++fox;
            t.erase(lt - 3, 3);
            lt -= 3;
        }
    }
    cout << n - fox * 3 << endl;
}
int main()
{
    solve1();
    //solve2();
    return 0;
}




