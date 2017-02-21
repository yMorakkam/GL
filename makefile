EXE : main.cpp LexicalAnalyser.o State.o SyntaxAnalyser.o
	g++ -o EXE main.cpp LexicalAnalyser.o State.o SyntaxAnalyser.o

LexicalAnalyser.o : LexicalAnalyser.cpp LexicalAnalyser.h
	g++ -c LexicalAnalyser.cpp

State.o : State.cpp State.h
	g++ -c State.cpp

SyntaxAnalyser.o : SyntaxAnalyser.cpp SyntaxAnalyser.h
	g++ -c SyntaxAnalyser.cpp

clean :
	rm EXE LexicalAnalyser.o State.o SyntaxAnalyser.o