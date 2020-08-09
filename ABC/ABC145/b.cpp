#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N;
    string S;
    cin>>N;
    cin>>S;

    if (N%2==1){
        cout<<"No"<<endl;
        return 0;
    }

    for (int i = 0; i < int(N/2); ++i) {
        if(S[i]!=S[int(N/2)+i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;


}
