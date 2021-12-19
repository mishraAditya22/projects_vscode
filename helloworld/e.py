def check (l,le):
    f = 0
    for i in range(2,le):
        if l[i].isupper():
            f+=1
            break
    if f==0:
        return 1
    else:
        return 0

for i in range(int(input())):
    l = str(input())
    if l[0]== '<' and l[1]=='/':
        if l[len[l]-1]=='>':
            ans  = check(l,len(l))
            if ans ==1:
                print("success")
    else:
        print("Error")