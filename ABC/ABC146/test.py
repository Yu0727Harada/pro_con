N = int(input())
S = list(input())
x = ""
ans =list()
for x in S:
    #temp = (chr(ord(x)-ord("A")+1+N))
    if ord(x)-ord("A")+1+N > ord("Z"):
        ans.append(ord(x)-ord("A")+1+N)
