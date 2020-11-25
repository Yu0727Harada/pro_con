//
// Created on 2020/11/24.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;
    map<int,int>odd;
    map<int,int>even;
    for (int i = 0; i < n; ++i) {
        if(i % 2 == 0){
            int v;
            cin>>v;
            even[v]++;
        }else{
            int v;
            cin>>v;
            odd[v]++;
        }
    }
    int ans1 = 0;
    int even_max_ele = 0;
    int even_max_ele_cnt = 0;

    for(auto value : even){
        if(value.second > even_max_ele_cnt){
            even_max_ele = value.first;
            even_max_ele_cnt = value.second;
        }
    }
    ans1 += (n/2)-even_max_ele_cnt;

    int odd_max_ele = 0;
    int odd_max_ele_cnt = 0;

    for(auto value : odd){
        if(value.second > odd_max_ele_cnt && value.first != even_max_ele){
            odd_max_ele = value.first;
            odd_max_ele_cnt = value.second;
        }
    }
    ans1 += (n/2)-odd_max_ele_cnt;


    swap(even,odd);
    int ans2 = 0;
    even_max_ele = 0;
    even_max_ele_cnt = 0;

    for(auto value : even){
        if(value.second > even_max_ele_cnt){
            even_max_ele = value.first;
            even_max_ele_cnt = value.second;
        }
    }
    ans2 += (n/2)-even_max_ele_cnt;

    odd_max_ele = 0;
    odd_max_ele_cnt = 0;

    for(auto value : odd){
        if(value.second > odd_max_ele_cnt && value.first != even_max_ele){
            odd_max_ele = value.first;
            odd_max_ele_cnt = value.second;
        }
    }
    ans2 += (n/2)-odd_max_ele_cnt;


    cout<<min(ans1,ans2)<<endl;

    return 0;
}
