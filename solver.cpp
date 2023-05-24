#include <coin/ClpSimplex.hpp>  // Include COIN-OR header for Clp solver

// Objective function
double f(double x) {
    // Define your objective function here
    return -x * x;  // Example: maximizing a quadratic function
}

int main() {
    // Create Clp solver instance
    ClpSimplex solver;

    // Set optimization direction to maximize
    solver.setOptimizationDirection(1);

    // Define variable x
    double xLowerBound = 0.0;
    double xUpperBound = 1.0;
    double xInitialGuess = 0.5;

    // Add variable x to the solver
    int xIndex = solver.addCol();
    solver.setColBounds(xIndex, xLowerBound, xUpperBound);
    solver.setColSolution(xIndex, xInitialGuess);

    // Set objective function
    solver.setObjectiveCoefficient(xIndex, 1.0);

    // Solve the optimization problem
    solver.initialSolve();

    // Get optimal solution and objective function value
    double optimalX = solver.getColSolution()[xIndex];
    double optimalValue = solver.getObjValue();

    // Print the results
    std::cout << "Optimal Solution: x = " << optimalX << std::endl;
    std::cout << "Optimal Value: " << optimalValue << std::endl;

    return 0;
}
