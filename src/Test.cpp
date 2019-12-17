//
// Created by anka on 17.12.2019.
//

#include "Test.h"

int Test::test(int numbOfTests) {
    for (int i = 1; i <= numbOfTests; ++i) {
        string testName = "../Tests/test" + to_string(i);
        cout << "test " << i << ": ";
        try {
            Parser pars;
            Tree t = pars.parser(testName);
            cout << "OK!" << endl;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
