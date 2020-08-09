//
// Created on 2020/01/13.
//

//
// Created on 2020/01/12.
//

#include <istream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

const int MAX = 510000;//nCkのn,kの取りうるMAX
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

    int n;
    int k;
    cin>>n>>k;
    vector<ll>A_array(n);
    for (int i = 0; i < n; ++i) {
        cin>>A_array[i];
    }
    sort(all(A_array));

    COM_initialize();
    ll sum_max = 0;
    for (int j = 0; j < n; ++j) {
        sum_max += COM(j,k-1)*A_array[j]%MOD;
    }

    ll sum_min = 0;
    reverse(all(A_array));
    for (int j = 0; j < n; ++j) {
        sum_min += COM(j,k-1)*A_array[j]%MOD;
    }

    ll ans;
    ans = sum_max  - sum_min;
    cout<<ans%MOD<<endl;
}
