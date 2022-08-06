d, n = input().rstrip().split()


ans = int(n)

if int(n) == 100:
    ans = 101

for i in range(int(d)):
    ans *= 100

print(ans)
