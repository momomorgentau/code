#diff 2367
#tleします。

n, m, l = map(int,input().split())
mod = 1000000007
p = [[0 for i in range(n+1)] for j in range(n+1)]

#パスカルの三角形
p[0][0] = 1
for i in range(n):
  for j in range(i+1):
    p[i+1][j] = (p[i+1][j] + p[i][j]) % mod
    p[i+1][j+1] = (p[i+1][j+1] + p[i][j]) % mod

#種類数の計算
path = [0,1,1]
cycle = [0,0,1]
for i in range(3,l+1):
  path.append((path[i-1] * i) % mod)
  cycle.append(path[i-1])

def f(n,m,l):
  dp = [[0 for i in range(m+1)] for j in range(n+1)]
  dp[0][0] = 1
  for i in range(n):
    for j in range(m+1):
      for k in range(1,l+1):
        ni = k + i
        nj = k + j - 1
        if ni > n:
          break
        if nj > m:
          break
        add = (path[k] * p[n-i-1][k-1]) % mod
        add = (add * dp[i][j]) % mod
        dp[ni][nj] += add
        dp[ni][nj] =(dp[ni][nj]) % mod
        #dp[ni][nj] += (((dp[i][j] * path[k]) % mod) * p[n - i - 1][k - 1]) % mod
        #dp[ni][nj] %= mod
      for k in range(2,l+1):
        ni = k + i
        nj = k + j
        if ni > n:
          break
        if nj > m:
          break
        add = (cycle[k] * p[n-i-1][k-1]) % mod
        add = (add * dp[i][j]) % mod
        dp[ni][nj] += add
        dp[ni][nj] =(dp[ni][nj]) % mod
        #dp[ni][nj] += (((dp[i][j] * cycle[k]) % mod) * p[n - i - 1][k - 1]) % mod
        #dp[ni][nj] %= mod
  return dp[n][m]

ans = (f(n,m,l)-f(n,m,l-1)) % mod
print(int(ans)) 