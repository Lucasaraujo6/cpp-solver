#include <iostream>
#include <coin/CbcModel.hpp>

int main() {
    // Criar uma instância do modelo Cbc
    CbcModel model;

    // Definir o sentido da otimização (maximizar ou minimizar)
    model.setOptimizationDirection(1);  // 1 para maximizar, -1 para minimizar

    // Definir o número de variáveis de decisão
    int numVars = 2;

    // Adicionar as variáveis de decisão ao modelo
    for (int i = 0; i < numVars; i++) {
        model.addCol();
    }

    // Definir os limites das variáveis de decisão
    double lowerBound = 0.0;
    double upperBound = 1.0;
    for (int i = 0; i < numVars; i++) {
        model.setColBounds(i, lowerBound, upperBound);
    }

    // Definir os coeficientes da função objetivo
    double objCoeffs[] = {1.0, 2.0};  // Coeficientes para as duas variáveis de decisão
    model.setObjectiveCoefficients(numVars, objCoeffs);

    // Resolver o problema de otimização
    model.branchAndBound();

    // Obter a solução ótima
    double* solution = model.getColSolution();

    // Imprimir a solução
    for (int i = 0; i < numVars; i++) {
        std::cout << "Variável " << i << ": " << solution[i] << std::endl;
    }

    // Liberar memória
    delete[] solution;

    return 0;
}
