//
// Created by 原田 on 2022/02/21.
//


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
//#include <atcoder/all>


#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int a,b;
    cin>>a>>b;
    int c,d;
    cin>>c>>d;

    vi n(1010,0);

    for (int i = 2; i < 1010; ++i) {
        if(n[i] == 0){
            n[i] = -1;
            int now = i * 2;
            for(int j = 3;now < 1010;j++){
                n[now] = 1;
                now = j * i;
            }
        }
    }
    vi sum(1010,0);
    sum[1] = 0;
    for (int i = 2; i < 1010; ++i) {
        if(n[i] == -1)sum[i] = 1;
        sum[i] = sum[i - 1] + sum[i];
    }

    bool ok = false;
    for (int i = a; i <= b; ++i) {
         if(sum[i + d] - sum[i + c - 1] == 0){
             ok = true;
         }
    }
    if(ok){
        cout<<"Takahashi"<<endl;
    }else{
        cout<<"Aoki"<<endl;
    }



    return 0;
}
