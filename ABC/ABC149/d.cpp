//
// Created on 2020/04/06.
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


int main() {
    ll ans = 0;
    int n,k;
    ll r,s,p;
    string t;
    cin>>n>>k;
    cin>>s>>p>>r;
    map<char,ll>point;
    point['p'] = p;
    point['r'] = r;
    point['s'] = s;
    cin>>t;

    for (int i = 0; i < k; ++i) {
        int j;
        for (j = 0; i+j+k < n && i+j<n; j += k) {
            int cnt = 1;

            while(t[i+j] == t[i+j+k]){
                j += k;
                cnt ++;
                if(i+j+k >= n){
                    break;
                }
            }
            ans += ((cnt+1)/2)*point[t[i+j]];
        }
        if(i+j <n){
            if(i+j-k >= 0){
                if(t[i+j-k]!=t[i+j]){
                    ans +=point[t[i+j]];
                }
            }else{
                ans +=point[t[i+j]];
            }
        }


    }

    cout<<ans<<endl;
}

//https://atcoder.jp/contests/abc149/tasks/abc149_d
//modkで分ける。連続で同じ手は出せないので、コンピュータ川で同じ手が続いたら続いた数/2の切り上げ点もらえる。続かなかったら常に足すことができる。
//反省:範囲外参照。しつこいくらいに場合わけしよう。終了コードが139でも範囲外参照エラーだぞ