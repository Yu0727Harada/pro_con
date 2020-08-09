//
// Created on 2020/04/05.
//

//#include <bits/stdc++.h>
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

    int n;
    cin>>n;
    vector<int>R;
    vector<int>B;
    for (int i = 0; i < n; ++i) {
        string cl;
        int x;
        cin>>x>>cl;
        if(cl =="R"){
            R.push_back(x);
        }else{
            B.push_back(x);
        }
    }
    sort(all(R));

    sort(all(B));


    for (int j = 0; j < R.size(); ++j) {
        cout<<R[j]<<endl;
    }
    for (int k = 0; k < B.size(); ++k) {
        cout<<B[k]<<endl;
    }
    return 0;
}
