#include <iostream>

using namespace std;

void sayHi(string name, int age)
{
    cout << "Hello " << name << " you are " << age << endl;
}

int main()
{
    sayHi("Justice", 26);
    sayHi("Mary", 25);
    sayHi("Sage", 0);
    sayHi("Arthur", 0);

    return 0;
}