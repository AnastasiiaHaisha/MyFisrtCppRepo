#ifndef SOLVER_H
#define SOLVER_H

class EquationSolver {
    public:
        EquationSolver(void);
        ~EquationSolver(void); //деструктор класу
        //Деструктор викликається автоматично коли об'єкт знищується
        
        void setRange(double left, double right);
        void setPrecision(double tolerance);
        // методи розв'язання
        void bisection();
        void newtonMethod();
        double func(double x);
        double derivative(double x);
    private:
        double left;
        double right;
        double precision;
};

void run();

#endif