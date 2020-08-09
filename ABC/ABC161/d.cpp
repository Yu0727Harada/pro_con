//
// Created on 2020/04/04.
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

    int cnt = 9;
    int k;
    cin>>k;

    if(k<=9){
        cout<<k<<endl;
        return 0;
    }

    queue<string>q;

    for (int l = 1; l <= 9; ++l) {
        q.push(to_string(l));
    }

    string temp;

    while(!(q.empty())) {


        temp = q.front();
        q.pop();

        for (int i = max((temp[temp.size()-1] - '0') - 1, 0); i <= min((temp[temp.size()-1] - '0') + 1, 9); ++i) {
            string temp2 =  temp + to_string(i);

            cnt++;

            if (cnt == k) {

                cout << temp2 << endl;
                return 0;
            }
            q.push(temp2);

        }
    }



}
