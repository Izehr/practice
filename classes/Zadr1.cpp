#include <iostream>
#include <regex>
#include <string>
#include <locale.h>

using namespace std;

class Library {
private:
	string ID;
	string Names;
	int Readers;
public:
	string getID() {
		return ID;
	}
	int setID(string id_current) {
		int error_current{ 0 };
		smatch m;
		if (id_current != "" and id_current != " ") {
			ID = id_current;
			error_current = 0;
		}
		else {
			error_current = -1;
		};
		if (!regex_search(id_current, m, regex("[0-9]{40}"))) {
			error_current = 0;
		}
		else {
			error_current = -1;
		};
		return error_current;
	}
	string getNames() {
		return Names;
	}
	int setNames(string names_current) {
		int error_current{ 0 };
		smatch m;
		if (names_current != "" and names_current != " ") {
			Names = names_current;
			error_current = 0;
		}
		else {
			error_current = -1;
		}
		return error_current;
	}
	int getReaders() {
		return Readers;
	}
	int setReaders(int readers_current) {
		int error_current{ 0 };
		smatch m;
		if (readers_current < 0 or readers_current > 999) {
			Readers = readers_current;
			error_current = 0;
		}
		else {
			error_current = -1;
		}
		return error_current;
	}
};

class Event : public Library {
private:
	string Date;
	string Name;
public:
	string getDate() {
		return Date;
	}
	int setDate(string date_current){
		int error_current{0};
		smatch m;
		if (!regex_match(date_current, m, regex("^(((0[1-9]|[12]\d|3[01])\/(0[13578]|1[02])\/((19|[2-9]\d)\d{2}))|((0[1-9]|[12]\d|30)\/(0[13456789]|1[012])\/((19|[2-9]\d)\d{2}))|((0[1-9]|1\d|2[0-8])\/02\/((19|[2-9]\d)\d{2}))|(29\/02\/((1[6-9]|[2-9]\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00))))$"))) {
			error_current = 0;
			Date = date_current;
		}
		else {
			error_current = -1;
		}
		return error_current;
	}

	string getName() {
		return Name;
	}
	int setNames(string name_current) {
		int error_current{ 0 };
		smatch m;
		if (name_current != "" and name_current != " ") {
			Name = name_current;
			error_current = 0;
		}
		else {
			error_current = -1;
		}
		return error_current;
	}


};


void testLibraryID(Library test_id) {
	string id_current = "id.3242352525";
	if (test_id.setID(id_current) == 0) {
		cerr << "Positive test " << id_current << " passed" << endl;
	}
	else {
		cerr << "Positive test " << id_current << " failed" << endl;
	}
	id_current = "";
	if (test_id.setID(id_current) == -1) {
		cerr << "Negative test " << id_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << id_current << " failed" << endl;
	}
	id_current = " ";
	if (test_id.setID(id_current) == -1) {
		cerr << "Negative test " << id_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << id_current << " failed" << endl;
	}
}

void testLibraryNames(Library test_names) {
	string names_current = "BBD";
	if (test_names.setNames(names_current) == 0) {
		cerr << "Positive test " << names_current << " passed" << endl;
	}
	else {
		cerr << "Positive test " << names_current << " failed" << endl;
	}
	names_current = "";
	if (test_names.setID(names_current) == -1) {
		cerr << "Negative test " << names_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << names_current << " failed" << endl;
	}
	names_current = " ";
	if (test_names.setID(names_current) == -1) {
		cerr << "Negative test " << names_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << names_current << " failed" << endl;
	}
}

void testLibraryReaders(Library test_readers) {
	int readers_current = 99;
	if (test_readers.setReaders(readers_current) == 0) {
		cerr << "Positive test " << readers_current << " passed" << endl;
	}
	else {
		cerr << "Positive test " << readers_current << " failed" << endl;
	}
	readers_current = -1;
	if (test_readers.setReaders(readers_current) == -1) {
		cerr << "Negative test " << readers_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << readers_current << " failed" << endl;
	}
	readers_current = 1000;
	if (test_readers.setReaders(readers_current) == -1) {
		cerr << "Negative test " << readers_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << readers_current << " failed" << endl;
	}
}

void testEventLibraryDate(Event test_date) {
	string date_current = "01.01.2023";
	if (test_date.setDate(date_current) == 0) {
		cerr << "Positive test " << date_current << " passed" << endl;
	}
	else {
		cerr << "Positive test" << date_current << " failed" << endl;
	}
	date_current = "32.01.2023";
	if (test_date.setDate(date_current) == -1) {
		cerr << "Negative test" << date_current << " passed" << endl;
	}
	else {
		cerr << "Negative test" << date_current << " failed" << endl;
	}
	date_current = "31.13.2023";
	if (test_date.setDate(date_current) == -1) {
		cerr << "Negative test" << date_current << " passed" << endl;
	}
	else {
		cerr << "Negative test" << date_current << " failed" << endl;
	}
}

void testEventLibraryName(Library test_name) {
	string name_current = "BBD1";
	if (test_name.setNames(name_current) == 0) {
		cerr << "Positive test " << name_current << " passed" << endl;
	}
	else {
		cerr << "Positive test " << name_current << " failed" << endl;
	}
	name_current = "";
	if (test_name.setID(name_current) == -1) {
		cerr << "Negative test " << name_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << name_current << " failed" << endl;
	}
	name_current = " ";
	if (test_name.setID(name_current) == -1) {
		cerr << "Negative test " << name_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << name_current << " failed" << endl;
	}
}

int main(){
	Library test_id;
	Library test_names;
	Library test_readers;
	Event test_date;
	Event test_name;
	testLibraryID(test_id);
	testLibraryNames(test_names);
	testLibraryReaders(test_readers);
	testEventLibraryDate(test_date);
	testEventLibraryName(test_name);
	return 0;

}