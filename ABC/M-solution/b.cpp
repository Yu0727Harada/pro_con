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
    int a,b,c;
    cin>>a>>b>>c;
    int k;
    cin>>k;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k - i; ++j) {
                int l = k - (i + j);
                int red,green,blue;
                red = a;
                green = b;
                blue = c;
                red = red * (int)pow(2,i);
                green = green * (int)pow(2,j);
                blue = blue * (int)pow(2,l);
                if(green > red && blue > green){
                    cout<<"Yes"<<endl;
                    return 0;

                }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
