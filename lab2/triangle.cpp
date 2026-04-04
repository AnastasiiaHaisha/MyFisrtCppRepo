#include "triangle.h"
#include <iostream>
#include <cmath>

double distance(const Point &A, const Point &B) {
    return std::hypot(A.x - B.x, A.y - B.y);
}

bool Point::operator==(const Point &other) const {
    return distance(*this, other) < 1e-9;
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

bool Triangle::containsByArea(const Point &P) const {
    double S  = area();
    double S1 = Triangle{A, B, P}.area();
    double S2 = Triangle{B, C, P}.area();
    double S3 = Triangle{C, A, P}.area();
    return std::fabs(S - (S1 + S2 + S3)) < 1e-9;
}

bool Triangle::containsByVector(const Point &P) const {
    auto cross = [](const Point &O, const Point &X, const Point &Y) {
        return (X.x - O.x) * (Y.y - O.y) -
               (X.y - O.y) * (Y.x - O.x);
    };
    double d1 = cross(A, B, P);
    double d2 = cross(B, C, P);
    double d3 = cross(C, A, P);

    bool has_neg = (d1 < -1e-9) || (d2 < -1e-9) || (d3 < -1e-9);
    bool has_pos = (d1 >  1e-9) || (d2 >  1e-9) || (d3 >  1e-9);

    return !(has_neg && has_pos);
}

bool Triangle::isPointOnEdge(const Point &P,
                              const Point &p1, const Point &p2,
                              const std::string &name) const {
    double cross = (P.x - p1.x) * (p2.y - p1.y) -
                   (P.y - p1.y) * (p2.x - p1.x);
    if (std::fabs(cross) > 1e-9) return false;

    double dot  = (P.x - p1.x) * (p2.x - p1.x) +
                  (P.y - p1.y) * (p2.y - p1.y);
    double len2 = (p2.x - p1.x) * (p2.x - p1.x) +
                  (p2.y - p1.y) * (p2.y - p1.y);

    return dot >= -1e-9 && dot <= len2 + 1e-9;
}

std::string Triangle::whichEdge(const Point &P) const {
    if (isPointOnEdge(P, A, B, "AB")) return "AB";
    if (isPointOnEdge(P, B, C, "BC")) return "BC";
    if (isPointOnEdge(P, C, A, "CA")) return "CA";
    return "";
}

void Triangle::checkPointDegenerate(const Point &P) const {
    if (P == A) { std::cout << "  The point coincides with vertex A\n"; return; }
    if (P == B) { std::cout << "  The point coincides with vertex B\n"; return; }
    if (P == C) { std::cout << "  The point coincides with vertex C\n"; return; }

    std::string edge = whichEdge(P);

    std::cout << "  Method 1 (area decomposition): ";
    if (!edge.empty()) std::cout << "on edge " << edge << "\n";
    else               std::cout << "outside\n";

    std::cout << "  Method 2 (vector/cross product): ";
    if (!edge.empty()) std::cout << "on edge " << edge << "\n";
    else               std::cout << "outside\n";

    std::cout << "  Both methods agree.\n";
}

void Triangle::checkPoint(const Point &P) const {
    if (P == A) { std::cout << "  The point coincides with vertex A\n"; return; }
    if (P == B) { std::cout << "  The point coincides with vertex B\n"; return; }
    if (P == C) { std::cout << "  The point coincides with vertex C\n"; return; }

    bool byArea = containsByArea(P);
    bool byVec  = containsByVector(P);
    std::string edge = whichEdge(P);

    std::cout << "  Method 1 (area decomposition): ";
    if (byArea) {
        if (!edge.empty()) std::cout << "on edge " << edge << "\n";
        else               std::cout << "strictly inside\n";
    } else {
        std::cout << "outside\n";
    }

    std::cout << "  Method 2 (vector/cross product): ";
    if (byVec) {
        if (!edge.empty()) std::cout << "on edge " << edge << "\n";
        else               std::cout << "strictly inside\n";
    } else {
        std::cout << "outside\n";
    }

    if (byArea == byVec)
        std::cout << "  Both methods agree.\n";
    else
        std::cout << "  WARNING: methods disagree!\n";
}

static Triangle readTriangle(bool &degenerate) {
    Triangle t;
    std::cout << "\nEnter triangle vertices:\n";
    std::cout << "  A (x y): "; std::cin >> t.A.x >> t.A.y;
    std::cout << "  B (x y): "; std::cin >> t.B.x >> t.B.y;
    std::cout << "  C (x y): "; std::cin >> t.C.x >> t.C.y;

    degenerate = !t.hasArea();
    return t;
}

void run() {
    bool degenerate = false;
    Triangle ABC = readTriangle(degenerate);

    if (!degenerate) {
        std::cout << "\nTriangle info:\n";
        std::cout << "  Area      : " << ABC.area()      << "\n";
        std::cout << "  Perimeter : " << ABC.perimeter() << "\n";
    } else {
        std::cout << "\n  Degenerate triangle: points are collinear.\n";
        std::cout << "  Perimeter (sum of segment lengths): " << ABC.perimeter() << "\n";
    }

    int n;
    std::cout << "\nHow many points to check? ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        Point P;
        std::cout << "\nPoint #" << i << " (x y): ";
        std::cin >> P.x >> P.y;

        if (degenerate)
            ABC.checkPointDegenerate(P);
        else
            ABC.checkPoint(P);
    }
}