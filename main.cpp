/* main.cpp */

#include <string>
#include <vector>
#include <iostream>
#include "production.h"
#include "parse.h"

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<Production> p;
    
    char buf[128];
    cin.getline( buf, sizeof(buf) );
    string terminals( buf );
    cout << buf << endl;

    do {
        cin.getline( buf, sizeof(buf) );
        p = Parse::productionList( buf );

        for( Production& prod : p )
            cout << prod << endl;
        cout << endl;
    } while( !p.empty() );

    string initial( buf );
    cout << initial << endl;

    int q;
    cin >> q;
    cout << q << endl;
    return 0;
}
