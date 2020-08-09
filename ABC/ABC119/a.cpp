//
// Created on 2020/07/14.
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
    cin>>s;
    int yyyy= 0;
    yyyy += int(s[0] -'0') * 1000;
    yyyy += int(s[1] - '0') * 100;
    yyyy += int(s[2] -'0') *10;
    yyyy += int(s[3] - '0');
    int mm =( int(s[5] - '0') *10)  + int(s[6] - '0');
    int dd = (int(s[8] - '0') *10) +int(s[9] -'0');
    if(yyyy < 2019){
        cout<<"Heisei"<<endl;
        return 0;
    }
    if(yyyy == 2019){
        if(mm < 4){
            cout<<"Heisei"<<endl;
            return 0;
        }
        if(mm == 4){
            if(dd <= 30){
                cout<<"Heisei"<<endl;
                return 0;
            }
        }
    }
    cout<<"TBD"<<endl;
    return 0;
}
