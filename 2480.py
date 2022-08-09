## 주사위 세개
## 1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다...

a,b,c = sorted(map(int, input().split()))

if a==b and b==c:
    print(10000+a*1000)
elif a==b or b==c:
    print(1000+b*100)
else:
    print(c*100)