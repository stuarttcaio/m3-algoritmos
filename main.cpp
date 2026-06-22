#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int M, N, X;

    cout << "Quantidade de vetores (M): ";
    cin >> M;

    cout << "Tamanho dos vetores (N): ";
    cin >> N;

    cout << "Quantidade de execucoes (X): ";
    cin >> X;

    vector<vector<int>> vetores(M, vector<int>(N));

    // Melhor caso (ordenado)
    if (M >= 1) {
        for (int i = 0; i < N; i++)
            vetores[0][i] = i + 1;
    }

    // Pior caso (ordem inversa)
    if (M >= 2) {
        for (int i = 0; i < N; i++)
            vetores[1][i] = N - i;
    }

    // Vetores aleatórios
    srand(time(NULL));

    for (int i = 2; i < M; i++) {
        for (int j = 0; j < N; j++) {
            vetores[i][j] = rand() % 1000;
        }
    }

    // Exibir vetores
    for (int i = 0; i < M; i++) {
        cout << "\nVetor " << i + 1 << ": ";

        for (int j = 0; j < N; j++) {
            cout << vetores[i][j] << " ";
        }
    }

    return 0;
}