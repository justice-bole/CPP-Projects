#include <iostream>

class Average
{
private:
    std::int_least32_t m_sum{};
    std::int_least16_t m_nums{};

public:
    Average(const std::int_least32_t& sum = 0, const std::int_least16_t& nums = 0) : m_sum{sum}, m_nums{nums}
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const Average& average)
    {
        out << static_cast<double>(average.m_sum) / average.m_nums;
        return out;
    }

    Average& operator+=(int num)
    {
        m_sum += num;
        ++m_nums;
        return *this;
    }

};

class IntArray
{
private:
    int m_size{0};
    int* m_data{nullptr};

public:
    IntArray(int size) : m_size{size}
    {
        assert(size > 0 && "Array must be larger than zero");

        m_data = new int[size]{};
    }

    //deep copy
    IntArray(const IntArray& array) : m_size{array.m_size}
    {
        m_data = new int[m_size]{}; //allocate new array

        for(int i{0}; i < array.m_size; i++) //copy original into new
        {
            m_data[i] = array.m_data[i];
        }
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    friend std::ostream& operator<<(std::ostream& out, IntArray& array)
    {
        for(int i{0}; i < array.m_size; i++)
        {
            out << array.m_data[i] << ' ';
        }

        return out;
    }

    int& operator[](const int index)
    {
        assert(index >= 0);
        assert(index < m_size);
        return m_data[index];
    }

    IntArray& operator=(const IntArray& array)
    {
        if(this == &array)
            return *this;

        delete[] m_data;

        m_size = array.m_size;
        m_data = new int[m_size];

        for(int i{0}; i < array.m_size; ++i)
        {
            m_data[i] = array.m_data[i];
        }

        return *this;

    }

};

class FixedPoint2
{
private:
    int m_base{};
    int m_fraction{};
public:
    FixedPoint2(int base = 0, int fraction = 0) : m_base{base}, m_fraction{fraction}
    {
        if(m_base < 0 || m_fraction < 0)
        {
            if(m_base > 0)
                m_base = -m_base;

            if(m_fraction > 0)
                m_fraction = -m_fraction;
        }
    }

    operator double() const
    {
        return m_base + (static_cast<double>(m_fraction) / 100);
    }

    friend std::ostream& operator<<(std::ostream& out, FixedPoint2& fixedPoint)
    {
        out << static_cast<double>(fixedPoint);
        return out;
    }


};


IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{

}