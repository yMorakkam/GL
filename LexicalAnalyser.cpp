#include <cstdlib>
#include "LexicalAnalyser.h"

LexicalAnalyser::LexicalAnalyser() : cursor(0) {

}

void LexicalAnalyser::openString(std::string theString) {
    analysedString = theString;
    cursor = 0;
}

LexicalAnalyser::Symbol LexicalAnalyser::readSymbol(bool updateCursor) {

    const char * c_string = analysedString.c_str();

    // We use the c string format in order to have a '\0' character a the end.
    char readChar = c_string[cursor];

    Symbol next;

    // We set the symbol to be UNKNOWN, so if no case are matched, the type is still set
    next.type = symbolType::UNKNOWN;
    next.data.number = 0;

    switch (readChar) {
        case '\0' : {
            next.type = symbolType::EOF_CHAR;
            break;
        }
        case ' ':
        case '\t':
        case '\n': {
            cursor++;
            return readSymbol(updateCursor);
            break;
        }
        case '+' : {
            next.type = symbolType::PLUS;
            if (updateCursor) { cursor++; }
            break;
        }
        case '*': {
            next.type = symbolType::MULT;
            if (updateCursor) { cursor++; }
            break;
        }
        case '(': {
            next.type = symbolType::OPEN;
            if (updateCursor) { cursor++; }
            break;
        }
        case ')': {
            next.type = symbolType::CLOSE;
            if (updateCursor) { cursor++; }
            break;
        }
        default: { // Case for number handling
            if (readChar >= '0' && readChar <= '9') {
                std::string numberString = "";
                int tempCursor = cursor;

                while (c_string[tempCursor] >= '0' && c_string[tempCursor] <= '9') {
                    numberString += c_string[tempCursor];
                    tempCursor++;
                }

                int number = atoi(numberString.c_str());

                next.type = symbolType::NUMBER;
                next.data.number = number;

                if (updateCursor) {
                    cursor = tempCursor;
                }

            }
            break;
        }

    }


    return next;
}