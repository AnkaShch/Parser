//
// Created by anka on 14.12.2019.
//

#include "Tree.h"

Tree::Tree(string x) {
    symb = x;
}

Tree::Tree(string x, vector<Tree> childs) {
    symb = x; children = childs;
}

void Tree::print(int n) {
    for (auto e : this->children) {
        for (int i = 0; i < n - 1; ++i) {
            cout << ".   ";
        }
        cout << "∟——";
        cout <<this->symb << endl;
        e.print(n + 1);
    }
}
