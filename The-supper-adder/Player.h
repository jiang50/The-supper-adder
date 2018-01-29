#include "std_lib_facilities_4.h"

class Player{
	public:

	//Constructors
	Player() : in("undefined"), s(-1) {};
	Player(string initial, double score):in(initial),s(score){}
	
	//Accessor functions
	string initial() const {return in;}
	double score() const {return s;}

	//Mutative functions
	void set_initials (string init) {in = init;}
	void set_score (double ss) {s = ss;}
	
	private:
	string in;
	double s;
};

void fill_vector(vector<Player>& p,string file,char terminator);
void rankplayers(vector<Player>& player);
void write_file(vector<Player>p, string file);
vector<string> random(int n);
vector<string> random5();
vector<string> random6();
vector<string> random7();