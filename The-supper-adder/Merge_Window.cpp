#include "Simple_window.h"
#include "Graph.h"
#include "Token.h"
#include "Player.h"
using namespace Graph_lib;





struct Tile : Button {
	
	Tile(Point xy, int w, int h, const string& label, Callback cb)
            : Button(xy,w,h,label,cb),
            op(label)
        {}

        //This mutator function has not been tested
        void set_point (Point p)
		{
			move(p.x - loc.x, p.y - loc.y);
		}

        //void attach(Window&);

        //As of 6:55 11/11, this would not work because the tile's op value was not set.
        //Only it's label was set.
        //Accessor Function
        string get_op() const {return op;}

private:
	string op;
};






struct Merge_window : Graph_lib::Window {

    //Passing the next win as an argument is no longer necessary
	Merge_window (Point xy, int w, int h, const string& title, vector<Player>*, vector<Player>*, vector<Player>*, vector<Player>*, vector<Player>*);

private:
//----------------These are W1 things-------------------------------------
	Text game_title{Point{150, 50}, " Fun! Math Game"};//15 chars
	Text Team_number{Point{150, 150}, "Team Number: 20"};
	Text Team_members{Point{150, 200}, "Team Members:"};
	Text Jiang{Point{150, 250}, "Yucheng Jiang"};
	Text Mejia{Point{150, 300}, "Jonathan Mejia"};
	Text Khureshi{Point{150, 350}, "Amreen Khureshi"};
	
	string instructions1{"The object of the game is to rearrange a certain number of tiles \n(each labelled with a"};
	string instructions2{"digit or an operator) to yield the highest arithmetic value. For example, the three tiles"};
	string instructions3{" (3), (5), and (+) could be rearranged to 3+5 = 8, 5+3 = 8, +35 = 35, or +53 = 53. Since"};
	string instructions4{"+53 has the highest value, that is the best move. If 35+ or 53+ is chosen, the score is zero"};
    string instructions5{"since that is not a “well-formed formula” in arithmetic (in other words, it is an illegal move)."};
	string instructions6{"When using factorial (!), it may only be used after a digit with a value of 9 or lower."};

	Text Instructions1{Point{10, 150}, instructions1};
	Text Instructions2{Point{10, 175}, instructions2};
	Text Instructions3{Point{10, 200}, instructions3};
    Text Instructions4{Point{10, 225}, instructions4};
    Text Instructions5{Point{10, 250}, instructions5};
	Text Instructions6{Point{10, 275}, instructions6};
 
	Button start;
	Button to_part_2;

public:

	static void cb_start(Address, Address);
	static void cb_to_part_2(Address, Address);

	void start_button_pressed();
	void to_2_button_pressed();

//--------------------These are W2 things-------------------------------

     void get();

private:

    //These are placed next to each other
	In_box initials;
	Button get_initials;

    Text test{Point{100, 300}, ""};

    //vectors declared and set to parameter values 
	vector<Player>* v3;
	vector<Player>* v4;
	vector<Player>* v5;
	vector<Player>* v6;
	vector<Player>* v7; 


		//The top Player in each level is displayed
	//THIS ONLY WORKS IF THE FIRST ELEMENT IS THE TOP PLAYER
	
	
	vector<Shape> Leaderboard3;
	vector<Shape> Leaderboard4;
	vector<Shape> Leaderboard5;
	vector<Shape> Leaderboard6;
	vector<Shape> Leaderboard7;

	

	

	//Texts for initials are defined
	Text t31i = {Point{100, 200}, (*v3)[0].initial()};
	Text t32i = {Point{100, 220}, (*v3)[1].initial()};
	Text t33i = {Point{100, 240}, (*v3)[2].initial()};
	Text t34i = {Point{100, 260}, (*v3)[3].initial()};
	Text t35i = {Point{100, 280}, (*v3)[4].initial()};
	
	//Texts for scores are defined; SETPRECISION AND FIXED MAY BE NEEDED
	Text t31s = {Point{200, 200}, to_string( (*v3)[0].score() )};
	Text t32s = {Point{200, 220}, to_string( (*v3)[1].score() )};
	Text t33s = {Point{200, 240}, to_string( (*v3)[2].score() )};
	Text t34s = {Point{200, 260}, to_string( (*v3)[3].score() )};
	Text t35s = {Point{200, 280}, to_string( (*v3)[4].score() )};

	//Leaderboard3.push_back(t31i);

	//Texts for initials are defined
	Text t41i = {Point{100, 200}, (*v4)[0].initial()};
	Text t42i = {Point{100, 220}, (*v4)[1].initial()};
	Text t43i = {Point{100, 240}, (*v4)[2].initial()};
	Text t44i = {Point{100, 260}, (*v4)[3].initial()};
	Text t45i = {Point{100, 280}, (*v4)[4].initial()};
	
	//Texts for scores are defined; SETPRECISION AND FIXED MAY BE NEEDED
	Text t41s = {Point{200, 200}, to_string( (*v4)[0].score() )};
	Text t42s = {Point{200, 220}, to_string( (*v4)[1].score() )};
	Text t43s = {Point{200, 240}, to_string( (*v4)[2].score() )};
	Text t44s = {Point{200, 260}, to_string( (*v4)[3].score() )};
	Text t45s = {Point{200, 280}, to_string( (*v4)[4].score() )};

	//Texts for initials are defined
	Text t51i = {Point{100, 200}, (*v5)[0].initial()};
	Text t52i = {Point{100, 220}, (*v5)[1].initial()};
	Text t53i = {Point{100, 240}, (*v5)[2].initial()};
	Text t54i = {Point{100, 260}, (*v5)[3].initial()};
	Text t55i = {Point{100, 280}, (*v5)[4].initial()};
	
	//Texts for scores are defined; SETPRECISION AND FIXED MAY BE NEEDED
	Text t51s = {Point{200, 200}, to_string( (*v5)[0].score() )};
	Text t52s = {Point{200, 220}, to_string( (*v5)[1].score() )};
	Text t53s = {Point{200, 240}, to_string( (*v5)[2].score() )};
	Text t54s = {Point{200, 260}, to_string( (*v5)[3].score() )};
	Text t55s = {Point{200, 280}, to_string( (*v5)[4].score() )};

	//Texts for initials are defined
	Text t61i = {Point{100, 200}, (*v6)[0].initial()};
	Text t62i = {Point{100, 220}, (*v6)[1].initial()};
	Text t63i = {Point{100, 240}, (*v6)[2].initial()};
	Text t64i = {Point{100, 260}, (*v6)[3].initial()};
	Text t65i = {Point{100, 280}, (*v6)[4].initial()};
	
	//Texts for scores are defined; SETPRECISION AND FIXED MAY BE NEEDED
	Text t61s = {Point{200, 200}, to_string( (*v6)[0].score() )};
	Text t62s = {Point{200, 220}, to_string( (*v6)[1].score() )};
	Text t63s = {Point{200, 240}, to_string( (*v6)[2].score() )};
	Text t64s = {Point{200, 260}, to_string( (*v6)[3].score() )};
	Text t65s = {Point{200, 280}, to_string( (*v6)[4].score() )};

	//Texts for initials are defined
	Text t71i = {Point{100, 200}, (*v7)[0].initial()};
	Text t72i = {Point{100, 220}, (*v7)[1].initial()};
	Text t73i = {Point{100, 240}, (*v7)[2].initial()};
	Text t74i = {Point{100, 260}, (*v7)[3].initial()};
	Text t75i = {Point{100, 280}, (*v7)[4].initial()};
	
	//Texts for scores are defined; SETPRECISION AND FIXED MAY BE NEEDED
	Text t71s = {Point{200, 200}, to_string( (*v7)[0].score() )};
	Text t72s = {Point{200, 220}, to_string( (*v7)[1].score() )};
	Text t73s = {Point{200, 240}, to_string( (*v7)[2].score() )};
	Text t74s = {Point{200, 260}, to_string( (*v7)[3].score() )};
	Text t75s = {Point{200, 280}, to_string( (*v7)[4].score() )};



	//---------------------These are W3 things-------------------------
public:
	//These are cb functions for level selection
	void choose_3();
	void choose_4();
	void choose_5();
	void choose_6();
	void choose_7();

	//These are cb functions for each tile
	static void cb1(void*, void*);
	static void cb2(void*, void*);
	static void cb3(void*, void*);
	static void cb4(void*, void*);
	static void cb5(void*, void*);
	static void cb6(void*, void*);
	static void cb7(void*, void*);

	void cb_continue();
	void cb_quit();

	//Number of tiles created depends on the value of num_tiles which is determined 
	//by level selection
	void create_Tiles();

	//All of the cb functions for each tile call this function.
	//Where the int references the number element in the vector of tiles
	void to_for_line(int);
	double primary();
	double fac();
	double term();
	double expression();
	double cal();
	Token_stream ts;
	vector<Token> vt;
	

private:

	//This window individually will only assign the score value of this player.
	Player current_player;

	//Score is determined by result of Jiang's calc
	Text display_score{Point{300, 200}, ""};

	//This is a vector of points that predetermines the positions of each position of
	//the tile after it's clicked
	//These Points must be tested to see if they're good spots; trial and error
	vector<Point> form_points {Point{75, 550}, Point{150, 550}, Point{225, 550}, Point{300, 550}, Point{375, 550}, Point{450, 550}, Point{525, 550}};
	
	//These buttons determine level selection
	Button L3, L4, L5, L6, L7;

	Button again, quit;

	short int num_tiles;
	short int num_tiles_clicked = 0;


	vector<short int> tiles_clicked{0, 0, 0, 0, 0, 0, 0};

	//random_strings is the randomly oredered vector.
	//sorted_strings order is chosen by the player by clicking tiles.
	vector<string> random_strings,sorted_strings;

	//vector of Tiles because why not?
	vector<Tile*> v_Tile;

	void player_sort();
	
	void to_for_line_sup();

	void attach_Lead3();
	void attach_Lead4();
	void attach_Lead5();
	void attach_Lead6();
	void attach_Lead7();

	void detach_Lead3();
	void detach_Lead4();
	void detach_Lead5();
	void detach_Lead6();
	void detach_Lead7();

	void detach_L_buttons();
};

Merge_window::Merge_window(Point xy, int w, int h, const string& title, vector<Player>* v3, vector<Player>* v4, vector<Player>* v5, vector<Player>* v6, vector<Player>* v7)

	:Window(xy,w,h,title),

	to_part_2(Point(x_max()-150,0),70,20,"Next_2",cb_to_part_2),
	start(Point(x_max()-150,0),70,20,"Start",cb_start),
    initials(Point{50, 50}, 50, 50, "Initials"),
    get_initials{Point{100, 50}, 50, 50, "Submit",
	 [](Address, Address pw){reference_to<Merge_window>(pw).get();}},
	 v3(v3), v4(v4), v5(v5), v6(v6), v7(v7),
	 L3{Point{50, 50}, 50, 50, "Level 3",
	 [](Address, Address pw){reference_to<Merge_window>(pw).choose_3();}},
	 L4{Point{150, 50}, 50, 50, "Level 4",
	 [](Address, Address pw){reference_to<Merge_window>(pw).choose_4();}},
	 L5{Point{250, 50}, 50, 50, "Level 5",
	 [](Address, Address pw){reference_to<Merge_window>(pw).choose_5();}},
	 L6{Point{350, 50}, 50, 50, "Level 6",
	 [](Address, Address pw){reference_to<Merge_window>(pw).choose_6();}},
	 L7{Point{450, 50}, 50, 50, "Level 7",
	 [](Address, Address pw){reference_to<Merge_window>(pw).choose_7();}},
	 again{Point(300, 250), 100, 50, "Continue",
	 [](Address, Address pw){reference_to<Merge_window>(pw).cb_continue();}},
	 quit{Point(300, 350), 100, 50, "Quit",
	 [](Address, Address pw){reference_to<Merge_window>(pw).cb_quit();}}
	  
{
		game_title.set_font_size(40);

		attach(start);
		attach(game_title);
		attach(Team_number);
		attach(Team_members);
		attach(Jiang);
		attach(Mejia);
		attach(Khureshi);
		v_Tile.resize(7);

		//Leaderboard3.push_back(t31i);
/*
		for (int j = 0; j < 5; j++) {
			Leaderboard3i.push_back(new Text(Point{100, 200 + 20 * j}, (*v3)[j].initial()));
		}*/
}



double Merge_window::primary()
{
    Token t = ts.get(vt);
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get(vt);
            if (t.kind != ')') throw Invalid{};
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
	case '-':{
		double e=term();
		return 0-e;
	}
	case '+':{
		double e=term();
		return e;
	}
	
    default:
        throw Invalid{};
    }
}

//------------------------------------------------------------------------------
double Merge_window::fac()
{
	double left=primary();
	Token t=ts.get(vt);
	while (true){
		switch(t.kind){
			case '!':{
			if (left>9) throw Invalid{};
			if (left!=floor(left))throw Invalid{};
			left=factorial(left);
			t=ts.get(vt);
			break;
			}
			default:
			ts.putback(t);
			return left;
		}
	}
}
// deal with *, /, and %
double Merge_window::term()
{
    double left = fac();
    Token t = ts.get(vt);        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= fac();
            t = ts.get(vt);
			break;
        case '/':
            {    
                double d = fac();
                if (d == 0) throw Invalid{};
                left /= d; 
                t = ts.get(vt);
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------


// deal with + and -
double Merge_window::expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get(vt);        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get(vt);
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get(vt);
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}


double Merge_window::cal()
try{
	if(check_legal(vt)){
	double val;
    while (true) {
        Token t = ts.get(vt);

        
        if (t.kind == '=') {       // '=' for "print now"
            
			break;
		}
        else
            ts.putback(t);
        val = expression();
    }return val;
	}
	else return 0;
}
catch (Invalid){
	return 0;
}


void Merge_window::cb_start(Address, Address pw){
	reference_to<Merge_window>(pw).start_button_pressed();
}

void Merge_window::cb_to_part_2(Address, Address pw) {
	reference_to<Merge_window>(pw).to_2_button_pressed();
}

void Merge_window::cb_continue() {
//	v_Tile.erase(v_Tile.begin(), v_Tile.end());
sorted_strings.clear();
num_tiles_clicked = 0;
ts.count=0;                      //reset ts.count
if (num_tiles < 5) {
	random_strings = random(num_tiles);
}
else if(num_tiles==5)
	random_strings = random5();
else if(num_tiles==6)
	random_strings = random6();
else {
	random_strings = random7();
}
	detach(again);
	detach(quit);

	for (int i = 0; i < num_tiles; i++) {
		detach( *(v_Tile[i]) );
	}

	for (int i = 0; i < num_tiles; i++) {
		tiles_clicked[i] = 0;
	}
	create_Tiles();
	redraw();

}

void Merge_window::cb_quit() {
	hide();
}

void Merge_window::start_button_pressed() {
	detach(Team_number);
	detach(Team_members);
	detach(Jiang);
	detach(Mejia);
	detach(Khureshi);
	
	detach(start);

	attach(Instructions1);
	attach(Instructions2);
	attach(Instructions3);
    attach(Instructions4);
	attach(Instructions5);
	attach(Instructions6);
	attach(to_part_2);
	
	redraw();
}

void Merge_window::to_2_button_pressed() {
	//Display next window
	//nwin->show();
    detach(game_title);
    detach(Instructions1);
	detach(Instructions2);
	detach(Instructions3);
    detach(Instructions4);
	detach(Instructions5);
	detach(Instructions6);
	detach(to_part_2);

   	attach(L3);
	attach(L4);
	attach(L5);
	attach(L6);
	attach(L7);

	redraw();
	//hide();
}

void Merge_window::create_Tiles() {

	//Number of tiles created is dependent on value of num_tiles
	v_Tile[0] = (new Tile(Point{ 50 * (0 + 1), 100 }, 50, 50, random_strings[0], cb1));
	v_Tile[1] = (new Tile(Point{ 50 * (1 + 1), 100 }, 50, 50, random_strings[1], cb2));
	v_Tile[2] = (new Tile(Point{ 50 * (2 + 1), 100 }, 50, 50, random_strings[2], cb3));

	if (num_tiles > 3)
		v_Tile[3] = (new Tile(Point{ 50 * (3 + 1), 100 }, 50, 50, random_strings[3], cb4));
	if (num_tiles > 4)
		v_Tile[4] = (new Tile(Point{ 50 * (4 + 1), 100 }, 50, 50, random_strings[4], cb5));
	if (num_tiles > 5)
		v_Tile[5] = (new Tile(Point{ 50 * (5 + 1), 100 }, 50, 50, random_strings[5], cb6));
	if (num_tiles > 6)
		v_Tile[6] = (new Tile(Point{ 50 * (6 + 1), 100 }, 50, 50, random_strings[6], cb7));
	
	for (int i = 0; i < num_tiles; i++) {
		attach( *(v_Tile[i]) );
	}
	
}

//Display the top 5 scores of level (num_tiles)
void Merge_window::choose_3() {

	num_tiles = 3;

	detach_L_buttons();

	random_strings = random(num_tiles);
	//if (random_strings.size() != 3)
	//throw something;

	attach_Lead3();
	
	attach(initials);
	attach(get_initials);


	redraw();
}

void Merge_window::choose_4() {

	num_tiles = 4;

	detach_L_buttons();
	
	random_strings = random(num_tiles);	

	attach_Lead4();

	attach(initials);
	attach(get_initials);
	
	redraw();
}

void Merge_window::choose_5() {

	num_tiles = 5;

	detach_L_buttons();
	
	random_strings = random(num_tiles);
	
	attach_Lead5();
	
	attach(initials);
	attach(get_initials);

	redraw();
}

void Merge_window::choose_6() {

	num_tiles = 6;

	detach_L_buttons();
	
	random_strings = random(num_tiles);

	attach_Lead6();
	
	attach(initials);
	attach(get_initials);

	redraw();
}

void Merge_window::choose_7() {

	num_tiles = 7;

	detach_L_buttons();
	
	random_strings = random7();

	attach_Lead7();
	
	attach(initials);
	attach(get_initials);

	redraw();
}

void Merge_window::cb1(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(0);
}

void Merge_window::cb2(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(1);
}

void Merge_window::cb3(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(2);
}

void Merge_window::cb4(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(3);
}

void Merge_window::cb5(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(4);}


void Merge_window::cb6(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(5);
}

void Merge_window::cb7(void*, void*pw){
	reference_to<Merge_window>(pw).to_for_line(6);
}

void Merge_window::to_for_line(int i) {

	if ( tiles_clicked[i] ) {
		cout << "This tile has already been clicked!\n\n";
		return;
	}
	else {
		tiles_clicked[i]++;
	}

	//Text t3i = {Point{100, 200}, v3[0]->initial()};

	//string value associated with the ith tile adds to sorted_strings
	sorted_strings.push_back( v_Tile[i]->get_op() );

	//Move each tile by setting it's point after it's clicked
	v_Tile[i]->set_point(form_points[num_tiles_clicked]);
	
	cout << "Button moved to " << form_points[num_tiles_clicked].x << ", " << form_points[num_tiles_clicked].y << endl << endl;
	
	redraw();

	//In order to access the next point in the form_points vector
	num_tiles_clicked++; cout << "num_tiles_clicked " << num_tiles_clicked << endl;

	if (num_tiles == num_tiles_clicked) {
		
		//return sorted_strings to one of Jiang's functions, so that his function
		//can calculate the result.
        vector<string> s2=combine(sorted_strings);
        vt=f(s2);
		double ds=cal();
		current_player.set_score( ds );
		stringstream stream;
		stream<<fixed<<setprecision(2)<<ds;
		string ss=stream.str();
		display_score.set_label( ss );

		to_for_line_sup();
		}
}

void Merge_window::to_for_line_sup() {

		show();
		Fl::redraw();
		Fl::wait();

		attach(display_score);
		show();
		Fl::redraw();
		Fl::wait();
		this_thread::sleep_for(chrono::seconds(5));
		detach(display_score);
		
		player_sort();

		attach(again);
		attach(quit);
		redraw();
}

void Merge_window::player_sort() {

	switch (num_tiles){
			case 3:
			v3->push_back(current_player);
			rankplayers(*v3);
			write_file(*v3,"level3.txt");
			v3->pop_back();
			break;
			case 4:
			v4->push_back(current_player);
			rankplayers(*v4);
			write_file(*v4,"level4.txt");
			v4->pop_back();
			break;
			case 5:
			v5->push_back(current_player);
			rankplayers(*v5);
			write_file(*v5,"level5.txt");
			v5->pop_back();
			break;
			case 6:
			v6->push_back(current_player);
			rankplayers(*v6);
			write_file(*v6,"level6.txt");
			v6->pop_back();
			break;
			case 7:
			v7->push_back(current_player);
			rankplayers(*v7);
			write_file(*v7,"level7.txt");
			v7->pop_back();
			break;
		}
}

//Must display initials this is what Submit does
void Merge_window::get() {
	//MAKE SURE CURRENT_PLAYER HAS VALUE IN NEXT WINDOW
	
	detach(initials);
	detach(get_initials);

	show();
	Fl::redraw();
	Fl::wait();

	//current_player assigned value from Inbox
	current_player = Player(initials.get_string(), -1);
	
	//Text test is given the string initial value
	test.set_label( current_player.initial() );
	
	//Attached purely as a test for now to show the value was received
	attach(test);
	show();
	Fl::redraw();
	Fl::wait();
	this_thread::sleep_for(chrono::seconds(5));
	detach(test);

	if (num_tiles == 3) {
	detach_Lead3();
	}

	else if (num_tiles == 4) {
	detach_Lead4();
	}

	else if (num_tiles == 5) {
	detach_Lead5();
	}

	else if (num_tiles == 6) {
	detach_Lead6();
	}

	else if (num_tiles == 7) {
	detach_Lead7();
	}
	
	create_Tiles();
	
	redraw();
}

void Merge_window::attach_Lead3() {
	attach(t31i);
	attach(t32i);
	attach(t33i);
	attach(t34i);
	attach(t35i);
	
	attach(t31s);
	attach(t32s);
	attach(t33s);
	attach(t34s);
	attach(t35s);
}
void Merge_window::attach_Lead4() {
	attach(t41i);
	attach(t42i);
	attach(t43i);
	attach(t44i);
	attach(t45i);
	
	attach(t41s);
	attach(t42s);
	attach(t43s);
	attach(t44s);
	attach(t45s);
}
void Merge_window::attach_Lead5() {
	attach(t51i);
	attach(t52i);
	attach(t53i);
	attach(t54i);
	attach(t55i);
	
	attach(t51s);
	attach(t52s);
	attach(t53s);
	attach(t54s);
	attach(t55s);
}
void Merge_window::attach_Lead6() {
	attach(t61i);
	attach(t62i);
	attach(t63i);
	attach(t64i);
	attach(t65i);
	
	attach(t61s);
	attach(t62s);
	attach(t63s);
	attach(t64s);
	attach(t65s);
}
void Merge_window::attach_Lead7() {
	attach(t71i);
	attach(t72i);
	attach(t73i);
	attach(t74i);
	attach(t75i);
	
	attach(t71s);
	attach(t72s);
	attach(t73s);
	attach(t74s);
	attach(t75s);
}

void Merge_window::detach_Lead3() {
	detach(t31i);
	detach(t32i);
	detach(t33i);
	detach(t34i);
	detach(t35i);
	
	detach(t31s);
	detach(t32s);
	detach(t33s);
	detach(t34s);
	detach(t35s);
}
void Merge_window::detach_Lead4() {
	detach(t41i);
	detach(t42i);
	detach(t43i);
	detach(t44i);
	detach(t45i);
	
	detach(t41s);
	detach(t42s);
	detach(t43s);
	detach(t44s);
	detach(t45s);
}
void Merge_window::detach_Lead5() {
	detach(t51i);
	detach(t52i);
	detach(t53i);
	detach(t54i);
	detach(t55i);
	
	detach(t51s);
	detach(t52s);
	detach(t53s);
	detach(t54s);
	detach(t55s);
}
void Merge_window::detach_Lead6() {
	detach(t61i);
	detach(t62i);
	detach(t63i);
	detach(t64i);
	detach(t65i);
	
	detach(t61s);
	detach(t62s);
	detach(t63s);
	detach(t64s);
	detach(t65s);
}
void Merge_window::detach_Lead7() {
	detach(t71i);
	detach(t72i);
	detach(t73i);
	detach(t74i);
	detach(t75i);
	
	detach(t71s);
	detach(t72s);
	detach(t73s);
	detach(t74s);
	detach(t75s);
}

void Merge_window::detach_L_buttons() {
	detach(L3);
	detach(L4);
	detach(L5);
	detach(L6);
	detach(L7);
}

int main() {

    vector<Player> v3, v4, v5, v6, v7;

	fill_vector(v3,"level3.txt", '_' );
	fill_vector(v4,"level4.txt", '_' );
	fill_vector(v5,"level5.txt", '_' );
	fill_vector(v6,"level6.txt", '_' );
	fill_vector(v7,"level7.txt", '_' );
	

	Merge_window win(Point(100,100),600,600,"Start Screen", &v3, &v4, &v5, &v6, &v7);
	return gui_main();
}