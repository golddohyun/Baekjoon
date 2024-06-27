import sys
input = sys.stdin.readline

N = int(input())
mystack = list()
for _ in range(N) :
    ord_list = input().split()
    if ord_list[0] == 'push' :
        mystack.append(int(ord_list[1]))
    elif ord_list[0] == 'pop' :
        if not mystack :
            print(-1)
        else :
            last_elem = mystack.pop()
            print(last_elem)
    elif ord_list[0] == 'size' :
        print(len(mystack))
    elif ord_list[0] == 'empty' :
        print(1) if len(mystack) == 0 else print(0)
    elif ord_list[0] == 'top' :
        print(-1) if len(mystack) == 0 else print(mystack[-1])