//
// Created by 原田 on 2022/06/13.
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

    int n;
    cin>>n;
    int nn = pow(2,n);
    vi a(nn);
    int max_l = 0;
    int max_l_index = -1;
    int max_r = 0;
    int max_r_index = -1;
    int div = nn / 2;
    for (int i = 0; i < nn; ++i) {
        cin>>a[i];
        if(i < div){
            if(max_l < a[i]){
                chmax(max_l,a[i]);
                max_l_index = i;
            }
        }else{
            if(max_r < a[i]){
                chmax(max_r,a[i]);
                max_r_index = i;
            }
        }
    }
    if(max_l > max_r){
        cout<<max_r_index + 1<<endl;
    }else{
        cout<<max_l_index + 1<<endl;
    }




    return 0;
}

