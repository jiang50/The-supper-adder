#include "std_lib_facilities_4.h"
#include "Player.h"

void fill_vector(vector<Player>& p,string file,char terminator){
	
	ifstream ist{file};
	if (!ist) error("can't open input file ",file);
	string initial;
	double score;
	while(ist>>initial>>score)
		p.push_back(Player{initial,score});
	if (ist.eof())return;
	if (ist.bad())error("ist is bad");
	if (ist.fail()){
		ist.clear();
		char c;
		ist>>c;
		if (c!=terminator){
			ist.unget();
			ist.clear(ios_base::failbit);
		}
	}
}

void rankplayers(vector<Player>& player){
	int n=player.size();
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n-i-1;j++){
			if (player[j].score()<player[j+1].score()){
				Player temp=player[j+1];
				player[j+1]=player[j];
				player[j]=temp;
			}
		}
			
}

void write_file(vector<Player>p, string file){
	ofstream ost{file};
	if (!ost) error("can't open output file ",file);
	if (p.size()<5){//changed <= to <
		for (int i=0;i<p.size();i++)
		ost<<p[i].initial()<<'\t'<<p[i].score()<<'\t'<<endl;
		}
	else {
		for (int i=0;i<5;i++)
		ost<<p[i].initial()<<'\t'<<p[i].score()<<'\t'<<endl;
	}
}

vector<string> random(int n) {
	vector<string> a={ "0","1","2","3","4","5","6","7","8","9","+","-","*","/"};
	int count_op = 0;
	vector<string> b;
	srand (time(NULL));
	for (int i = 0; i < n; i++) {
		int ran = rand() % 14;
		if (count_op == 0) {
			while (ran < 10)
				ran = rand() % 14;
			b.push_back(a[ran]);
			count_op++;
		}
		else if (count_op == (n-1) / 2) {
			while (ran > 9)
				ran = rand() % 14;
			b.push_back(a[ran]);
		}
		else {
			b.push_back(a[ran]);
			if (ran>9)
				count_op++;
		}
	}
	return b;
}
//level5
vector<string> random5(){
	srand(time(NULL));
	vector<string>b;
	int a=rand()%3;
	if (a==0){
		b=random(4);
		b.push_back("!");
	}
	else b=random(6);
	return b;
}
//level 6
vector<string> random6(){
	srand(time(NULL));
	vector<string>b;
	int a=rand()%9;
	if (a==0){
		b=random(4);
		b.push_back("(");
		b.push_back(")");
		
	}
	else if (a>5){
		b=random(4);
		b.push_back("!");
		int c=rand()%10;
		b.push_back(to_string(c));
	}
	else b=random(6);
	return b;
}


//level 7
vector<string> random7(){
	srand(time(NULL));
	vector<string>b;
	int a=rand()%3;
	if(a==0){
		b=random(4);
		b.push_back("(");
		b.push_back(")");
		int c=rand()%10;
		b.push_back(to_string(c));
	}
	else if (a==1){
		b=random(6);
		b.push_back("!");
	}
	else b=random(7);
	return b;
}


