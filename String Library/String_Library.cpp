#include <bits/stdc++.h>
#include "String_Library.h"
using namespace std;

int main() {

    stringLir s("Hello, I'm Muhammad Sakr a SWE in my room");
    
    cout << s.Length() << endl;    
    cout << s.countSpaces() << endl;     
    cout << s.tolower() << endl;     
    cout << s.toupper() << endl;     
    cout << s.countVowels() << endl;     
    cout << s.countWords() << endl;     
    cout << s.palindrome() << endl;     
    cout << s.removeChar('S') << endl;     
    cout << s.removeChar('M') << endl;     
    cout << s.removeChar('a') << endl;     
    cout << s.removeChar('r') << endl;     
    cout << s.reverse() << endl;     
    cout << s.substring("sakr") << endl;    // return false --> Sakr [S] is a small litter    
    cout << s.substring("Sakr") << endl;    // return true
    
    return 0;
}