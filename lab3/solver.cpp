#include "solver.h"
#include <iostream>
#include <cmath>

EquationSolver::EquationSolver() {}

// задаємо кінці відрізку
void EquationSolver::setRange(double l, double r) {
    left  = l;
    right = r;
}

// задаємо точність
void EquationSolver::setPrecision(double tolerance) {
    precision = tolerance;
}

// f(x) = x^2/4 + x - 1.2502  (варіант 2)
double EquationSolver::func(double x) {
    double result = (x * x) / 4.0 + x - 1.2502;
    return result;
}

// чисельна похідна методом скінченних різниць
double EquationSolver::derivative(double x) {
    double step = 1e-6;
    double result = (func(x + step) - func(x)) / step;
    return result;
}

// метод дихотомії (поділу відрізку навпіл)
void EquationSolver::bisection() {
    // перевірка: чи є розв'язок на проміжку
    if ((func(left) * func(right)) > 0) {
        std::cout << "No solution found on interval: ("
                  << left << " : " << right << ")" << std::endl;
        return;
    }

    double lo = left;
    double hi = right;

    // звужуємо відрізок, поки його довжина більша за точність
    while (std::abs(lo - hi) > precision) {
        double mid = (lo + hi) / 2.0;       // центр відрізку

        if ((func(lo) * func(mid)) < 0) {
            hi = mid;                        // розв'язок у лівій половині
        } else {
            lo = mid;                        // розв'язок у правій половині
        }
    }

    double answer = (lo + hi) / 2.0;
    std::cout << "[Bisection] x = " << answer << std::endl;
}

// метод Ньютона (дотичних)
void EquationSolver::newtonMethod() {
    double x = (left + right) / 2.0;        // початкове наближення — середина відрізку

    // ітеруємо, поки |f(x)| більше за задану точність
    while (std::abs(func(x)) > precision) {
        // перевірка на ділення на нуль
        if (std::abs(derivative(x)) < 1e-9) {
            std::cout << "Derivative is zero, stopping." << std::endl;
            std::cout << "[Newton] Last x = " << x << std::endl;
            return;
        }
        // формула Ньютона: x_{n+1} = x_n - f(x_n) / f'(x_n)
        x = x - func(x) / derivative(x);
    }

    std::cout << "[Newton] x = " << x << std::endl;
}

EquationSolver::~EquationSolver() {
    std::cout << "Object destroyed." << std::endl;
}

void run() {
    EquationSolver *solver = new EquationSolver(); //new виділяє пам'ять у heap (купі) і повертає адресу

    double l, r, tol;
    std::cout << "Enter interval (e.g. \"0 2\"): ";
    std::cin >> l >> r;
    std::cout << "Enter precision: ";
    std::cin >> tol;

    solver->setRange(l, r);
    solver->setPrecision(tol);
    solver->bisection();
    solver->newtonMethod();

    delete solver;
}