//
// Created on 2020/07/25.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int x;
    cin>>x;
    if(x < 600){
        cout<<8<<endl;
        return  0;
    }
    if(x < 800){
        cout<<7<<endl;
        return 0;
    }
    if(x < 1000){
        cout<<6<<endl;
        return 0;
    }
    if(x < 1200){
        cout<<5<<endl;
        return 0;
    }
    if(x < 1400){
        cout<<4<<endl;
        return 0;
    }
    if(x < 1600){
        cout<<3<<endl;
        return 0;
    }
    if(x < 1800){
        cout<<2<<endl;
        return 0;
    }
    if(x < 2000){
        cout<<1<<endl;
    }
    return 0;
}
