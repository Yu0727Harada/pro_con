//
// Created by 原田 on 2021/07/12.
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
    int n,l,k;
    cin>>n>>l>>k;

    vi a(n+1);
    cin>>a[0];
    int last = a[0];
    for (int i = 1; i < n; ++i) {
        int temp;
        cin>>temp;
        a[i] = temp - last;
        last = temp;
    }
    a[n] = l - last;

    int ok = 0;
    int ng = l;
    while(ng - ok > 1){
        int mid = (ok + ng)/2;

        int pierce = 0;
        int yokan_length = 0;
        for (int i = 0; i < n + 1 && pierce < k + 1; ++i) {
            yokan_length += a[i];
            if(yokan_length >= mid){
                pierce++;
                yokan_length = 0;
            }
        }
        if(yokan_length != 0){
            pierce ++;
            if(yokan_length < mid){
                ng = mid;
                continue;
            }
        }

        if(pierce == k + 1){
            ok = mid;
        }else{
            ng = mid;
        }




    }
    cout<<ok<<endl;
    return 0;
}
