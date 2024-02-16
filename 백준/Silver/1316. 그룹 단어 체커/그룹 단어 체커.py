groupchecker = 0
for i in range(int(input())):
    word = input()
    err = 0
    for idx in range(len(word)-1) :
        if word[idx] != word[idx+1] : 
            new_word = word[idx+1:]
            if new_word.count(word[idx]) > 0 : err +=1    
    if err == 0 : groupchecker +=1
print(groupchecker)