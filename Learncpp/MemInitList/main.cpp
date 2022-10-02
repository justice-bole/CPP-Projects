#include <iostream>
#include <cstdint>

class RGBA
{
private:
    using color_type = std::uint8_t;

    color_type m_red{};
    color_type m_green{};
    color_type m_blue{};
    color_type m_alpha{};

public:
    RGBA(color_type r=0, color_type g=0, color_type b=0, color_type a=255) :
        m_red{r}, m_green{g}, m_blue{b}, m_alpha{a}
    {
    }

    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red)
            << " g=" << static_cast<int>(m_green)
            << " b=" << static_cast<int>(m_blue)
            << " a=" << static_cast<int>(m_alpha) << '\n';
    }

};

int main()
{
    RGBA teal{ 0, 127, 127 };
    teal.print();

    return 0;
}
