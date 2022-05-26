#include <iostream>

using namespace std;

int main()
{
    bool isMale = false;
    bool isTall = false;

    if(isMale && isTall){
        cout << "Your are a tall male\n";
    }
    else if(isMale && !isTall){
        cout << "You are a short male\n";
    }
    else if(!isMale && isTall){
        cout << "You are a tall female\n";
    }
    else{
        cout << "You are a short female\n";
    }

    return 0;
}