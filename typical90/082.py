#082
#Counting Numbers
#*3
l,r = map(int, input().split())
mod = int(10**9)+7
ans = 0
for i in range(19):
  t = pow(10,i)
  if r < t:
    break
  if t*10 < l:
    continue
  tl = max(l, t);
  tr = min(r, t*10-1);
  ans += ((tr+1)*tr//2 - (tl-1)*tl // 2) * (i+1);
  ans %= mod

print(ans)
  