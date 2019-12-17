//
// Created by anka on 08.12.2019.
//

#ifndef PARSER_LEXICALANALYZER_H
#define PARSER_LEXICALANALYZER_H

#include <iostream>
#include <exception>

using namespace std;

enum Token {
    LPAREN, RPAREN, NOT, AND, XOR, OR, END, VAR
};

class LexicalAnalyzer {
public:
    void setInput(string s);
    void runLex();
    void nextToken();
    Token getCurToken();
    int getCurPos();
    char getVar();
    ~LexicalAnalyzer();



private:
    char curChar{0};
    int curPos{0};
    char var{0};
    Token curToken;
    FILE *input;

    static bool isBlank(char c);
    bool isOperand(char c);
    void nextChar();

};


#endif //PARSER_LEXICALANALYZER_H
