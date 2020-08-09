#include <bits/stdc++.h>
using namespace std;
int main() {

    int price,monthly_payment,loanterm;
    cin>>price>>monthly_payment>>loanterm;

    double x =0;
    double y =100;
    double risi = abs(x-y)/2+min(x,y);

    while ((1e-9 < (y-x)) && (1e-9<(y-x)/y)) {
        double account = price;
        for (int i = 0; i < loanterm; ++i) {
            account = account-monthly_payment + account*(risi/12/100);
        }

        if (account == 0) {
            break;
        } else if (account > 0) {
            y=risi;
            risi = abs(risi-x)/2+min(risi,x);

        } else {
            x=risi;
            risi = abs(y-risi)/ 2+min(y,risi);

        }
    }
    cout << risi << endl;
    return 0;

}