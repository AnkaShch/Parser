//
// Created by anka on 08.12.2019.
//

#include "LexicalAnalyzer.h"

bool LexicalAnalyzer::isBlank(char c) {
    return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}

void LexicalAnalyzer::nextChar() {
    curChar = getc(input);
    curPos++;
}
#include <iostream>
void LexicalAnalyzer::nextToken() {
    while (isBlank(curChar)) {
        nextChar();
    }
    switch (curChar) {
        case '(': {
            nextChar();
            curToken = LPAREN;
            break;
        }
        case ')': {
            nextChar();
            curToken = RPAREN;
            break;
        }
        case '!': {
            nextChar();
            curToken = NOT;
            break;
        }
        case '&': {
            nextChar();
            curToken = AND;
            break;
        }
        case '^': {
            nextChar();
            curToken = XOR;
            break;
        }
        case '|': {
            nextChar();
            curToken = OR;
            break;
        }
        case EOF: {
            curToken = END;
            break;
        }
        default: {
            if (!isalpha(curChar))
                throw runtime_error("Lexical error");
            var = curChar;
            nextChar();
            curToken = VAR;
            if (curChar != '(' && curChar != ')' && curChar != EOF && !isOperand(curChar) && !isblank(curChar))
                throw runtime_error("Lexical error");
        }
    }
}

Token LexicalAnalyzer::getCurToken() {
    return curToken;
}

int LexicalAnalyzer::getCurPos() {
    return curPos;
}

char LexicalAnalyzer::getVar() {
    return var;
}

void LexicalAnalyzer::runLex() {
    nextChar();
    nextToken();
}

void LexicalAnalyzer::setInput(string s) {
    curPos = 0;
    input = fopen(s.c_str(), "r");
}

LexicalAnalyzer::~LexicalAnalyzer() {
    fclose(input);
}

bool LexicalAnalyzer::isOperand(char c) {
    return c == '^' || c == '&' || c == '|' || c == '!';
}

