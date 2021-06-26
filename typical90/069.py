#069
#Colorful_Blocks_2
#*3
n,k = map(int, input().split())

mod = 10**9+7
ans = k

if n > 1:
  ans*=k-1
  ans *= pow(k-2,n-2,mod)
ans%=mod
print(ans)