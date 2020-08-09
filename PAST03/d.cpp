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
    int n;
    cin>>n;
    vector<string>s(5);

    vector<string>sample = {
            {".###..#..###.###.#.#.###.###.###.###.###."},
            {".#.#.##....#...#.#.#.#...#.....#.#.#.#.#."},
            {".#.#..#..###.###.###.###.###...#.###.###."},
            {".#.#..#..#.....#...#...#.#.#...#.#.#...#."},
            {".###.###.###.###...#.###.###...#.###.###."}
    };

    for (int i = 0; i < 5; ++i) {
        cin>>s[i];
    }
    string ans = "";
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < 10; ++i) {
            bool ok = true;
            for (int k = 0; k < 5; ++k) {
                if(s[k].substr(j * 4,4) != sample[k].substr(i * 4,4)){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans += to_string(i);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
