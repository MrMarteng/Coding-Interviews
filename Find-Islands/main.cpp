#include <iostream>
#include <array>
#include <vector>
#include "findIsland.hpp"

using namespace std;

int input[6][6] =
{
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 1, 0},
    {1, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 1},
};

int output[6][6] = {};

int main(void)
{
    int num_rows = sizeof(input)/sizeof(input[0]);
    int num_cols = sizeof(input[0])/sizeof(input[0][0]);
    findIsland f;

    cout << num_rows << " : " << num_cols << endl;
   
    cout << "input:" << endl;
    findIsland::print2dArray((int*)input, num_rows, num_cols);

    memcpy(output, input, sizeof(input));

    f.removeIslands((int*)output, num_rows, num_cols);

    cout << "output:" << endl;
    findIsland::print2dArray((int*)output, num_rows, num_cols);

}