n,q = list(map(int,input().split()))
s = []
for _ in range(q):
    row = list(map(int,input().split()))
    for i in range(len(row)):
        row[i] -= 1
    s.append(row)

graph = []
for _ in range(n):
    row = []
    for __ in range(n):
        row.append(False)
    graph.append(row)

for query in s:
    if query[0] == 0:
        graph[query[1]][query[2]] = True
    elif query[0] == 1:
        for i in range(n):
            if graph[i][query[1]]:
                graph[query[1]][i] = True
    else:
        addlist = []
        for i in range(n):
            if graph[query[1]][i]:
                for j in range(n):
                    if graph[i][j] and query[1] != j:
                        addlist.append(j)
        for i in addlist:
            graph[query[1]][i] = True
for i in range(n):
    for j in range(n):
        if graph[i][j]:
            graph[i][j] = 'Y'
        else:
            graph[i][j] = 'N'

for i in range(n):
    graph[i] = ''.join(graph[i])
    print(graph[i])
