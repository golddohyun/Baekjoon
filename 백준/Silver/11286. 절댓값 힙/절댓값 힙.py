import sys, heapq
input = sys.stdin.readline

n = int(input())
hq = []
 
for _ in range(n):
    inputValue = int(input())
    if not inputValue:
        try:
            print(heapq.heappop(hq)[1])
        except:
            print(0)
    else:
        heapq.heappush(hq, (abs(inputValue), inputValue))