#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<string> readFile(char *file){
	ifstream in(file);
	vector<string> buf;
	string s;
	while (getline(in,s))
		buf.push_back(s);
	return buf;
}
void lex(char *file){
	vector<string> codes = readFile(file);
	for (int i = 0; i < codes.size(); i++){
		cout << i + 1 << ":" << codes[i] << endl;
	}
}
int main(int argc, char *argv[]){
	if (argc == 2){
		lex(argv[1]);
	}
}