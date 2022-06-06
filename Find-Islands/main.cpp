#include <iostream>
#include <array>
#include <vector>
#include "gtest/gtest.h"
#include "findIsland.hpp"

using namespace std;

/*
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
*/

// The fixture for testing class Foo.
class IslandTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  IslandTest() {
     // You can do set-up work for each test here.
  }

  ~IslandTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
private:
  findIsland    m_find;

public:
    void removeIslands(int* pMatrix, int num_rows, int num_cols)
    {
        m_find.removeIslands(pMatrix, num_rows, num_cols);
    }

};

int input1[6][6] =
{
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 1, 0},
    {1, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 1},
};
int expect1[6][6] = 
{
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 0},
    {1, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1},
};

int input2[6][7] =
{
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 0},
};
int expect2[6][7] = 
{
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 0},
};

int input3[10][10] =
{
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1}
};

int expect3[10][10] =
{
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 0}, 
    {0, 1, 1, 1, 0, 1, 1, 0, 1, 1}, 
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0}, 
    {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}, 
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 0}, 
    {1, 1, 1, 0, 0, 1, 0, 0, 0, 0}, 
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1} 
};


// Tests that the Foo::Bar() method does Abc.
TEST_F(IslandTest, removeIsland) {
    
    int* pOutput;
    int num_rows;
    int num_cols;
    findIsland f;

    // Test input 1
    num_rows = sizeof(input1)/sizeof(input1[0]);
    num_cols = sizeof(input1[0])/sizeof(input1[0][0]);
    pOutput = (int*)malloc(num_cols*num_rows*sizeof(int));
    findIsland::copyMatrix((int*)input1, (int*)pOutput, num_rows, num_cols);
    f.removeIslands((int*)pOutput, num_rows, num_cols);
    EXPECT_EQ(findIsland::compareMatrix((int*)expect1, pOutput, num_rows, num_cols), true);
    free(pOutput);

    // Test input 2
    num_rows = sizeof(input2)/sizeof(input2[0]);
    num_cols = sizeof(input2[0])/sizeof(input2[0][0]);
    pOutput = (int*)malloc(num_cols*num_rows*sizeof(int));
    findIsland::copyMatrix((int*)input2, pOutput, num_rows, num_cols);
    f.removeIslands(pOutput, num_rows, num_cols);
    EXPECT_EQ(findIsland::compareMatrix((int*)expect2, pOutput, num_rows, num_cols), true);
    free(pOutput);

    // Test input 3
    num_rows = sizeof(input3)/sizeof(input3[0]);
    num_cols = sizeof(input3[0])/sizeof(input3[0][0]);
    pOutput = (int*)malloc(num_cols*num_rows*sizeof(int));
    findIsland::copyMatrix((int*)input3, pOutput, num_rows, num_cols);
    f.removeIslands(pOutput, num_rows, num_cols);
    EXPECT_EQ(findIsland::compareMatrix((int*)expect3, pOutput, num_rows, num_cols), true);
    free(pOutput);
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}