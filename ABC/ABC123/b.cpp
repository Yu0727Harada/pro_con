//
// Created on 2020/07/13.
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
//#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    vector<int>menu(5);
    for (int j = 0; j < 5; ++j) {
        cin>>menu[j];
    }
    vector<int>array = {0,1, 2, 3,4};
    int ans = INF;
    do {
        int time = 0;
        for (int i = 0; i < array.size(); i++) {
            while(true){
                if(time % 10 == 0){
                    time += menu[array[i]];
                    break;
                }else{
                        time ++;
                }
            }
        }
        ans = min(ans,time);
    }while (std::next_permutation(array.begin(), array.end()));

    cout<<ans<<endl;


    return 0;
}
