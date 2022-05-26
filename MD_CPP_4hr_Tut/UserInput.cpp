#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string name;
    
    cout << "Enter your name: ";
    getline(cin, name);\
    cout << "Hello, " << name << endl;

    int age;
    
    cout << "What is your age: ";
    cin >> age; //gets user input
    cout << "You are " << age << " years old" << endl;

    return 0;
}