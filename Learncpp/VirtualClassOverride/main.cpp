#include <iostream>
#include <vector>

//2a) Create an abstract class named Shape. This class should have three functions:
// A: a pure virtual print function that takes and returns a std::ostream&,
// B: an overloaded operator<<
// C: and an empty virtual destructor.

class Point
{
private:
    int m_x{};
    int m_y{};

public:
    Point() = default;

    Point(int x, int y)
            : m_x{ x }, m_y{ y }
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }
};


class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0; // A
    friend std::ostream& operator<<(std::ostream& out, Shape& s) // B
    {
        return s.print(out);
    }
    virtual ~Shape() = default; // C
};

//2b) Derive two classes from Shape: a Triangle, and a Circle.
// The Triangle should have 3 Points as members.
// The Circle should have one center Point, and an integer radius.
// Overload the print() function to print the following
//Circle(Point(1, 2), radius 7)
//Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
class Triangle : public Shape
{
private:
    Point m_p1{};
    Point m_p2{};
    Point m_p3{};

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3) : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {

    }
    std::ostream& print(std::ostream& out) const override
    {
        std::cout << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
        return out;
    }
};

class Circle : public Shape
{
private:
    Point m_cp{};
    int m_radius;

public:
    Circle(Point p1, int r) : m_cp{p1}, m_radius{r}
    {

    }

    std::ostream& print(std::ostream& out) const override
    {
        std::cout << "Circle(" << m_cp << ", radius " << m_radius << ')';
        return out;
    }

    int getRadius() const
    {
        return m_radius;
    }

};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{ 0 };

    // Loop through all the shapes in the vector
    for (const auto* element : v)
    {
        // // Ensure the dynamic cast succeeds by checking for a null pointer result
        if (auto* c{ dynamic_cast<const Circle*>(element) })
        {
            largestRadius = std::max(largestRadius, c->getRadius());
        }
    }

    return largestRadius;
}

int main()
{
    std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for(const auto& i : v)
    {
        std::cout << *i << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    // delete each element in the vector here
    for(const auto& i : v)
    {
        delete i;
    }

    return 0;
}
