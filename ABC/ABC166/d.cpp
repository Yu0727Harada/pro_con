//
// Created on 2020/05/03.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    ll ans_a;
    ll ans_b;
    int x;
    cin>>x;
    vector<ll>pow_list;

    for (ll i = 0; pow(i,5) < LINF ; ++i) {
        pow_list.push_back(pow(i,5));
    }

    bool find = false;
    for (int j = 0; j < pow_list.size(); ++j) {
        if(find) break;
        ll add = x+pow_list[j];
        ll sub = x-pow_list[j];
        for (int i = 0; i < pow_list.size(); ++i) {
            if(pow_list[i] == add){
                ans_a = i;
                ans_b = j;
                find = true;
                break;
            }else if(pow_list[i] == sub){
                ans_a = i;
                ans_b = -j;
                find = true;
                break;
            }else if(-pow_list[i] == add){
                ans_a = -i;
                ans_b = j;
                find = true;
                break;
            }else if(-pow_list[i] == sub){
                ans_a = -i;
                ans_b = -j;
                find = true;
                break;
            }
        }
    }

    cout<<ans_a<<" "<<ans_b<<endl;
    return 0;
}