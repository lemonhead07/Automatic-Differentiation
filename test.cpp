#include <iostream>
#include <vector>
#include "test.h"

using namespace std;


string a = "";
vector<string> terms;
vector<string> dydx;

int main() {
    getline(cin, a);
    terms = findterms(a);
    dydx = derive(terms);
    for( int i = 0; i < dydx.size(); i++){
        cout << dydx[i] << '\n';
    }
    return 0;
}




