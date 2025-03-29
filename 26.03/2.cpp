#include <iostream>
using namespace std;

void findMaxMin(int** matrix, int N, int M, int& maxUpper, int& minLower) {

    maxUpper = matrix[0][M / 2];
    for (int i = 0; i < N / 2; ++i) {
        for (int j = M / 2; j < M; ++j) {
            if (matrix[i][j] > maxUpper) {
                maxUpper = matrix[i][j];
            }
        }
    }

    minLower = matrix[N / 2][0];
    for (int i = N / 2; i < N; ++i) {
        for (int j = 0; j < M / 2; ++j) {
            if (matrix[i][j] < minLower) {
                minLower = matrix[i][j];
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxUpper, minLower;
    findMaxMin(matrix, N, M, maxUpper, minLower);

    cout << "Максимум в верхней правой четверти: " << maxUpper << endl;
    cout << "Минимум в нижней левой четверти: " << minLower << endl;

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
