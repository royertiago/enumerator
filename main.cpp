/* main.cpp */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "production.h"
#include "parse.h"
#include "grammar.h"

using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<Production> prod;
    vector<Production> alce;
    
    char buf[128];
    cin.getline( buf, sizeof(buf) );
    string terminals( buf );

    do {
        cin.getline( buf, sizeof(buf) );
        alce = Parse::productionList( buf );
        prod.insert( prod.end(), alce.begin(), alce.end() );
    } while( !alce.empty() );

    string initial( buf );

    Grammar g( terminals, initial, prod );

    int q;
    cin >> q;
    vector<string> sentences = g.generate( q );

    sort( sentences.begin(), sentences.end(),
            [](string i, string j) { return i.length() < j.length(); } );
    for( string& str: sentences ) //Imprimir em ordem crescente de tamanho
        cout << str << endl;
    return 0;
}
