//
// Created on 2020/07/11.
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
#include <cmath>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

bool is_integer( double x ){
    return std::floor(x)==x;
}
int main() {
    int n;
    cin>>n;
    vector<int>ans(n+10,0);

//    for (int i = 1; i <= n; ++i) {
//        int ans = 0;
//        for (int j = 1; j <=i ; ++j) {
//            for (int k = 1; k <= i; ++k) {
//                double l = ((-1) * (j+k) + sqrt((j +k)*(j+k) - 4 * (j*k + k * k + j *j - i)))/2;
//                if(is_integer(l)){
//                    if(l >= 1){
//                        ans ++;
//                    }
//                }
//
//            }
//        }
    for (int i = 1; i * i <= n ; ++i) {
        for (int j = 1; j * j <= n; ++j) {
            for (int k = 1; k * k <= n; ++k) {
                if(i*i+j*j+k*k+i*k+j*k+i*j > n)break;
                ans[i*i+j*j+k*k+i*k+j*k+i*j] += 1;
            }
        }
    }

    for (int l = 1; l <= n; ++l) {
        cout<<ans[l]<<endl;
    }

    return 0;
}
