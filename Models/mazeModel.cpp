#include "mazeModel.h"
#include <algorithm>







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
        
    }