#ifndef TP_COMP_ALANYSESYNTAXIQUE_H
#define TP_COMP_ALANYSESYNTAXIQUE_H


#include <string.h>
#include <fstream>

class LexicalAnalyser {
public:

    /**
     * Contains all the possibilities for the symbols
     */
    enum symbolType{
        UNKNOWN = -1,   // The Symbol was not recognised
        EOF_CHAR,       // End Of File character
        PLUS,           // Plus operator
        MULT,           // Multiplication operator
        OPEN,           // Open parenthesis
        CLOSE,          // Closed parenthesis
        EXPR,           // Result of a Reduction in the Syntax Analyser, cannot be read from the lexical analysier
        NUMBER          // An integer
    };

    /**
     * We use an union here so we can have a sort of Polymorphism on the Symbol struct without the added complexity
     * of ussing classes with inheritance. This approach was used to gain time and maybe wouldn't fit a more complex
     * language (with variables for example)
     */
    union symbolData {
        int number;     // If the symbol need to hold numerical data
        char character; // Not used anymore
    };

    /**
     * Represents a symbol : a piece of data read by the lexical analyser.
     * Far more lightweight than a Class implementaion with inheritance.
     */
    struct Symbol {
        symbolType type;    // Holds the type of the Symbol.
        symbolData data;    // Holds additional data for the symbol (if numerical value for example
    };

    /**
     * Default constructor, creates a new LexicalAnalyser
     * @return
     */
    LexicalAnalyser();

    /**
     * Loads a string in the LexicalAnalyser so it can be analysed.
     */
    void openString(std::string);

    /**
     * Read and returns the symbol under the cursor in the opened string. The cursor position is not updated if
     * updateCursor is set to false.
     * @param updateCursor
     * @return The read symbol
     */
    Symbol readSymbol(bool updateCursor = false);

private:

    std::string analysedString;

    int cursor;
};


#endif