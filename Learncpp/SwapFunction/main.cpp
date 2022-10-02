#include <iostream>

void swap(int& a, int& b)
{
    int temp{a};
    a = b;
    b = temp;
}

int main() {
    int a{555};
    int b{2203};

    std::cout << "Before swap: \t a:" << a << " b:" << b << '\n';
    swap(a, b);
    std::cout << "After swap: \t a:" << a << " b:" << b << '\n';

    return 0;
}
