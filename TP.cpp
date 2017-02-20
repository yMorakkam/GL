#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

typedef enum{PLUS,MULT,OPEN,CLOSE,INTEGER,END,ERROR,EXPR} monEnum;

class Automate;

class Symbole 
{
protected:
	int ident;
public:
	Symbole(int id) : ident(id) {}
	virtual ~Symbole() {}
	void print();
	operator int() const {return ident;}
};


class 	Expr : public Symbole {
protected:
		int value; //value of the number if Expr is a number
	public:
		Expr(): Symbole(EXPR){};
		Expr(int id, int value): Symbole(id), value(value){};
		virtual ~Expr(){}
};

	class Etat{

	public: 
		Etat(string name): name(name){}
		virtual ~Etat() {}
		void print() const;
		virtual bool transition(Automate & automate, Symbole * s)=0;
	protected:
		string name;
	};

	class E0 : public Etat{
	public:
		E0() : Etat("E0") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E0() {}
	};

	class E1 : public Etat{
	public:
		E1() : Etat("E1") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E1() {}
	};

	class E2 : public Etat{
	public:
		E2() : Etat("E2") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E2() {}
	};

	class E3 : public Etat{
	public:
		E3() : Etat("E3") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E3() {}
	};

	class E4 : public Etat{
	public:
		E4() : Etat("E4") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E4() {}
	};

	class E5 : public Etat{
	public:
		E5() : Etat("E5") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E5() {}
	};

	class E6 : public Etat{
	public:
		E6() : Etat("E6") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E6() {}
	};

	class E7 : public Etat{
	public:
		E7() : Etat("E7") {}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E7() {}
	};

	class E8 : public Etat {
	public:
		E8() : Etat("E8"){}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E8() {}
	};

	class E9 : public Etat {
	public:
		E9() : Etat("E9"){}
		bool transition(Automate & automate, Symbole * s);
		virtual ~E9() {}
	};

	class Automate{
	private:
		stack<Etat * > * statestack;
		stack<Symbole * > * symbolstack;
	public:

		Automate() {
			symbolstack = new std::stack<Symbole * >();
			statestack = new std::stack<Etat * >();
		}

		void decalage(Symbole *s, Etat *e) {
			symbolstack->push(s);
			statestack->push(e);
		}
		void reduction(int n, Symbole * s) {
			for (int i=0; i<n; i++)
			{
				delete(statestack->top());
				statestack->pop();
			}
		}

		virtual ~Automate() {
			delete(symbolstack);
			delete(statestack);
		}
	};	

	bool E0::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case INTEGER:
			automate.decalage(s, new E3);
			break;
			case OPEN:
			automate.decalage(s, new E2);
			break;
			case EXPR:
			automate.decalage(s, new E1);
			break;
		}
		return false;		
	}

	bool E1::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.decalage(s, new E4);
			break;
			case MULT:
			automate.decalage(s, new E5);
			break;
			case END:
			automate.decalage(s, new E1);
			return true;
			break;
		}

		return false;

	}

	bool E2::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case INTEGER:
			automate.decalage(s, new E3);
			break;
			case OPEN:
			automate.decalage(s, new E2);
			break;
			case EXPR:
			automate.decalage(s, new E6);
			break;
		}
		return false;		
	}

	bool E3::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.reduction(1,s);
			break;
			case OPEN:
			automate.reduction(1,s);
			break;
			case EXPR:
			automate.reduction(1,s);
			break;
		}
		return false;		
	}

	bool E4::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case INTEGER:
			automate.decalage(s, new E3);
			break;
			case OPEN:
			automate.decalage(s, new E2);
			break;

		}
		return false;		
	}

	bool E5::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case INTEGER:
			automate.decalage(s, new E3);
			break;
			case OPEN:
			automate.decalage(s, new E2);
			break;

		}
		return false;		
	}

	bool E6::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.decalage(s, new E4);
			break;
			case MULT:
			automate.decalage(s, new E5);
			break;
			case CLOSE:
			automate.decalage(s, new E9);
			break;
		}
		return false;		
	}

	bool E7::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.reduction(2, s);
			break;
			case MULT:
			automate.decalage(s, new E5);
			break;
			case CLOSE:
			automate.reduction(2, s);
			break;
			case END:
			automate.reduction(2, s);
			break;
		}
		return false;		
	}

	bool E8::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.reduction(2, s);
			break;
			case MULT:
			automate.reduction(2, s);
			break;
			case CLOSE:
			automate.reduction(2, s);
			break;
			case END:
			automate.reduction(2, s);
			break;
		}
		return false;
	}

	bool E9::transition(Automate & automate, Symbole * s) {
		switch(*s) {
			case PLUS:
			automate.reduction(2, s);
			break;
			case MULT:
			automate.reduction(2, s);
			break;
			case CLOSE:
			automate.reduction(2, s);
			break;
			case END:
			automate.reduction(2, s);
			break;
		}
		return false;
	}




	void readChar(ifstream& ifs, Symbole ** newSymbole); 

	int main(int c, char *v[])
	{
		std::vector<Symbole*> symboleList;
		Symbole ** newSymbole = new Symbole *;		
		ifstream ifs("test.txt", ios::in);
		if(ifs)
		{   
			do
			{
				readChar(ifs, newSymbole); 
				symboleList.push_back((*newSymbole));
			}while(int(*(*newSymbole)) != END && int(*(*newSymbole)) != ERROR);	

			ifs.close();
		}
		else
			cerr << "Impossible d'ouvrir le fichier !" << endl;

		for(int i = 0; i< symboleList.size(); i++)
		{
			cout << (int) (*symboleList[i]) << " ";
			delete symboleList[i];
		}

		delete newSymbole;

		return 0;
	}

	void readChar(std::ifstream& ifs, Symbole** newSymbole)
	{
		int c = ifs.peek();

		if(std::isdigit(c))
		{
			std::string newInt = "";
			char temp;
			ifs.get(temp);
			newInt+=temp;

			while(std::isdigit(ifs.peek()))
			{
				ifs.get(temp);
				newInt+=temp;
			}
			int newIntValue = std::stoi(newInt);
			(*newSymbole) = new Expr(INTEGER,newIntValue);
		}
		else if(c == EOF)
		{
			(*newSymbole) = new Symbole(END);
			ifs.get();
		}
		else 
		{
			switch(c)
			{
				case '(':
					(*newSymbole) = new Symbole(OPEN);
					break;
				case ')':
					(*newSymbole) = new Symbole(CLOSE);
					break;
				case '+':
					(*newSymbole) = new Symbole(PLUS);
					break;
				case '*':
					(*newSymbole) = new Symbole(MULT);
					break;
				default: 
					(*newSymbole) = new Symbole(ERROR);
					break;
			}
			ifs.get();
		}
	}

