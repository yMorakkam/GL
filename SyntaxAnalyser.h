#ifndef TP_COMP_SYNTAXANALYSER_H
#define TP_COMP_SYNTAXANALYSER_H


#include <stack>
#include "LexicalAnalyser.h"
#include "State.h"

class State;

class SyntaxAnalyser {
public:
    SyntaxAnalyser();

    /**
     * Push the given symbols and states on the stack
     * @param s
     * @param e
     */
    void offset(LexicalAnalyser::Symbol s, State *e);

    /**
     * Performs a reduction with n steps, and then analyse the given symbol
     * @param n
     * @param s
     */
    void reduce(int n, LexicalAnalyser::Symbol s);

    /**
     * Perform a syntax analyse on the given string.
     * @param theString
     */
    void analyse(std::string theString);

    /**
     * Returns the symbol at the current cursor position in the lexical analyser
     * @return
     */
    LexicalAnalyser::Symbol readSymbol();

    /**
     * Move the cursor in the lexical analyser by one step
     */
    void moveCursor();

    /**
     * Pop and returns the symbol at the top of the symbol stack.
     * @return
     */
    LexicalAnalyser::Symbol popSymbol();

    /**
     * Prints the default message for a syntax error.
     */
    void syntaxError();
private:
    std::stack<State*> states;
    std::stack<LexicalAnalyser::Symbol> symbols;

    LexicalAnalyser * lex;
};


#endif //TP_COMP_SYNTAXANALYSER_H