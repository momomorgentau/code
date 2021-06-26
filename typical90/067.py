#066
#Base 8 to 9
#*2
n,k = map(int, input().split())
if n == 0:
  print(0)
  exit()

s = str(n)  
for _ in range(k):
  now = 0
  for c in s:
    now *= 8
    now += int(c)
  res = ""
  while now > 0:
    res += str(now % 9)
    now //= 9
  s = res[::-1].replace("8","5")

print(s)