//
// Created by anka on 14.12.2019.
//

#ifndef PARSER_TREE_H
#define PARSER_TREE_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Tree {
    string symb;
    vector<Tree> children;
public:
    explicit Tree(string x);
    Tree(string x, vector<Tree> childs);

    void print(int n = 0);
};


#endif //PARSER_TREE_H
