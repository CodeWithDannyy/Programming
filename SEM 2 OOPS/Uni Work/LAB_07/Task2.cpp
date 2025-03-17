#include<iostream>
using namespace std;

class Shape
{
    int position;
    string color;
    float borderThickness;

    public:
    const float pi = 3.14;
    Shape(int position, string color, float borderThickness)
    : position(position), color(color), borderThickness(borderThickness) {}

    virtual void draw()
    {
        cout << "Drawing Shape..." << endl;
    }

    virtual void calculateArea()
    {
        cout << "Calculating Area" << endl;
    }

    virtual void calculatePerimeter()
    {
        cout << "Calculating Perimeter" << endl;
    }
};

class Circle : public Shape
{
    float radius;
    float centerPosition;

    public:
    Circle(int position, string color, float borderThickness, float radius, float centerPosition)
    : Shape(position, color, borderThickness), radius(radius), centerPosition(centerPosition) {}

    void draw()
    {
        cout << "Center Position : " << centerPosition << endl;
        cout << "Drawing Circle..." << endl;
    }

    void calculateArea()
    {
        float area = pi*(radius*radius);
        cout << "Area = " << area << endl;
    }

    void calculatePerimeter()
    {
        float perimeter = 2 * pi * radius;
        cout << "Perimeter = " << perimeter << endl;
    }

};

class Rectangle : public Shape
{
    float width,height,topLeftCornerPosition;

    public:
    Rectangle(int position, string color, float borderThickness, float width, float height, float topLeftCornerPosition)
    : Shape(position, color, borderThickness), width(width), height(height), topLeftCornerPosition(topLeftCornerPosition) {}

    void draw()
    {
        cout << "Top Left Corner Position : " << topLeftCornerPosition << endl;
        cout << "Drawing Rectangle..." << endl;
    }

    void calculateArea()
    {
        float area = width*height;
        cout << "Area = " << area << endl;
    }

    void calculatePerimeter()
    {
        float Perimeter = (width + height) * 2;
        cout << "Perimeter = " << Perimeter << endl;
    }
};

class Triangle : public Shape
{
    float base,height,side1,side2,side3;

    public:
    Triangle(int position, string color, float borderThickness, float base, float height, float side1, float side2, float side3)
    : Shape(position, color, borderThickness), base(base), height(height), side1(side1), side2(side2), side3(side3) {}

    void draw()
    {
        cout << "Drawing Triangle..." << endl;
    }

    void calculateArea()
    {
        float area = (0.5)*(base*height);
        cout << "Area = " << area << endl;
    }

    void calculatePerimeter()
    {
        float Perimeter = side1 + side2 + side3;
        cout << "Perimeter = " << Perimeter << endl;
    }
};

class Polygon : public Shape
{
    public:
    Polygon(int position, string color, float borderThickness)
    : Shape(position, color, borderThickness) {}

    void draw()
    {
        cout << "Drawing Polygon..." << endl;
    }

    void calculateArea()
    {
        cout << "Calculating Area of polygon" << endl;
    }

    void calculatePerimeter()
    {
        cout << "Calculating Perimeter of polygon" << endl;
    }

};

int main()
{
    Circle circle(5, "Red", 2.0, 10.0, 3.0);
    Rectangle rectangle(10, "Blue", 1.5, 6.0, 4.0, 2.0);
    Triangle triangle(15, "Green", 1.0, 5.0, 3.0, 4.0, 5.0, 6.0);
    Polygon polygon(20, "Yellow", 1.2);

    Shape* shapes[4] = { &circle, &rectangle, &triangle, &polygon};

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        shapes[i]->calculatePerimeter();
        cout << "----------------------" << endl;
    }

    return 0;
}