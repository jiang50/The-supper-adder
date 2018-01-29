#include "Token.h"
#include "std_lib_facilities_4.h"

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0),count(0)  // no Token in buffer
{}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get(vector<Token> vt)
{
	
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 
	else{

	int c=count;
	count++;
	return vt[c];
	}
}

//-------------------------------------------------

bool opcheck(char ch){
	switch(ch){
		case '(': case ')': case '+': case '-': case '*': case '/': case '=':case '!':{
			return true;
		}
		case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':{
				return false;
			}
	}
}

vector<Token> f(vector<string> s){
	vector<Token> t;
	for(auto i=0;i<s.size();i++){	
		if (opcheck(s[i][0])){
			char op=s[i][0];
			Token t1{op};
			t.push_back(t1);
		}
		else{
			double opr=atoi(s[i].c_str());
			Token t2{'8',opr};
			t.push_back(t2);
		}
	
	}Token last{'=',0};
	t.push_back(last);
	return t;
}


vector<string> combine(vector<string> s){
	int i=0;
	vector<string> newst;
	while (i<s.size()){
		if (opcheck(s[i][0])){
			newst.push_back(s[i]);
			i++;
		}
		else {
			string str="";
			while(i<s.size()&&opcheck(s[i][0])==false){
			str=str+s[i];
			i++;
		}
			newst.push_back(str);
		}
	}
		return newst;
}

bool check_legal(vector<Token> vt){
	for (int i=0;i<vt.size()-1;i++){
		if (vt[i].kind=='+'||vt[i].kind=='-'||vt[i].kind=='*'||vt[i].kind=='/'){
			if(vt[i+1].kind=='+'||vt[i+1].kind=='-'||vt[i+1].kind=='*'||vt[i+1].kind=='/'||vt[i+1].kind=='!')
				return false;
		}
		else if (vt[i].kind=='8'&&(vt[i+1].kind=='8'||vt[i+1].kind=='('))
			return false;
		else if (vt[i].kind=='!'&&(vt[i+1].kind=='8'||vt[i+1].kind=='('))
			return false;
	} return true;
}

double factorial(double n){
	double result=1;
	while(n>1){
		result=n*result;
		n--;
	}return result;
}

