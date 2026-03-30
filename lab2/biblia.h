#pragma once
#include <string>

struct Point {
    double x, y;

    bool operator==(const Point &other) const;
};

struct Triangle {
    Point A, B, C;

    double perimeter() const;
    double area() const;
    bool isValid() const;
    bool contains(const Point &P) const;
    void checkPoint(const Point &P) const;

private:
    bool isOnEdge(const Point &P, const Point &p1, const Point &p2, const std::string &name) const;
};

double distance(const Point &A, const Point &B);
void run();