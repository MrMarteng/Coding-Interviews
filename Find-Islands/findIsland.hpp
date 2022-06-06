/**
 * @file findIsland.hpp
 * @author Martin Kiepfer (m.kiepfer@teleschirm.org)
 * @brief 
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

enum DIRECTION
{
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP, 
    DIR_DOWN,
    DIR_NONE
};

class findIsland
{
public:
    findIsland();

    void removeIslands(int* pMatrix, int num_rows, int num_cols);

    static void print2dArray(int* pArray, int num_rows, int num_cols);
    static bool compareMatrix(int* pM1, int* pM2, int num_rows, int num_cols);
    static void copyMatrix(int* pIn, int* pOut, int num_rows, int num_cols);

private: 
    bool isEdge(int row, int col, int num_rows, int num_cols);
    int validateEdgeConnection(int* pMatrix, int row, int col, int num_rows, int num_cols, enum DIRECTION from_dir);
};