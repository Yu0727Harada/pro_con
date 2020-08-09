#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

const int MAX = 1000010;//nCkのn,kの取りうるMAX
const int MOD = 1000000007;

long long fac[MAX],finv[MAX],inv[MAX];

//階乗のテーブルを作る
void COM_initialize(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2 ; i < MAX ; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD -inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

//二項係数計算,nCkのn,kを引数として渡す
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD)% MOD;
}

int main() {

   long long X;
   long long Y;
   cin>>X>>Y;
   if((X+Y)%3!=0){
       cout<<0<<endl;
       return 0;
   }

   long long ans;

   COM_initialize();
   ans = COM(((2*X-Y)/3)+((2*Y-X)/3),(2*X-Y)/3);
   cout<<ans<<endl;
}
