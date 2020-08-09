//
// Created on 2020/05/17.
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
    string s;
    cin>>s;
    if(s[s.size()-1] == '3'){
        cout<<"bon"<<endl;
        return 0;
    }

    vector<char>pon;
    pon = {'0', '1','6','8'};
    vector<char>hon;
    hon = {'2','4','5','7','9'};

    for (int i = 0; i < pon.size(); ++i) {
        if(s[s.size()-1] == pon[i]){
            cout<<"pon"<<endl;
            return 0;
        }
    }
    for (int i = 0; i < hon.size(); ++i) {
        if(s[s.size()-1] == hon[i]){
            cout<<"hon"<<endl;
            return 0;
        }
    }
    return 0;
    
}

