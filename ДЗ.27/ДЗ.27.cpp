#include <iostream>
using namespace std;

void printMatrix(int** matrix, size_t rows, size_t columns) 
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void deleteMatrix(int** matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        delete matrix[i];
    delete[] matrix;
}

// Задание 1. Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.

void insertColumn(int** matrix, size_t rows, size_t columns, size_t index)
{
    int** temp = new int*[rows];
    for (size_t i = 0; i < rows; i++)
        temp[i] = new int[columns + 1];

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < index; j++)
           temp[i][j] = matrix[i][j];

    for (size_t i = 0; i < rows; i++)
        temp[i][index] = 0;
   
    for (size_t i = 0; i < rows; i++)
        for (size_t j = index + 1; j <= columns; j++)
            temp[i][j] = matrix[i][j-1];
    
    for (size_t i = 0; i < rows; i++)
        delete matrix[i];
    delete[] matrix;
   
    for (size_t i = 0; i < rows; i++)
        matrix[i] = temp[i];      
    matrix = temp;
      
}

// Задание 2. Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

void DeleteColumn(int** matrix, size_t rows, size_t columns, size_t index)
{
    int** temp = new int* [rows];
    for (size_t i = 0; i < rows; i++)
        temp[i] = new int[columns - 1];

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < index; j++)
            temp[i][j] = matrix[i][j];

    for (size_t i = 0; i < rows; i++)
        for (size_t j = index + 1; j <= columns; j++)
            temp[i][j-1] = matrix[i][j];

    for (size_t i = 0; i < rows; i++)
        delete matrix[i];
    delete[] matrix;

    for (size_t i = 0; i < rows; i++)
        matrix[i] = temp[i];
    matrix = temp;

}

// Задание 3. Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать
// функцию, осуществляющую циклический сдвиг строк и / или столбцов массива указанное количество раз и в указанную сторону.

void ShiftColumn(int** matrix, size_t rows, size_t columns, size_t index, size_t step, size_t way)
{
    int temp;
    if (way == 0)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = index; j < index+step; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = temp;                 
            }           
         }   
    }  
    if (way == 1)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = index; j > index - step; j--)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][j - 1];
                matrix[i][j - 1] = temp;
            }
        }
    }
}

int main()
{
    size_t rows;
    cout << "Enter amount of rows in matrix: ";
    cin >> rows;
    size_t columns;
    cout << "Enter amount of columns in matrix: ";
    cin >> columns;   

    int** matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            cout << "Enter " << j << " element of " << i << " row: ";
            cin >> matrix[i][j];
        }
     
    printMatrix(matrix, rows, columns);
    // Задача 1.
    size_t index;
    cout << "Enter index for insertion column: ";
    cin >> index;    
    insertColumn(matrix, rows, columns, index-1);    
    printMatrix(matrix, rows, columns+1);
    // Задача 2.
    size_t index1;
    cout << "Enter index to delete column: ";
    cin >> index1;
    DeleteColumn(matrix, rows, columns, index1 - 1);
    printMatrix(matrix, rows, columns - 1);
    // Задача 3.
    size_t step;
    size_t way;
    cout << "Enter number of steps: ";
    cin >> step;
    cout << "Enter the way: Left - 1, Right - 0: ";
    cin >> way;
    size_t index2;
    cout << "Enter index shifted column: ";
    cin >> index2;

    ShiftColumn(matrix, rows, columns, index2-1, step, way);
    printMatrix(matrix, rows, columns);

    deleteMatrix(matrix, rows);

    return 0;
}

