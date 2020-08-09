//
// Created on 2019/12/15.
//

#include <bits/stdc++.h>
#include <numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int n;
    cin>>n;
    vector<int>line(n);
    string temp;
    cin>>temp;
    for (int i = 0; i < n; ++i) {
        if (temp[i] == 'B') line[i] = 1;
        else if(temp[i] =='W') line[i] =0;
    }
    int ans =0;
    vector<int>operation;
    auto sum =accumulate(all(line),0);
    if (sum % 2 == 1 && (n-sum) %2 == 1 ){
        cout<<-1<<endl;
        return 0;
    }
    while (!(sum == 0 || sum ==n)){
        if (sum % 2 == 1){
            //adjustB
            for (int i = 0; i < n-1; ++i) {
                if(line[i] == 0){
                    operation.push_back(i);
                    ans ++;
                    line[i] = (line[i] +1) % 2;
                    line[i+1]= (line[i+1] +1) % 2;
                }
            }
        }else if(sum % 2 == 0 ){
            //adjust
            for (int i = 0; i < n-1; ++i) {
                if(line[i] == 1){
                    operation.push_back(i);
                    ans ++;
                    line[i] = (line[i] +1) % 2;
                    line[i+1]= (line[i+1] +1) % 2;
                }
            }
        }
        sum =accumulate(all(line),0);
    }
    if (ans >= n*3){
        cout<<-1<<endl;
    }
    cout<<ans<<endl;
    for (int j : operation) {
        cout<<j+1<<" ";
    }
    cout<<endl;
}
