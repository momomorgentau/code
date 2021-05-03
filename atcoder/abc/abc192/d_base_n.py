x = int(input())
m = int(input())

if x <= 9:
  if x <= m:
    print(1)
  else:
    print(0)
  exit()

def n2d(n):
  tx = x
  res = 0
  w = 1
  while(tx > 0):
    res += (tx % 10) * w
    tx = tx // 10
    w *= n
  return res


X = [x for x in list(str(x))]
 
md = int(max(X))
ac = md
wa = 2*10**18

while(wa-ac > 1):
  wj = (wa+ac)//2
  v = n2d(wj)
  if v <= m:
    ac = wj
  else:
    wa = wj

print(ac-md)  