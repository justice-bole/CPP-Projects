#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string color, noun, celeb;

    cout << "Enter a color: ";
    getline(cin, color);
    cout<<"Enter a plural noun: ";
    getline(cin, noun);
    cout << "Name a celebrity: ";
    getline(cin, celeb);
    
    cout << "Roses are " << color <<endl;
    cout << noun << " are blue" <<endl;
    cout <<"I love " << celeb << endl;
}