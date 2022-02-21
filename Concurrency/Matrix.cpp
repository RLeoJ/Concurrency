#include <iostream>
#include <thread>
#include <vector>

using std::cout;
using std::endl;


//matrix A
const int r1 = 2, c1 = 2;
int m1[r1][c1] = { {1,2},{3,4} };

//matrix B
const int r2 = 2, c2 = 2;
int m2[r2][c2] = { {5,6},{7,8} };

//Resultant Matrix
int res[r1][c2];
int sum = 0;

void matrixCalc(int i, int k, int j) {
    sum += (m1[i][k] * m2[k][j]);
}

void threadMatrix() {
    std::vector<std::thread> threads;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            sum = 0;
            for (int k = 0; k < r2; k++) {
                std::thread t1(matrixCalc, i, k, j);
                threads.emplace_back(std::move(t1));
                //matrixCalc(i,k,j); //regular function call
            }
            res[i][j] = sum;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }

    for (auto& entry : threads)
        entry.join();
}
    
int main() {
    threadMatrix();

    return 0;
}
