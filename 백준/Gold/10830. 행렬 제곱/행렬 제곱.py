import sys
input = sys.stdin.readline

# 지수곱 분할정복 함수
def matrix_pow(matrix, m):
    if m == 1 :
        return matrix
    tmp = matrix_pow(matrix, m//2)
    if m % 2 == 0 :
        return matmul(tmp, tmp)
    else :
        return matmul(matmul(tmp, tmp), matrix)    
    
    
# 나머지 구하는 함수
def remainder(A):
    n = len(A)
    for i in range(n):
        for j in range(n):
            A[i][j] %= 1000

# 행렬 곱셈 함수
def matmul(mata, matb):
    col = len(mata)
    tmp = [[0] * col for _ in range(col)]
    for i in range(col):
        for j in range(col):
            for k in range(col):
                tmp[i][j] += mata[i][k] * matb[k][j]
    remainder(tmp)
    return tmp         


N, M = map(int, input().split())
original_mat = [list(map(int, input().split())) for _ in range(N)]
result = matrix_pow(original_mat, M)

remainder(result)
for rows in result:
    for idx in rows :
        print(idx%1000, end=' ')
    print()