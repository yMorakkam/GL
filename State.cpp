#include <iostream>
#include "State.h"

State::State(std::string name) {

}

State::~State() {

}

void State::print() const {
    std::cout << name << std::endl;
}

S0::S0(): State::State("S0"){

}


bool S0::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    switch (s.type){
        case LexicalAnalyser::symbolType::NUMBER :
            syntaxAnalyser.offset(s, new S3);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::OPEN :
            syntaxAnalyser.offset(s, new S2);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType ::EXPR :
            syntaxAnalyser.offset(s, new S1);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S0::~S0() {

}

S1::S1() : State("S1") {

}

S1::~S1() {

}

bool S1::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    LexicalAnalyser::Symbol val;
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
            syntaxAnalyser.offset(s, new S4);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::MULT :
            syntaxAnalyser.offset(s, new S5);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::EOF_CHAR :
            // TODO : make better
            val = syntaxAnalyser.popSymbol();
            std::cout << "EOF reached, value computed : " << val.data.number;

            return false;
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}


S2::S2() : State("S2") {

}

S2::~S2() {

}

bool S2::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    switch (s.type) {
        case LexicalAnalyser::symbolType::NUMBER :
            syntaxAnalyser.offset(s, new S3);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::OPEN :
            syntaxAnalyser.offset(s, new S2);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::EXPR :
            syntaxAnalyser.offset(s, new S6);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S3::S3() : State("S3") {

}

S3::~S3() {

}

bool S3::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    LexicalAnalyser::Symbol val;
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
        case LexicalAnalyser::symbolType::MULT :
        case LexicalAnalyser::symbolType::CLOSE :
        case LexicalAnalyser::symbolType::EOF_CHAR :
            val = syntaxAnalyser.popSymbol();
            val.type = LexicalAnalyser::symbolType::EXPR;
            syntaxAnalyser.reduce(1, val);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S4::S4() : State("S4") {

}

S4::~S4() {

}

bool S4::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    switch (s.type) {
        case LexicalAnalyser::symbolType::NUMBER :
            syntaxAnalyser.offset(s, new S3);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::OPEN :
            syntaxAnalyser.offset(s, new S2);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::EXPR :
            syntaxAnalyser.offset(s, new S7);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S5::S5() : State("S5") {

}

S5::~S5() {

}

bool S5::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    switch (s.type) {
        case LexicalAnalyser::symbolType::NUMBER :
            syntaxAnalyser.offset(s, new S3);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::OPEN :
            syntaxAnalyser.offset(s, new S2);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::EXPR :
            syntaxAnalyser.offset(s, new S8);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S6::S6() : State("S6") {

}

S6::~S6() {

}

bool S6::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
            syntaxAnalyser.offset(s, new S4);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::MULT :
            syntaxAnalyser.offset(s, new S5);
            syntaxAnalyser.moveCursor();
            break;
        case LexicalAnalyser::symbolType::CLOSE :
            syntaxAnalyser.offset(s, new S9);
            syntaxAnalyser.moveCursor();
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S7::S7() : State("S7") {

}

S7::~S7() {

}

bool S7::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    LexicalAnalyser::Symbol val1;
    LexicalAnalyser::Symbol val2;
    LexicalAnalyser::Symbol result;
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
        case LexicalAnalyser::symbolType::CLOSE :
        case LexicalAnalyser::symbolType::EOF_CHAR :
            val1 = syntaxAnalyser.popSymbol();
            syntaxAnalyser.popSymbol();
            val2 = syntaxAnalyser.popSymbol();
            result.type = LexicalAnalyser::symbolType::EXPR;
            result.data.number = val1.data.number + val2.data.number;
            syntaxAnalyser.reduce(3, result);
            break;
        case LexicalAnalyser::symbolType::MULT :
            syntaxAnalyser.offset(s, new S5);
            syntaxAnalyser.moveCursor();
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S8::S8() : State("S8") {

}

S8::~S8() {

}

bool S8::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    LexicalAnalyser::Symbol val1;
    LexicalAnalyser::Symbol val2;
    LexicalAnalyser::Symbol result;
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
        case LexicalAnalyser::symbolType::MULT :
        case LexicalAnalyser::symbolType::CLOSE :
        case LexicalAnalyser::symbolType::EOF_CHAR :
            val1 = syntaxAnalyser.popSymbol();
            syntaxAnalyser.popSymbol();
            val2 = syntaxAnalyser.popSymbol();
            result.type = LexicalAnalyser::symbolType::EXPR;
            result.data.number = val1.data.number * val2.data.number;
            syntaxAnalyser.reduce(3, result);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}

S9::S9() : State("S9") {

}

S9::~S9() {

}

bool S9::transition(SyntaxAnalyser &syntaxAnalyser, LexicalAnalyser::Symbol s) {
    LexicalAnalyser::Symbol val1;
    LexicalAnalyser::Symbol result;
    switch (s.type) {
        case LexicalAnalyser::symbolType::PLUS :
        case LexicalAnalyser::symbolType::MULT :
        case LexicalAnalyser::symbolType::CLOSE :
        case LexicalAnalyser::symbolType::EOF_CHAR :
            syntaxAnalyser.popSymbol();
            val1 = syntaxAnalyser.popSymbol();
            syntaxAnalyser.popSymbol();
            result.type = LexicalAnalyser::symbolType::EXPR;
            result.data.number = val1.data.number;
            syntaxAnalyser.reduce(3, result);
            break;
        default:
            syntaxAnalyser.syntaxError();
            return false;
            break;
    }

    return true;
}