#include "mazeModel.h"
#include <algorithm>
#include <cstdlib> // for rand() 






MazeModel::MazeModel(int rows, int cols)
    : modelRows(rows),
      modelCols(cols),
      modelNumCells(rows * cols),
      modelUnionFind(rows * cols),
      topWalls(rows * cols, true),
      rightWalls(rows * cols, true),
      bottomWalls(rows * cols, true),
      leftWalls(rows * cols, true),
      nextWallIndex(0),
      finished(false) {

    allPresentWalls();
    shuffleWalls();
    updateFinishedStatus();

      }

    void MazeModel::shuffleWalls(){
    walls.clear();

    walls.reserve((modelRows * (modelCols - 1)) + ((modelRows - 1) * modelCols));

    for (int row = 0; row < modelRows; ++row) {
        for (int col = 0; col < modelCols -1; ++col) {
            Wall wall;
            wall.cell1 = index(row, col);
            wall.cell2 = index(row, col + 1);
            walls.push_back(wall);
        }
    }
    }