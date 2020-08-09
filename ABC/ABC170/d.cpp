//
// Created on 2020/06/14.
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
    vector<int>A(n);
    vector<int>list(1000005,0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        A[i] = a;
        list[a] ++;
        if(list[a] > 1) continue;
        for (int j = a + a; j < list.size(); j = j + a) {
            list[j] ++;
        }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        if(list[A[j]] == 1){
            ans ++;
        }
    }

    cout<<ans<<endl;
    return 0;
}

/*vectorは一次元なら10^6くらいの長さを持つことができる
自分自身しかないというのはlistに保持した値が1の時
 同じ値が２つ以上ある場合はlistの値を2以上になる


 長さNの数列Aが与えられます。

次の性質を満たす整数i(1≤i≤N)の数を答えてください。i≠jである任意の整数j(1≤j≤N)についてAiはAjで割り切れない



 */
