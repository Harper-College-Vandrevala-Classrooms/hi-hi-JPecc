#include <iostream>
#include <cassert>

using namespace std;

int strcmp_case_insensitive(const char* s1, const char* s2) {
    char upper1[100];
    char upper2[100];
    
    int i = 0;
    for (i = 0; s1[i] != '\0' && i < 100; i++) {
        upper1[i] = toupper(s1[i]);
    }
    upper1[i] = '\0';

    for (i = 0; s2[i] != '\0' && i < 100; i++) {
        upper2[i] = toupper(s2[i]);
    }
    upper2[i] = '\0';

    return strcmp(upper1, upper2);
}

int main() {
    assert(strcmp_case_insensitive("hello", "hello") == 0);
    assert(strcmp_case_insensitive("hello", "HELLO") == 0);
    assert(strcmp_case_insensitive("hello", "world") < 0);
    assert(strcmp_case_insensitive("hi", "hello") > 0);
    assert(strcmp_case_insensitive("", "") == 0);
    assert(strcmp_case_insensitive("", "non-empty") < 0);
    assert(strcmp_case_insensitive("non-empty", "") > 0);
    assert(strcmp_case_insensitive("   ", "   ") == 0);
    assert(strcmp_case_insensitive("abc!@#", "ABC!@#") == 0);
    assert(strcmp_case_insensitive("This is a long string.", "this is a long string.") == 0);
    assert(strcmp_case_insensitive("A", "a") == 0);
    assert(strcmp_case_insensitive("abc", "abC") == 0);

    const int max_length = 100;
    char s1[max_length];
    char s2[max_length];

    cout << "Enter the first string: ";
    cin.getline(s1, max_length);

    cout << "Enter the second string: ";
    cin.getline(s2, max_length);

    int result = strcmp_case_insensitive(s1, s2);
    
    cout << "The comparison of " << s1 << " and " << s2 << " returns " << result << "." << endl;

    if (result < 0) {
        cout << s1 << " < " << s2 << endl;
    } else if (result == 0) {
        cout << s1 << " == " << s2 << endl;
    } else {
        cout << s1 << " > " << s2 << endl;
    }

    return 0;
}
