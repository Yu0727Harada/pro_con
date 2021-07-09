//
// Created by 原田 on 2021/06/29.
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

int solve(int &ans ,int m,vi &dic){
    if(m % 2 == 0){
        ans ++;
        m /= 2;
        if(dic[m] != -1){
            ans += dic[m];
            return ans;
        }
        solve(ans,m,dic);
    }else{
        return ans;
    }
}


int main() {

    int n;
    cin>>n;
    vi dic(110,-1);
    dic[0] = 0;
    dic[1] = 0;

    int f_ans = 0;
    int f_index = 1;
    for (int i = 2; i <= n; ++i) {
        int ans = 0;
        dic[i] = solve(ans,i,dic);
        if(dic[i] > f_ans){
            chmax(f_ans,dic[i]);
            f_index = i;
        }
     }
    cout<<f_index<<endl;

    return 0;
}
