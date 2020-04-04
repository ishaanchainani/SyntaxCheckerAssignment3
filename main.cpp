#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "./GenStack.h"

bool delimsMatch(string inputChars);

int main(int argc, char *argv[]) {
    // this is from: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    std::ifstream t(argv[1]);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    delimsMatch(str);
}

bool delimsMatch(string inputChars) {
    GenStack<char> stack;
    char open[] = {'(','{','['};
    char close[] = {')', '}', ']'};
    for (int i = 0; i < inputChars.length(); i++) {
        char c = inputChars[i];
        if (c==open[0] ||
            c==open[1] ||
            c==open[2]) {
        stack.Push(c);
        }
        for (int w = 0; w < 3; w++) {
            if (c==close[w]) {
                try {
                    if (stack.Pop() != open[w]) {
                        cout << "Error at pos " << i << endl;
                        return false;
                    }
                } catch (char const* msg) {
                    cout << "Error at pos " << i << endl;
                    return false;
                }
            }
        }
    }
    if (stack.Size()==0) { return true; }
    cout << "Unclosed delimiter: " << stack.Pop() << endl;
    return false;
}
