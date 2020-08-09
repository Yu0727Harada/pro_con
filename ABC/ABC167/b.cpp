//
// Created on 2020/05/10.
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
    int ans = 0;
    int a,b,c;
    int k;
    cin>>a>>b>>c>>k;
    while(k>0 && a >0){
        ans += min(a,k);
        if(a>k){a=a-k;k=0;}
        else {k=k-a;a=0;}
    }
    k=k-b;
    while(k>0 && c>0){
        ans -= min(c,k);
        if(c>k){c=c-k;k=0;}
        else {k=k-c;c=0;}
    }

    cout<<ans<<endl;
    return 0;
}
