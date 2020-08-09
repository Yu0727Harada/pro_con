//
// Created on 2020/06/21.
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
    ll n;
    cin>>n;
    vector<int>kisu;
    while(!(n <= 26)){
        int a = n % 26;
        kisu.push_back(a);
        n /= 26;
        if(a == 0) n --;
    }
    if(n != 0) kisu.push_back(n);
    for (int i = kisu.size() - 1; i >= 0; --i) {
        char o = kisu[i] + 'a' - 1;
        if(kisu[i] == 0){
            o = 'z';
        }
        cout<<o;
    }
    cout<<endl;

    return 0;
}
