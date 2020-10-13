n = int(input())
brickwall = [[i for i in input().split()[:n]] for j in range(n)]



trow = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        trow[j][i] = brickwall[i][j]
        


def decompose_cube(brickwall,trow,n):
    if n == 0:
        return 0
    for i in range(n):

    	brickwall[i].sort()

    	trow[i].sort()

    rowss = 0
    colss = 0
    for i in range(n):

    	cmelt = brickwall[i].count('C')

    	rowss = max(rowss,cmelt)

    	cmelt = trow[i].count('C')

    	colss = max(colss,cmelt)

    return min(rowss,colss)
ans = decompose_cube(brickwall,trow,n)
print(ans, end = '')