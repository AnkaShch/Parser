//
// Created by anka on 14.12.2019.
//

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H


#include "LexicalAnalyzer.h"
#include "Tree.h"

class Parser {
public:
    Tree parser(string s);

private:
    LexicalAnalyzer lex;

    Tree S1();
    Tree S2();
    Tree A1();
    Tree A2();
    Tree B1();
    Tree B2();
    Tree C();
    Tree D();
};


#endif //PARSER_PARSER_H
