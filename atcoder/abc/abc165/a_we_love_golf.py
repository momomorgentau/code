#ABC_165_A_We_Love_Golf
#25
k = int(input())
a, b = list(map(int,input().split()))
ok = False
for i in range(a,b+1):
    if i % k == 0:
        ok = True
if ok:
    print("OK")
else:
    print("NG")