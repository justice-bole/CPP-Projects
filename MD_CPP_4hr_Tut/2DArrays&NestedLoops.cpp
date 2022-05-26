#include <iostream>
using namespace std;

int main()
{
    int numberGrid[3][2] = {        //2d array. 3 rows 2 columns. 0 based
                            {1,2}, 
                            {3,4},
                            {5,6}
                           };
    cout << numberGrid[2][0] << endl;

    for(int i = 0; i < 3; i++){ //for loop
        for(int j = 0; j <2; j++){  //nested for loop
            cout << numberGrid[i][j];
        }
        cout << endl;
    }

    return 0;
}