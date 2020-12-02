//1418
//abc184_e_third_avenue
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n:++i)
using namespace std;
using Tiic = tuple<int,int,char>;
using Pii = pair<int,int>;


char g[2005][2005];
int dist[2005][2005];

int c2i(char c) return c - 'a';

 int main()
 {
     int h,w;
     cin >> h >> w;
     vector<vector<Pii>> warp(26);
     int sx,sy,gx,gy;
     rep(i,h)rep(j,w)
     {
         char c;
         cin >> c;
         if(c == 'S') 
         {
             sx = j,sy = i;
             g[i][j] = '.';
             continue;
         }
         else if(c == 'G')
         {
            gx = j,gy = i;
            g[i][j] = '.';
            continue;
         }
         if(c != '.' && c != '#') warp[c2i(c)].emplaceback(i,j);
         g[i][j] = c;
     }

     vector<int> dx(0,0,-1,1);
     vector<int> dy(1,-1,0,0);

     deque<Tiic> dq;
     dq.emplace_front(sx,sy,'.');
     while(!dq.empty())
     {
         Tiic t = dq[0];
         int tx,ty;
         char c;
         tie(ty,tx,c) = t;
         dq.pop_front();
         rep(i,4)
         {
             int nx = tx+dx[i];
             int ny = ty+dy[i];
             if(nx < 0 || w-1 < nx) continue;
             if(ny < 0 || h-1 < ny) continue;
             if(g[ny][nx] == '#') continue;
             if(dist[ty][tx]+1 >= dist[ny][nx]) continue;
             dist[ny][nx]=dist[ty][tx] +1;
             dq.emplace_back(ny,nx,g[ny][nx]);
         }
         if(c != '.' && c != '#')
         {
             auto pv = warp[c2i(c)];
             for(auto p: pv)
             {
                 int nx = p.second;
                 int ny = p.first;
                 if(dist[ty][tx]+1 >= dist[ny][nx]) continue;
                 dist[ny][nx] = dist[ty][tx] +1;
                 dq.emplace_front(ny,nx,g[ny][nx]);

             }
         }
     }

     cout << dist[gy][gx] << endl;
     return 0;
 }
