#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {
    Stack<char> s(20);
    Queue<char> q(20);
    string word;
    bool isPalindrome = true;

    cout << "Enter word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        s.push(word[i]); 
        q.Enqueue(word[i]); 
    }

    // Temporary storage to display the outputs as per Sample Run
    string stackOutput = "";
    string queueOutput = "";
    string tempWord = word;

    cout << "Stack pops : ";
    for (int i = 0; i < tempWord.length(); i++) {
        char c = s.pop();
        stackOutput += c;
        cout << c << "  ";
    }

    cout << "\nQueue deq  : ";
    for (int i = 0; i < tempWord.length(); i++) {
        char c = q.Dequeue();
        queueOutput += c;
        cout << c << "  ";
    }

    // Comparison logic
    if (stackOutput != queueOutput) {
        isPalindrome = false;
    }

    cout << "\nResult: " << (isPalindrome ? "PALINDROME" : "NOT A PALINDROME") << endl;

    return 0;
}