#include <iostream>
#include <array>
#include <vector>

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

inline bool isEdge(int row, int col, int num_rows, int num_cols)
{
    if((row <= 0) || (col <= 0) || (row >= num_rows-1) || (col >= num_cols-1))
        return true;
    else
        return false;
}

enum DIRECTION
{
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP, 
    DIR_DOWN,
    DIR_NONE
};

int validateEdgeConnection(int* pMatrix, int row, int col, int num_rows, int num_cols, enum DIRECTION from_dir)
{
    //cout << "validateNeighbours. (" << col << ":" << row << ")" << endl;
    int retval = 0;

    if(isEdge(row, col, num_rows, num_cols))
    {
        retval = pMatrix[row*num_cols+col];
    }
    else
    {
        // check only if current value is 1
        if(pMatrix[row*num_cols+col])
        {
            // Look left
            if((from_dir != DIR_LEFT) && pMatrix[row*num_cols+col-1])
            {
                retval |= validateEdgeConnection(pMatrix, row, col-1, num_rows, num_cols, DIR_RIGHT);
            }

            // Look right
            if((from_dir != DIR_RIGHT) && pMatrix[row*num_cols+col+1])
            {
                retval |= validateEdgeConnection(pMatrix, row, col+1, num_rows, num_cols, DIR_LEFT);
            }

            // Look down
            if((from_dir != DIR_DOWN) && pMatrix[(row-1)*num_cols+col])
            {
                retval |= validateEdgeConnection(pMatrix, row-1, col, num_rows, num_cols, DIR_UP);
            }

            // Lock up
            if((from_dir != DIR_UP) && pMatrix[(row+1)*num_cols+col])
            {
                retval |= validateEdgeConnection(pMatrix, row+1, col, num_rows, num_cols, DIR_DOWN);
            }
        }
    }

    return retval;
}

void findIsland(int* pMatrix, int num_rows, int num_cols)
{
    // itterate through input
    for(int row=0; row<num_rows; row++)
    {
        for(int col=0; col<num_cols; col++)
        {
            //cout << "(" << col << "/" << row << "): " << pInput[row*num_cols+col] << endl;
            if(!isEdge(row, col, num_rows, num_cols))
            {
                if(pMatrix[row*num_cols+col])
                {
                    pMatrix[row*num_cols+col] = validateEdgeConnection(pMatrix, row, col, num_rows, num_cols, DIR_NONE);
                }
            }

            
        }
    }
    
    return;
}

void print2dArray(int* pArray, int num_rows, int num_cols)
{
    for(int row=0; row<num_rows; row++)
    {
        for(int col=0; col<num_cols; col++)
        {
            if(col == 0)
                cout << "[";
            cout << pArray[row*num_cols+col];

            if(col == num_cols-1)
                cout << "]" << endl;
            else 
                cout << ",";
        }
    }
}

int main(void)
{
    int num_rows = sizeof(input)/sizeof(input[0]);
    int num_cols = sizeof(input[0])/sizeof(input[0][0]);

    cout << num_rows << " : " << num_cols << endl;
   
    cout << "input:" << endl;
    print2dArray((int*)input, num_rows, num_cols);

    memcpy(output, input, sizeof(input));

    findIsland((int*)output, num_rows, num_cols);

    cout << "output:" << endl;
    print2dArray((int*)output, num_rows, num_cols);

}