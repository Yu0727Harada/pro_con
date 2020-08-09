//
// Created on 2020/02/09.
//

//#include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

const int MAX = 200;//nCkのn,kの取りうるMAX
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
    int ans = 0;
    string n;
    int k;
    cin>>n;
    cin>>k;
    vector<int>s(n.size());
    transform(n.begin(), n.end(), s.begin(), [](char ch) { return ch - '0';});
    COM_initialize();

    cout<<COM(100,3)<<endl;
    
    ans += COM(n.size()-1,k-1)*pow(9,k-1);
    ans += (s[0]-1)*COM(n.size()-1,k)*pow(9,k);
    int i = 1;
    while (i<=k){
        if  (s[i] == 0){
            i --;
        }else break;
    }
    if (i == k){
        int temp = 1;
        for (int j = 1+k; j < s.size(); ++j) {
            temp *= s[j];
        }
        ans += temp;
        cout<<ans<<endl;
    }
    ans += s[i]*COM(n.size()-i,k-i)*pow(9,k-i);


    cout<<ans<<endl;
}
