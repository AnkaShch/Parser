//
// Created by anka on 14.12.2019.
//

#include "Parser.h"
#include <iostream>

Tree Parser::S1() {
    switch (lex.getCurToken()) {
        case NOT:
        case VAR:
        case LPAREN:
            return Tree("S1", {A1(), S2()});
        case END:
            return Tree("S1", {Tree("eps")});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::S2() {
    switch (lex.getCurToken()) {
        case OR:
            lex.nextToken();
            return Tree("S2", {Tree("|"), A1(), S2()});
        case END:
        case RPAREN:
            return Tree("S2", {Tree("eps")});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::A1() {
    switch (lex.getCurToken()) {
        case NOT:
        case VAR:
        case LPAREN:
            return Tree("A1", {B1(), A2()});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::A2() {
    switch (lex.getCurToken()) {
        case XOR:
            lex.nextToken();
            return Tree("A2", {Tree("^"), B1(), A2()});
        case END:
        case RPAREN:
        case OR:
            return Tree("A2", {Tree("eps")});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::B1() {
    switch (lex.getCurToken()) {
        case NOT:
        case VAR:
        case LPAREN:
            return Tree("B1", {C(), B2()});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::B2() {
    switch (lex.getCurToken()) {
        case AND:
            lex.nextToken();
            return Tree("B2", {Tree("&"), C(), B2()});
        case END:
        case RPAREN:
        case OR:
        case XOR:
            return Tree("B2", {Tree("eps")});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::C() {
    switch (lex.getCurToken()) {
        case NOT:
            lex.nextToken();
            return Tree("C", {Tree("!"), C()});
        case VAR:
        case LPAREN:
            return Tree("C", {D()});
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::D() {
    switch (lex.getCurToken()) {
        case VAR :
        {
            char var = lex.getVar();
            lex.nextToken();
            return Tree("D", {Tree({var})});
        }
        case LPAREN:
        {
            lex.nextToken();
            Tree nextS = S1();
            if (lex.getCurToken() != RPAREN) {
                throw runtime_error("Syntax error");
            }
            lex.nextToken();
            return Tree("D", {Tree("("), nextS, Tree(")")});
        }
        default:
            throw runtime_error("Syntax error");
    }
}

Tree Parser::parser(string s) {
    lex.setInput(s);
    lex.runLex();
    Tree t = S1();
    if (lex.getCurToken() == END) {
        return t;
    }
    throw runtime_error("Syntax error");
}


