while True:
    lang = input().rstrip()
    if lang == '.' : break
    mystack = []
    flag = True
    for l in lang :
        if l in "([" :
            mystack.append(l)
        elif l in ")]" :
            if not mystack :
                flag = False
                break
            elif (l == ")" and mystack[-1] == "(") or (l == "]" and mystack[-1] == "[") :
                mystack.pop()
            else :
                mystack.append(l)
    if mystack or not flag :
        print("no")
    else :
        print("yes")