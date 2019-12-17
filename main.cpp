#include <iostream>
#include "src/Parser.h"
#include "src/Test.h"
int main() {
    Parser pars;
    Tree t = pars.parser("input.txt");
    //t.print(0);

    Test::test(17);
    return 0;
}
