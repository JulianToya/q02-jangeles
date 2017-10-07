/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}*/

TEST(PiezasTest, resetIsBlank)
{
  Piezas test;
  Piece result;

  test.dropPiece(2); 
  test.reset();
  result = test.pieceAt(0, 2);

  ASSERT_EQ(result, Blank);
}

TEST(PiezasTest, resetErased)
{
  Piezas test;
  Piece result1;
  Piece result2;

  result1 = test.dropPiece(2); 
  test.reset();
  result2 = test.pieceAt(0, 2);

  ASSERT_NE(result1, result2);
}

TEST(PiezasTest, dropCheckX)
{
  Piezas test;
  Piece result;

  result = test.dropPiece(2); 

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, dropCheckO)
{
  Piezas test;
  Piece result;

  test.dropPiece(2); 
  result = test.dropPiece(2);

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, dropFull)
{
  Piezas test;
  Piece result;

  test.dropPiece(2); 
  test.dropPiece(2);
  test.dropPiece(2);
  result = test.dropPiece(2);

  ASSERT_EQ(result, Blank);
}

TEST(PiezasTest, dropOutL)
{
  Piezas test;
  Piece result;

  result = test.dropPiece(-1); 

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, dropOutG)
{
  Piezas test;
  Piece result;

  result = test.dropPiece(BOARD_COLS); 

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtX) {
  Piezas test;
  Piece result;

  test.dropPiece(2);
  result = test.pieceAt(0, 2);

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, pieceAtO) {
  Piezas test;
  Piece result;

  test.dropPiece(1);
  test.dropPiece(1);
  result = test.pieceAt(1, 1);

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, pieceAtBlank) {
  Piezas test;
  Piece result;

  result = test.pieceAt(0, 2);

  ASSERT_EQ(result, Blank);
}
TEST(PiezasTest, pieceAtOutL1) {
  Piezas test;
  Piece result;

  result = test.pieceAt(-1, 1);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtOutL2) {
  Piezas test;
  Piece result;

  result = test.pieceAt(1, -1);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtOutLBoth) {
  Piezas test;
  Piece result;

  result = test.pieceAt(-1, -1);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtOutG1) {
  Piezas test;
  Piece result;

  result = test.pieceAt(BOARD_ROWS, 1);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtOutG2) {
  Piezas test;
  Piece result;

  result = test.pieceAt(1, BOARD_COLS);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAtOutGBoth) {
  Piezas test;
  Piece result;

  result = test.pieceAt(BOARD_ROWS, BOARD_COLS);

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, gameNotOver1) {
  Piezas test;
  Piece result;

  result = test.gameState();

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, gameNotOver2) {
  Piezas test;
  Piece result;

  test.dropPiece(0);
  result = test.gameState();

  ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, gameWinX) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_COLS; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);
      test.dropPiece(-1);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinO) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_COLS; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(-1);
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinXCol1) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(0);
    test.dropPiece(-1);
  }

  for(int i = 1; i < BOARD_COLS; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinXCol2) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(1);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 1) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinXCol3) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(2);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 2) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinXCol4) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(3);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 3) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinOCol1) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(-1);
    test.dropPiece(0);
  }

  for(int i = 1; i < BOARD_COLS; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinOCol2) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(-1);
    test.dropPiece(1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 1) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinOCol3) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(-1);
    test.dropPiece(2);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 2) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinOCol4) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_ROWS; ++i) {
    test.dropPiece(-1);
    test.dropPiece(3);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    if(i == 3) {
      continue;
    }

    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinXRow1) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_ROWS; ++i) {
    if(i == 0) {
      continue;
    }

    for(int j = 0; j < BOARD_COLS; ++j) {
      test.dropPiece(j);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinXRow2) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinXRow3) {
  Piezas test;
  Piece result;

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < BOARD_COLS; ++j) {
      test.dropPiece(j);  
    }
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
    test.dropPiece(-1);
  }

  result = test.gameState();

  ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameWinORow1) {
  Piezas test;
  Piece result;

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(-1);
    test.dropPiece(i);
  }

  for(int i = 0; i < BOARD_ROWS; ++i) {
    if(i == 0) {
      continue;
    }

    for(int j = 0; j < BOARD_COLS; ++j) {
      test.dropPiece(j);  
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinORow2) {
  Piezas test;
  Piece result;

  test.dropPiece(-1);

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
    test.dropPiece(-1);
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameWinORow3) {
  Piezas test;
  Piece result;

  test.dropPiece(-1);

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < BOARD_COLS; ++j) {
      test.dropPiece(j);  
    }
  }

  for(int i = 0; i < BOARD_COLS; ++i) {
    test.dropPiece(i);
    test.dropPiece(-1);
  }

  result = test.gameState();

  ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameTie) {
  Piezas test;
  Piece result;

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(i);
      test.dropPiece(-1);
    }
  }

  for(int i = 2; i < BOARD_COLS; ++i) {
    for(int j = 0; j < BOARD_ROWS; ++j) {
      test.dropPiece(-1);
      test.dropPiece(i);
    }
  }

  result = test.gameState();

  ASSERT_EQ(result, Blank);
}
