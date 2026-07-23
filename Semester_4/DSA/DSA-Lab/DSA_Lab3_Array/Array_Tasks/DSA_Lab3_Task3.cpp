// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

template <class T>
class Array {
    T* arr;
    int size;
    int n;

public:
    Array(int ssize) : n(0), size(ssize) {
        arr = new T[ssize];
    }

    void insert(T v) {
        if (n < size) {
            arr[n++] = v;
            cout << "Added to vocabulary.\n";
        }
        else {
            cout << "Array is Full. Can't add more elements...\n";
        }
    }

    int search(T v) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == v) { return i; }
        }
        return -1;
    }

    void display() {
        cout << "\n-----------------------------------\n";
        for (int i = 0; i < n; i++) {
            arr[i].display();
        }
        cout << "-----------------------------------\n";
    }

    void remove(T v) {
        int index = this->search(v);
        if (index == -1) {
            cout << "Word not found.\n";
            return;
        }
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "Word removed successfully.\n";
    }

    T& getIndex(int index) { return arr[index]; }

    ~Array() { delete[] arr; }
};

class Word {
    string word;
    string definition;
    string partOfSpeech;

    bool isEqual(string s1, string s2) const {
        if (s1.length() != s2.length()) return false;
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
            if (c2 >= 'A' && c2 <= 'Z') c2 += 32;
            if (c1 != c2) return false;
        }
        return true;
    }

public:
    Word() : word(""), definition(""), partOfSpeech("") {}

    Word(string w) : word(w), definition(""), partOfSpeech("") {}

    Word(string w, string d, string p) : word(w), definition(d), partOfSpeech(p) {}

    void display() {
        cout << "Word: " << word << " (" << partOfSpeech << ")\n";
        cout << "Def: " << definition << "\n\n";
    }

    bool operator == (const Word& other) {
        return isEqual(this->word, other.word);
    }

    friend ostream& operator << (ostream& out, const Word& w) {
        out << w.word;
        return out;
    }
};

int main() {
    Array<Word> vocab(15);
    int choice = 0;

    while (choice != 5) {
        cout << "1. Add Word\n2. Remove Word\n3. Search Word\n4. Display All\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string w, d, p;
            cout << "Word: "; cin >> w;

            if (vocab.search(Word(w)) != -1) {
                cout << "Word already in vocabulary\n";
            }
            else {
                cout << "Definition: "; cin >> d;
                cout << "Part of Speech: "; cin >> p;
                vocab.insert(Word(w, d, p));
            }
        }
        else if (choice == 2) {
            string w;
            cout << "Word to remove: "; cin >> w;
            vocab.remove(Word(w));
        }
        else if (choice == 3) {
            string w;
            cout << "Search: "; cin >> w;
            int idx = vocab.search(Word(w));
            if (idx != -1) {
                vocab.getIndex(idx).display();
            }
            else {
                cout << "Word not found.\n";
            }
        }
        else if (choice == 4) {
            vocab.display();
        }
    }

    return 0;
}