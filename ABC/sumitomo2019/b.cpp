#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
using gragh = vector<vector<int>>;

int main() {
    int N;
    cin>>N;
    double X;

    int x = 1;
    int y = 50000 * 1.08;

    while (y - x > 1){
        int temp = (x+y)/2;
        if ((int)(temp * 1.08) > N){
            y = temp;
            continue;
        }else if ((int)(temp * 1.08) < N){
            x = temp;
            continue;
        }else if ( (int)(temp * 1.08) ==N ){
            cout<<temp<<endl;

            return 0;
        }
    }

    if ((int)(x*1.08) == N){
        cout<<x<<endl;
        return 0;
    }else if ((int)(y*1.08) == N){
        cout<<y<<endl;
        return 0;
    }

    cout<<":("<<endl;

}
