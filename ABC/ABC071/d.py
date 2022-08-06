n = int(input())
s1 = str(input())
s2 = str(input())

mod = 1000000007

i = 0
last = 0
ans = 1
# 0 init 1 parallel 2 vertical
while i < n:
    if s1[i] == s2[i]:
        if last == 0:
            ans = ans * 3 % mod
        elif last == 1:
            ans = ans * 1 % mod
        elif last == 2:
            ans = ans * 2 % mod
        last = 2
        i += 1
        continue
    elif i + 1 <= n - 1:
        if s1[i] == s1[i + 1]:
            if last == 0:
                ans = ans * 3 % mod
                ans = ans * 2 % mod
            elif last == 1:
                ans = ans * 3 % mod

            elif last == 2:
                ans = ans * 2 % mod
                ans = ans * 1 % mod
            last = 1
            i += 2

print(ans)
