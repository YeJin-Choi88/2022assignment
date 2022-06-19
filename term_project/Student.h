#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student {
	string s_id;
	string s_pw;
	string s_name;
	string s_Dp;
	map<string, double> m;

public:
	Student(string id, string pw, string name, string Dp, map<string, double> sub_sco);
	string get_id();
	void put_id(string id);
	string get_pw();
	string get_name();
	string get_Dp();
	map<string, double> get_sub();
};

#endif