#include "Student.h"

Student::Student(string id, string pw,string name, string Dp, map<string, double> sub_sco) {
	this->s_id = id; 
	this->s_pw = pw;
	this->s_name = name; 
	this->s_Dp = Dp; 
	map<string, double>::iterator iter;
	for (iter = sub_sco.begin(); iter != sub_sco.end(); iter++) {
		string sub;
		double score;
		sub = iter->first;
		score = iter->second;
		this->m.insert(pair<string, double>(sub, score));
	}
}
string Student::get_id() {
	return s_id;
}
void Student::put_id(string id) {
	this->s_id = id;
}
string Student::get_pw() {
	return s_pw;
}
string Student::get_name() {
	return s_name;
}
string Student::get_Dp() {
	return s_Dp;
}
map<string, double> Student::get_sub() {
	return m;
}
