#include <iostream>
using namespace std;

//1
const int ROWS = 3;
const int COLS = 3;

void addColumn(int matrix[][COLS + 1], int position, int value) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = COLS; j > position; j--) 
        {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][position] = value;
    }
}

//2
void deleteColumn(int matrix[][COLS], int position) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = position; j < COLS - 1; j++) 
        {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
}

//3
const int M = 3; 
const int N = 3; 

void printMatrix(int matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftRows(int matrix[M][N], int shifts, bool left) {
    for (int i = 0; i < M; i++) {
        for (int s = 0; s < shifts; s++) {
            if (left) {
                int temp = matrix[i][0];
                for (int j = 0; j < N - 1; j++) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][N - 1] = temp;
            }
            else {
                int temp = matrix[i][N - 1];
                for (int j = N - 1; j > 0; j--) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = temp;
            }
        }
    }
}

void shiftColumns(int matrix[M][N], int shifts, bool up) {
    for (int s = 0; s < shifts; s++) {
        if (up) {
            int tempColumn[M];
            for (int i = 0; i < M; i++) {
                tempColumn[i] = matrix[i][0];
            }
            for (int j = 0; j < N - 1; j++) {
                for (int i = 0; i < M; i++) {
                    matrix[i][j] = matrix[i][j + 1];
                }
            }
            for (int i = 0; i < M; i++) {
                matrix[i][N - 1] = tempColumn[i];
            }
        }
        else {
            int tempColumn[M];
            for (int i = 0; i < M; i++) {
                tempColumn[i] = matrix[i][N - 1];
            }
            for (int j = N - 1; j > 0; j--) {
                for (int i = 0; i < M; i++) {
                    matrix[i][j] = matrix[i][j - 1];
                }
            }
            for (int i = 0; i < M; i++) {
                matrix[i][0] = tempColumn[i];
            }
        }
    }
}

//4
const int A = 3; 
const int B = 4; 

void transposeMatrix(int matrix[A][B]) {
    int transposedMatrix[B][A];

    for (int i = 0; i < B; i++) {
        for (int j = 0; j < A; j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    cout << "Transposed matrix:" << endl;
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < A; j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    //1
    /*int matrix[ROWS][COLS + 1] = { {1, 2, 3, 0},
                                   {4, 5, 6, 0},
                                   {7, 8, 9, 0} };

    int position = 1;
    int value = 10;

    addColumn(matrix, position, value);

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS + 1; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    //2
    //int matrix[ROWS][COLS] = { {1, 2, 3},
    //                           {4, 5, 6},
    //                           {7, 8, 9} };

    //int position = 1;

    //deleteColumn(matrix, position);

    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS - 1; j++) {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //3
    /*int matrix[M][N] = { {1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9} };

    int shifts = 2; 
    bool left = true; 
    bool up = true; 

    shiftRows(matrix, shifts, left);
    cout << "The matrix after cyclic shift of rows:" << endl;
    printMatrix(matrix);
    cout << endl;

    shiftColumns(matrix, shifts, up);
    cout << "The matrix after the cyclic shift of the columns:" << endl;
    printMatrix(matrix);*/

    //4
    /*int matrix[A][B] = { {1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12} };

    cout << "Matrix:" << endl;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    transposeMatrix(matrix);*/

    //5
    int size;
    cout << "Enter the number of contacts: ";
    cin >> size;

    string* names = new string[size];
    string* phones = new string[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter name " << i + 1 << " contact: ";
        cin >> names[i];
        cout << "Enter a phone number " << i + 1 << " conatct: ";
        cin >> phones[i];
    }

    string searchName;
    cout << "Enter a name to search: ";
    cin >> searchName;

    for (int i = 0; i < size; i++) {
        if (names[i] == searchName) {
            cout << "Phone number for " << searchName << ": " << phones[i] << endl;
            break;
        }
    }

    string searchPhone;
    cout << "Enter a phone number to search: ";
    cin >> searchPhone;

    for (int i = 0; i < size; i++) {
        if (phones[i] == searchPhone) {
            cout << "Name for the number " << searchPhone << ": " << names[i] << endl;
            break;
        }
    }

    delete[] names;
    delete[] phones;
}



