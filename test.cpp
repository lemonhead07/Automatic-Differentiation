#include <iostream>
#include <vector>
#include "test.h"

using namespace std;


string a = "";
vector<string> terms;
vector<string> dydx;

int main() {
    getline(cin, a);
    cout<< "gotline";

    terms = findterms(a);
    cout << "getterms";
    dydx = derive(terms);
    cout << "derived";
    for( int i = 0; i < dydx.size(); i++){
        cout << dydx[i] << '\n';
    }

    return 0;
}




