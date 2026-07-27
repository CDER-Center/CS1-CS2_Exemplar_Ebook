#include <iostream>
#include <vector>
#include <fstream>
#include <omp.h>

using namespace std;

const int EMPTY = 0;
const int HUMAN = 1;
const int ZOMBIE = 2;

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: could not open file." << endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;

    vector<vector<int>> currentGrid(rows, vector<int>(cols));
    vector<vector<int>> nextGrid(rows, vector<int>(cols));

    int initialHumans = 0;
    int initialZombies = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> currentGrid[i][j];

            if (currentGrid[i][j] == HUMAN) {
                initialHumans++;
            } else if (currentGrid[i][j] == ZOMBIE) {
                initialZombies++;
            }
        }
    }

    inputFile.close();

    int humanCount = initialHumans;
    int maxSteps = 1000;
    int step = 0;

    double startTime = omp_get_wtime();

    while (humanCount > 0 && step < maxSteps) {
        nextGrid = currentGrid;

        #pragma omp parallel for collapse(2)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (currentGrid[i][j] == ZOMBIE) {
                    if (i > 0 && currentGrid[i - 1][j] == HUMAN)
                        nextGrid[i - 1][j] = ZOMBIE;

                    if (i < rows - 1 && currentGrid[i + 1][j] == HUMAN)
                        nextGrid[i + 1][j] = ZOMBIE;

                    if (j > 0 && currentGrid[i][j - 1] == HUMAN)
                        nextGrid[i][j - 1] = ZOMBIE;

                    if (j < cols - 1 && currentGrid[i][j + 1] == HUMAN)
                        nextGrid[i][j + 1] = ZOMBIE;
                }
            }
        }

        humanCount = 0;

        #pragma omp parallel for collapse(2) reduction(+:humanCount)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (nextGrid[i][j] == HUMAN) {
                    humanCount++;
                }
            }
        }

        currentGrid.swap(nextGrid);
        step++;
    }

    double endTime = omp_get_wtime();

    cout << "Grid size: " << rows << " x " << cols << endl;
    cout << "Initial humans: " << initialHumans << endl;
    cout << "Initial zombies: " << initialZombies << endl;
    cout << "Threads used: " << omp_get_max_threads() << endl;
    cout << "Total steps: " << step << endl;
    cout << "Remaining humans: " << humanCount << endl;
    cout << "Runtime: " << endTime - startTime << " seconds" << endl;

    return 0;
}


/*
bash compile
g++ zombie.cpp -fopenmp -o zombie

submission: 
OMP_NUM_THREADS=4 ./zombie
*/