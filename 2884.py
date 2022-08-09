H, M= map(int, input().split())
hour = (H -(M <45))%24
minute = (M+15)%60
print(hour, minute)