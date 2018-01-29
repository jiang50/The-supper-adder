#include "std_lib_facilities_4.h"

class Token {
public:
    
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class Invalid{};

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get(vector<Token> vt);      // get a Token (get() is defined elsewhere)
	int count;
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
	
	
};

bool opcheck(char ch);
vector<Token> f(vector<string> s);//convert vector of string to vector of Token
vector<string> combine(vector<string> s);
bool check_legal(vector<Token> vt);
double factorial(double n);