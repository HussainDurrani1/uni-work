// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	string author;
	string publisher;
	int isbn;
	string genre;
	string language;
	int publicationYear;
	int pageCount;
	bool availabilityStatus;
	int shelfNumber;

public:
	Book(string t, string a, string p, int i, string g, string l, int py, int pc, bool status, int sn) {
		title = t;
		author = a;
		publisher = p;
		isbn = i;
		genre = g;
		language = l;
		publicationYear = py;
		pageCount = pc;
		availabilityStatus = status;
		shelfNumber = sn;
	}

	void setTitle(string t) { title = t; }
	string getTitle() { return title; }

	void updateAvailability(bool status) { availabilityStatus = status; }
	bool isAvailable() { return availabilityStatus; }

	void displayDetails() {
		cout << "\n================ BOOK DETAILS ================\n";
		cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << endl;
		cout << "ISBN: " << isbn << "\nGenre: " << genre << "\nLanguage: " << language << endl;
		cout << "Year: " << publicationYear << "\nPages: " << pageCount << endl;
		cout << "Status: " << (availabilityStatus ? "Available" : "Issued") << endl;
		cout << "Shelf: " << shelfNumber << endl;
		cout << "==============================================\n";
	}
};

int main() {
	Book b("Python & AI", "Hussain Durrani", "Durrani's Production", 9988, "Education", "English", 2024, 600, true, 12);
	b.displayDetails();

	b.updateAvailability(false);
	cout << "\nStatus Updated to Issued...";
	b.displayDetails();

	return 0;
}