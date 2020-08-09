//
// Created on 2020/04/10.
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

bool is_prime(int n){
    if (n == 1) return false;
    for (int i =2 ; pow(i,2) <= n ; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}
//素数判定

int main() {
    int x;
    cin>>x;
    int i;
    for (i = 0; i < INF; ++i) {
        if(is_prime(x+i)) break;
    }

    cout<<x+i<<endl;
}
