//
// Created on 2020/06/06.
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
    string s;
    string t;
    cin>>s>>t;

    bool same = true;
    for (int i = 0; i < 3; ++i) {
        if(s[i] != t[i]){
            same = false;
        }
        if((s[i] - 'A') % 32 != (t[i] - 'A') % 32){
            cout<<"different"<<endl;
            return 0;
        }
    }
    if(same){
        cout<<"same"<<endl;
    }else{
        cout<<"case-insensitive"<<endl;
    }

    return 0;
}