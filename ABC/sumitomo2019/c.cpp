#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
using gragh = vector<vector<int>>;

int main() {
    int X;
    cin>>X;
    int x;
    x = X;
    int hundred;
    int count;
    hundred = X/100;
    count = hundred;
    for (int i = 5; i > 0 ; --i) {
        while (x - (hundred * 100) >= i){
            if(count < 1){
                cout<<0<<endl;
                return 0;
            }else{
                count -= 1;
                x -= i;
            }
        }
    }
    cout<<1<<endl;
    return 0;

}
