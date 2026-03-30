#include "biblia.h"
#include <iostream>
#include <cmath>
#include <algorithm>

bool Point::operator==(const Point &other) const {
    return std::hypot(x - other.x, y - other.y) < 1e-9;
}

double distance(const Point &A, const Point &B) {
    return std::hypot(A.x - B.x, A.y - B.y);
}

double Triangle::perimeter() const {
    return distance(A, B) + distance(B, C) + distance(C, A);
}

double Triangle::area() const {
    return 0.5 * std::fabs((B.x - A.x) * (C.y - A.y) -
                            (C.x - A.x) * (B.y - A.y));
}

bool Triangle::hasArea() const {
    return area() > 1e-9;
}

bool Triangle::contains(const Point &P) const {
    double S = area();
    double S1 = Triangle{A, B, P}.area();
    double S2 = Triangle{B, C, P}.area();
    double S3 = Triangle{C, A, P}.area();
    return std::fabs(S - (S1 + S2 + S3)) < 1e-9;
}

bool Triangle::isPointOnEdge(const Point &P,
                         const Point &p1, const Point &p2,
                         const std::string &name) const {
    double cross = (P.x - p1.x) * (p2.y - p1.y) -
                   (P.y - p1.y) * (p2.x - p1.x);
    if (std::fabs(cross) > 1e-9) return false;

    double dot = (P.x - p1.x) * (p2.x - p1.x) +
                 (P.y - p1.y) * (p2.y - p1.y);
    double len2 = (p2.x - p1.x) * (p2.x - p1.x) +
                  (p2.y - p1.y) * (p2.y - p1.y);

    if (dot >= -1e-9 && dot <= len2 + 1e-9) {
        std::cout << "  The point is on edge " << name << "\n";
        return true;
    }
    return false;
}

void Triangle::checkPoint(const Point &P) const {
    if (P == A) { std::cout << "  The point coincides with vertex A\n"; return; }
    if (P == B) { std::cout << "  The point coincides with vertex B\n"; return; }
    if (P == C) { std::cout << "  The point coincides with vertex C\n"; return; }

    if (contains(P)) {
        if (isPointOnEdge(P, A, B, "AB")) return;
        if (isPointOnEdge(P, B, C, "BC")) return;
        if (isPointOnEdge(P, C, A, "CA")) return;
        std::cout << "  The point is strictly inside the triangle\n";
    } else {
        std::cout << "  The point is outside the triangle\n";
    }
}

static Triangle readTriangle() {
    Triangle t;
    while (true) {
        std::cout << "\nEnter triangle vertices:\n";
        std::cout << "  A (x y): "; std::cin >> t.A.x >> t.A.y;
        std::cout << "  B (x y): "; std::cin >> t.B.x >> t.B.y;
        std::cout << "  C (x y): "; std::cin >> t.C.x >> t.C.y;

        if (t.hasArea()) break;
        std::cout << "  Degenerate triangle — points are collinear. Try again.\n";
    }
    return t;
}

void run() {
    Triangle ABC = readTriangle();

    std::cout << "\nTriangle info:\n";
    std::cout << "  Area      : " << ABC.area()      << "\n";
    std::cout << "  Perimeter : " << ABC.perimeter() << "\n";

    int n;
    std::cout << "\nHow many points to check? "; std::cin >> n;

    for (int i = 1; i <= n; i++) {
        Point P;
        std::cout << "\nPoint #" << i << " (x y): "; std::cin >> P.x >> P.y;
        ABC.checkPoint(P);
    }
}