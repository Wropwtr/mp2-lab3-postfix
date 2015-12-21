#include "postfix.h"
#include <iostream>

void main(){
	cout << "\t\tPostfix demonstration:\n1) Convert to postfix A+B\n";
	cout << toPost("A+B") << endl;

	cout << "2) Convert to postfix A+(B-C)*D-F/(G+H)\n";
	cout << toPost("A+(B-C)*D-F/(G+H)") << endl;

	map <char, double> vals;
	vals['A'] = 1;
	vals['B'] = 2;
	vals['C'] = 3;

	cout << "3)Calculate AB5++ with A = 1 and B = 2\n";
	cout << "\t" << postRez("AB5++",vals) << endl;

	int i = 1;
	while (i){
		cout << "Do you want to check your string? 1/0" << endl;
		cin >> i;
		if (i){
			string s ="";
			double rezult;
			cout << "Enter string:\t";
			cin >> s;
			try{
				s = toPost(s);
				cout << "Postfix notation: " << s;
				cout << endl;
				rezult = postRez(s, getVals(s));
				cout << "Rezult of calculation: " << rezult;
				cout << endl;
			}
			catch(...){
				cout << "You enter not correct data\n";
			}
		}
	}
	
	return;
}