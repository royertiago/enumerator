/* parse.h
 * Funções que auxiliam no parsing do arquivo de entrada.
 */
#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include "production.h"

namespace Parse {
    /* Retorna um vetor de produções resultantes da interpretação
     * de uma linha como
     *  S -> aSBc | aBc
     * O vetor de caracteres passado será modificado.
     * 
     * Caso a linha passada seja da forma
     *  S
     * Isto é, representa apenas o símbolo terminal,
     * uma lista vazia de produções será retornada.*/
    std::vector<Production> productionList( char * );

} // namespace Parse

#endif // PARSE_H
