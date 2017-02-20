#ifndef TP_COMP_STATE_H
#define TP_COMP_STATE_H

#include <string>
#include "LexicalAnalyser.h"
#include "SyntaxAnalyser.h"

class SyntaxAnalyser;

/**
 * Base class representing a State in our SyntaxAnalyser.
 */
class State {
public:
    State (std::string name);
    virtual ~State();
    void print() const;
    virtual bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol) = 0;
protected:
    std::string name;
};


class S0: public State{
public:
    S0 ();
    ~S0();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S1: public State{
public:
    S1 ();
    ~S1();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S2: public State{
public:
    S2 ();
    ~S2();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S3: public State{
public:
    S3 ();
    ~S3();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S4: public State{
public:
    S4 ();
    ~S4();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S5: public State{
public:
    S5 ();
    ~S5();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S6: public State{
public:
    S6 ();
    ~S6();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S7: public State{
public:
    S7 ();
    ~S7();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S8: public State{
public:
    S8 ();
    ~S8();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

class S9: public State{
public:
    S9 ();
    ~S9();
    bool transition(SyntaxAnalyser & syntaxAnalyser, LexicalAnalyser::Symbol);
};

#endif