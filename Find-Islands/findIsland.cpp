/**
 * @file findIsland.cpp
 * @author Martin Kiepfer (m.kiepfer@teleschirm.org)
 * @brief 
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "findIsland.hpp"


findIsland::findIsland()
{

}

inline bool findIsland::isEdge(int row, int col, int num_rows, int num_cols)
{
    if((row <= 0) || (col <= 0) || (row >= num_rows-1) || (col >= num_cols-1))
        return true;
    else
        return false;
}

bool findIsland::compareMatrix(int* pM1, int* pM2, int num_rows, int num_cols)
{
    bool retval = true;
    for(int i=0; (i<(num_rows*num_cols)) && (retval); i++)
    {
        if(pM1[i] != pM2[i])
        {
            retval = false;
            std::cout << "XX: " << i << std::endl;
        }
    }

    return retval;
}

void findIsland::copyMatrix(int* pIn, int* pOut, int num_rows, int num_cols)
{
    memcpy(pOut, pIn, num_cols*num_rows*sizeof(pIn[0]));
}

void findIsland::removeIslands(int* pMatrix, int num_rows, int num_cols)
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

int findIsland::validateEdgeConnection(int* pMatrix, int row, int col, int num_rows, int num_cols, enum DIRECTION from_dir)
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

void findIsland::print2dArray(int* pArray, int num_rows, int num_cols)
{
    for(int row=0; row<num_rows; row++)
    {
        for(int col=0; col<num_cols; col++)
        {
            if(col == 0)
                std::cout << "[";
            std::cout << pArray[row*num_cols+col];

            if(col == num_cols-1)
                std::cout << "]" << std::endl;
            else 
                std::cout << ",";
        }
    }
}