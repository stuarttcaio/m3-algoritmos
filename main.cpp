#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(vector<int>& v);

int main() {
    int M, N, X;

    cout << "Quantidade de vetores (M): ";
    cin >> M;

    cout << "Tamanho dos vetores (N): ";
    cin >> N;

    cout << "Quantidade de execucoes (X): ";
    cin >> X;

    vector<vector<int>> vetores(M, vector<int>(N));

    if (M >= 1) {
        for (int i = 0; i < N; i++)
            vetores[0][i] = i + 1;
    }

    if (M >= 2) {
        for (int i = 0; i < N; i++)
            vetores[1][i] = N - i;
    }

    srand(time(NULL));

    for (int i = 2; i < M; i++) {
        for (int j = 0; j < N; j++) {
            vetores[i][j] = rand() % 1000;
        }
    }

    cout << "\nAntes da ordenacao:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << vetores[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        insertionSort(vetores[i]);
    }

    cout << "\nDepois da ordenacao:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << vetores[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void insertionSort(vector<int>& v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}