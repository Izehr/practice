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

void testLibraryNames(Library test_name) {
	string names_current = "BBD";
	if (test_name.setNames(names_current) == 0) {
		cerr << "Positive test " << names_current << " passed" << endl;
	}
	else {
		cerr << "Positive test " << names_current << " failed" << endl;
	}
	names_current = "";
	if (test_name.setID(names_current) == -1) {
		cerr << "Negative test " << names_current << " passed" << endl;
	}
	else {
		cerr << "Negative test " << names_current << " failed" << endl;
	}
	names_current = " ";
	if (test_name.setID(names_current) == -1) {
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

int main(){
	Library test_id;
	Library test_names;
	Library test_readers;
	testLibraryID(test_id);
	testLibraryNames(test_names);
	testLibraryReaders(test_readers);
	return 0;

}