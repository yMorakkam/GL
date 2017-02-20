#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

typedef enum{PLUS,MULT,OPEN,CLOSE,INTEGER,END,ERROR,EXPR} monEnum;

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


class 	Expr : public Symbole{
	protected:
		int value; //value of the number if Expr is a number
	public:
		Expr(): Symbole(EXPR){};
		Expr(int id, int value): Symbole(id), value(value){};
		virtual ~Expr(){}
		
		
};

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

bool readOneChar(){

}

bool readOneCharWithoutConsumeIt(){

} 