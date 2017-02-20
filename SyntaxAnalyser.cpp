#include <iostream>
#include "SyntaxAnalyser.h"
#include "State.h"

SyntaxAnalyser::SyntaxAnalyser() {
    lex = new LexicalAnalyser();
}

void SyntaxAnalyser::offset(LexicalAnalyser::Symbol s, State *e) {
    symbols.push(s);
    states.push(e);
}

void SyntaxAnalyser::reduce(int n, LexicalAnalyser::Symbol s) {
    for (int i = 0; i < n; i++){
        delete(states.top());
        states.pop();
    }
    states.top()->transition(*this, s);


}

LexicalAnalyser::Symbol SyntaxAnalyser::readSymbol() {
    return lex->readSymbol(false);
}

void SyntaxAnalyser::moveCursor() {
    lex->readSymbol(true);
}

void SyntaxAnalyser::syntaxError() {
    std::cerr << "Syntax Error !" << std::endl;
}

LexicalAnalyser::Symbol SyntaxAnalyser::popSymbol() {
    LexicalAnalyser::Symbol s = symbols.top();
    symbols.pop();
    return s;
}

void SyntaxAnalyser::analyse(std::string theString) {
    lex->openString(theString);

    states.push(new S0);

    while(true) {
        LexicalAnalyser::Symbol s = readSymbol();

        State * state = states.top();

        if (!state->transition(*this, s))
        {
            break;
        }

    }
}