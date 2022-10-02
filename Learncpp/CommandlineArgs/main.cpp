#include <iostream>

int main(int argc, char* argv[])
{
    if( argc == 1)
    {
        std::cout << "There is " << argc << " argument:\n";
    }
    else
    {
        std::cout << "There are " << argc << " arguments:\n";
    }

    for(int i{0}; i < argc; ++i)
    {
        std::cout << i << ' ' << argv[i] << '\n';
    }
    return 0;
}
