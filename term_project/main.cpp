#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include "Student.h"
#include<algorithm>
#include<windows.h>

using namespace std;

vector <Student> students;

typedef struct peopleID {
	string id;
	string password;
}peopleID;
int count = 0;

int menu() {
	int menu;
	cout << "Available Login operaitons:" << endl;
	cout << "1. Admin Login" << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Enter menu : ";
	cin >> menu;
	return menu;
}

int Adminmenu() {
	int menu;
	cout << "- Logged in as Admin -" << endl;
	cout << "1. Add Students" << endl;
	cout << "2. Delete Student" << endl;
	cout << "3. View Table" << endl;
	cout << "4. Main Menu" << endl;
	cout << "5. Exit" << endl << endl;
	cout << endl << endl << "Enter menu : ";
	cin >> menu;
	cout << endl;
	return menu;
}

int Studentmenu() {
	int menu;
	cout << "- Logged in as Student -" << endl;
	cout << "1. View Table" << endl;
	cout << "2. Main Menu" << endl;
	cout << "3. Exit" << endl << endl;
	cout << endl << endl << "Enter menu : ";
	cin >> menu;
	cout << endl;
	return menu;
}

bool check_AdminID(string &id, string &pw) {
	ifstream fout;
	fout.open("Login.txt");
	if (fout.fail()) {
		cout << "파일을 찾을 수 없음" << endl;
	}
	cout << "ID:  ";
	cin >> id;
	cout << "PASSWORD: ";
	cin >> pw;
	string word1, word2;
	int idx = 0;
	peopleID people[100];
	while (fout >> word1 >> word2) {
		people[idx].id = word1;
		people[idx].password = word2;
		idx++;
	}
	fout.close();
	for (int i = 0; i < 1 + idx; i++) {
		if (id == "Admin") {
			if (people[i].id == id && people[i].password == pw) {
				cout << endl << "찾았습니다." << endl << endl;
				return true;
			}
			else {
				cout << endl << "찾지못하였습니다." << endl;
				return false;
			}
		}
		else {
			cout << endl << "찾지못하였습니다." << endl;
			return false;;
		}
		
	}
}

bool check_StudentID(string& id, string& pw) {
	ifstream fout;
	fout.open("Login.txt");
	if (!fout) {
		cout << "파일을 찾을 수 없음" << endl;
	}
	cout << "ID:  ";
	cin >> id;
	cout << "PASSWORD: ";
	cin >> pw;
	string word1, word2;
	int idx = 0;
	peopleID people[100];
	while (fout >> word1 >> word2) {
		people[idx].id = word1;
		people[idx].password = word2;
		idx++;
	}
	for (int i = 0; i < 1 + idx; i++) {
		if (id != "Admin") {
			if (people[i].id == id && people[i].password == pw) {
				cout << endl << "찾았습니다." << endl << endl;
				return true;
			}
			else {
				cout << endl << "찾지못하였습니다." << endl;
				return false;
			}
		}
		else {
			cout << endl << "찾지못하였습니다." << endl;
			return false;
		}
	}

}

void Add_Students() {
	fstream fin;

	fin.open("Login.txt", ios::app);
	while (true) {

		string id, pw, name, Dp;
		cout << "아이디(종료는 stop): ";
		cin >> id;
		if (id == "stop") break;
		cout << "비밀번호: ";
		cin >> pw;
		cout << "이름: ";
		cin >> name;
		cout << "학과: ";
		cin >> Dp;
		map<string, double> m = { };
		for (int i = 0; i < 3; i++) {
			string name;
			double num;
			cout << "과목 및 점수 : ";
			cin >> name >> num;
			m.insert(make_pair(name, num));
		}
		cout << endl<<endl;
		Student tmp(id, pw, name, Dp, m);
		students.push_back(tmp);
		fin << id << " " << pw << endl;
	}
	fin.close();
}

void Delete_Students() {
	fstream fin;

	fin.open("Login.txt");
	cout << "삭제할 학생의 이름을 입력해주세요: ";
	string name;
	cin >> name;
	cin.ignore(256, '\n');
	for (int i = 0; i < students.size(); i++) {
		if (name == students[i].get_name()) {
			students.erase(students.begin() + i);
			cout << "삭제에 성공하였습니다!" << endl << endl;
		}
		else {
			cout << "이름을 찾지 못하였습니다." << endl << endl;
		}
	}
}

void Print_Students(){
	for (int i = 0; i < students.size(); i++) {
		cout << "아이디: " << students[i].get_id() << endl;
		cout << "이름: " << students[i].get_name() << endl;
		cout << "학과: " << students[i].get_Dp() << endl;
		cout << "수강과목 및 성적: "<<endl<<endl;
		map<string, double>::iterator itr;
		for (students[i].get_sub().begin(); itr != students[i].get_sub().end(); ++itr) {
			cout << itr->first << " " << itr->second << " ";
		}
		cout << endl << endl;
	}
}

void Print_Student(string s_id) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].get_id()== s_id) {
			cout << "아이디: " << students[i].get_id() << endl;
			cout << "이름: " << students[i].get_name() << endl;
			cout << "학과: " << students[i].get_Dp() << endl;
			cout << "수강과목 및 성적: " << endl << endl;
		}
	}
}

int main() {
	while (true) {
		
		int n = menu();
		string id, pw;
		if (n == 1) {
			system("cls");
			
			if (check_AdminID(id,pw)) {
				while (true) {
					int adm = Adminmenu();
					if (adm == 1) {
						Add_Students();
					}
					else if (adm == 2) {
						Delete_Students();
					}
					else if (adm == 3) {
						Print_Students();
					}
					else if (adm == 4) {
						break;
					}
					else if (adm == 5) {
						return 0;
					}
				}
				
			}
			else {
				cout << "로그인에 실패하였습니다." << endl << endl;
			}
		}
		else if (n == 2) {
			if (check_StudentID(id,pw)) {
				int stu = Studentmenu();
				while (true) {
					if (stu == 1) {
						Print_Student(id);
					}
					else if (stu == 2) {
						break;
					}
					else if (stu == 3) {
						return 0;
					}
				}
			}
			else {
				cout << "로그인에 실패하였습니다." << endl << endl;
			}
			
		}
		else if (n == 3) {
			break;
		}
	}
}