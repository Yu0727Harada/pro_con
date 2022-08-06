from sys import  stdin
mod = 1000000007

a, b, c = [int(x) for x in stdin.readline().rstrip().split()]

ans = a * b % mod
ans *= c
ans %= mod
print(ans)
