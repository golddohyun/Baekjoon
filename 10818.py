## 최소 최대
## N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

n = int(input())
arr = map(int,input().split())

arr_lst = list(arr)
print(min(arr_lst), max(arr_lst))