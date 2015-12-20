#include "postfix.h"
#include <cstdlib>

int getPriority(char c){
	switch (c) {
    case '=':
        return 0;
    case '(':
        return 1;
	case '+':
	case '-':
        return 2;
	case '*':
	case '/':
        return 3;
    }
    return -1;
}

string toPost(string exp){
    if ( exp == "" )
        return "";
    Stack<char> s1;
    Stack<char> s2;
    char c;

    for (int i = 0; i < (int)exp.length(); i++){
        c = exp[i];        

        if ( c == ')' && !s2.isEmpty() ){
            while ( !s2.isEmpty() && s2.top() != '(' ){
                s1.push(s2.pop());
            }
            if (s2.isEmpty()) throw("Brackets");
            s2.pop();
            continue;
        } 
			// 3.1
        if (getPriority(c) >= 0){
            if ( !s2.isEmpty() && getPriority(c) <= getPriority(s2.top()) && (c != '(') ){
                while ( !s2.isEmpty() && ( getPriority(c) <= getPriority(s2.top()) ) ){
                    s1.push(s2.pop());
                }
            }
            s2.push(c);
            continue;
        }
			// 3.2
        if (isalpha(c) || isdigit(c)){
            s1.push(c);
            continue;
        }
        if (getPriority(c) >= 0){
            s2.push(c);
            continue;
        }
        throw "Unexpected token";
    }   // Now we have 2 stack's

    if ( s1.isEmpty() ){
        throw ("Not correct data");
    }

    while ( !s2.isEmpty() ){
        if ( '(' == s2.top() )
            throw("Brackets");
        s1.push(s2.pop());
    }

    string postExp("");
    while(!s1.isEmpty()) {
        c = s1.pop();
        postExp = string(1,c) + postExp;
    }

    //delete s1;
    //delete s2;
    return postExp;
}

map<char, double> getVals(string postExp){
    cout << "Input values:\n";
	map<char, double> vals;
    for ( int i = 0; i < (int)postExp.length(); i++){
		if ( isalpha(postExp[i]) && vals.find(postExp[i])==vals.end() ){
            try{
                cout << postExp[i] << "= ";
                cin >> vals[postExp[i]];
            }catch(...){
                throw("Not correct value");
            }
        }
    }
    return vals;
}

double postRez(string postExp, map<char, double> &vals){
    if ( postExp == "" )
        throw("String is empty");
	int len =(int) postExp.length();
	if (len > 1 && isalpha(postExp[0]) && postExp[len-1] == '=' ){
		string s = "";
		s.append(postExp, 1, len-2);
		double rez;
		try{
			rez = postRez(s, vals);
		} catch(...){
			throw("Not correct string");
		}
		return rez;
	} // X=.....
    char c;
    double l;
    double r;
    Stack<double> rez;
    for ( int i = 0; i < (int)postExp.length(); i++){
        c = postExp[i];

        if ( c == '\n')
            continue;
        if ( isalpha(c) ){
            rez.push(vals[c]);
            continue;
        }
        if ( isdigit(c) ){
            rez.push(atoi(&c)); //
            continue;
        }
        try{
            r = rez.pop();
			l = rez.pop();
        }catch(...){
			throw("Few operands or many operations");
        }
			
        switch (c) {
            case '+':
            {
                rez.push(l+r); 
                break;
            }
            case '-':
            {
                rez.push(l-r); 
                break;
            }
            case '*':
            {
                rez.push(l*r); 
                break;
            }
            case '/':
            {
                if ( r*r <= 0.00001 )
                    throw ("Divide on zero");
                rez.push(l/r); 
                break;
            }
			default:
				throw("Unexpected char");
        }        
    }
    r = rez.pop();
    if ( !rez.isEmpty() /*&& rez.top()!='='*/)
        throw("Not correct data");
    return r;
}
