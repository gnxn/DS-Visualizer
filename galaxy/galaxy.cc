#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

//Skip the grammar part of the input.
void skipLine(istream& in) {
    string s;
    getline(in, s);
}

void skipGrammar(istream& in) {
    int i, numTerm, numNonTerm, numRules;

    // read the number of terminals and move to the next line
    in >> numTerm;
    skipLine(in);

    // skip the lines containing the terminals
    for (i = 0; i < numTerm; i++) {
        skipLine(in);
    }

    // read the number of non-terminals and move to the next line
    in >> numNonTerm;
    skipLine(in);

    // skip the lines containing the non-terminals
    for (i = 0; i < numNonTerm; i++) {
        skipLine(in);
    }

    // skip the line containing the start symbol
    skipLine(in);

    // read the number of rules and move to the next line
    in >> numRules;
    skipLine(in);

    // skip the lines containing the production rules
    for (i = 0; i < numRules; i++) {
        skipLine(in);
    }
}

string trim(const string& str) {
    size_t begin = str.find_first_not_of(" \t\n");
    if (begin == string::npos) return "";

    size_t end = str.find_last_not_of(" \t\n");

    return str.substr(begin, end - begin + 1);
}

// Prints the derivation with whitespace trimmed.
void printDerivation(istream& in, ostream& out) {
    string line;

    while (getline(in, line)) {
        out << trim(line) << '\n';
    }
}

int calcID(string &s) {
    int sum = 0;
    int idPos = s.find("id");
    int curPos = 0;
    bool hasMinus = false;
    if (idPos == string::npos) {
        return 0;
    }

    while (curPos < s.length()) {
        if (s[curPos] == 'i') {
            if (hasMinus) {
                sum -= 42;
            }
            else {
                sum += 42;
            }
			curPos++;
        }
        else if (s[curPos] == '-') {
            hasMinus = true;
        }
        else if (s[curPos] == '(') {
            int rpPos = s.find_last_of(")");
            string newExp = s.substr(curPos + 1, rpPos - curPos - 1);
            if (hasMinus) {
                sum -= calcID(newExp);
            }
            else {
                sum += calcID(newExp);
            }
            curPos = rpPos;
        }
        curPos++;
    }
    return sum;
}

void toExpr(istream& in, ostream& out) {
    string expr;
    string result;
    while (getline(in, expr)) {
        expr = trim(expr);
        if (result == "") {
            result = "expr";
        }
        else {
            int fwSpace = expr.find(" ");
            string needReplace = expr.substr(0, fwSpace);
            int sPosInR = result.find(needReplace);
            result.replace(sPosInR, fwSpace, expr.substr(fwSpace + 1));
        }
    }
    out << calcID(result) << '\n';
}
// Reads a .cfg file and prints the left-canonical
// derivation without leading or trailing spaces.
int main() {
    skipGrammar(std::cin);
    //printDerivation(std::cin, std::cout);
    toExpr(std::cin, std::cout);
}