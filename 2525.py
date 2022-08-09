H, M= map(int, input().split())
M += int(input())
Hour = (H + (M//60))%24
Minute = M%60
print(Hour, Minute)