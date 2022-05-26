#include <iostream>

using namespace std;

int main()
{
    string phrase = "Phrase Test";
    cout << phrase.length() << endl;
    cout << phrase[2] << endl; //index position starting at 0
    phrase[0] = 'B'; //changes char at designated index to designated char
    cout << phrase << endl;
    cout << phrase.find("Test", 0) << endl;
    cout << phrase.substr(8, 3);
    cout << "Hello\n";
}

int main()