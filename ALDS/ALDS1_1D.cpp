//
// Created on 2019/12/07.
//

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
//using ll = long long;
using namespace std;
//using gragh = vector<vector<int>>;
const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N;
    cin>>N;
    int ans = -1 * INF;
    int min_v = 0;
    int max_v = 0;
    int now;
    int next;
    cin>>now;
    min_v = now;
    for (int i = 0; i < N-1; ++i) {
        cin>>next;

        if (next - now >= 0){
            max_v = next;
            ans = max(max_v-min_v,ans);
        }else if (next - now <0){
            if (next < min_v){
                min_v = next;
                max_v = next;
            }
            ans = max(next-now,ans);
        }
        now = next;

    }
    cout<<ans<<endl;

}
