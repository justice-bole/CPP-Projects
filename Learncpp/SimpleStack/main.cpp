#include <iostream>
#include <array>

class Stack
{
private:

    std::array<int, 10> m_data{};
    std::array<int, 10>::size_type m_size{};

public:
    void reset()
    {
        m_size = 0;
    }

    bool push(int x)
    {
        if(m_size == m_data.size())
            return false;

        m_data[m_size++] = x;

        return true;
    }

    int pop()
    {
        assert(m_size > 0 &&  "Can not pop empty stack!");
        return m_data[--m_size];
    }

    void print()
    {
        std::cout << "( ";
        for(std::array<int, 10>::size_type i {}; i < m_size; ++i)
        {
            std::cout << m_data[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();


    return 0;
}
