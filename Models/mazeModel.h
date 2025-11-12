#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <vector>
#include "UnionFind.h"

class MazeModel {
    public: 
        struct Wall {
            int cell1;
            int cell2;
        };

        MazeModel(int rows, int cols);

        int rows() const {
            return modelRows;
        }
        int cols() const {
            return modelCols;
        }

    bool hasTopWall(int cellIndex) const;
    bool hasRightWall(int cellIndex) const;
    bool hasBottomWall(int cellIndex) const;
    bool hasLeftWall(int cellIndex) const;

    //looks at the next wall in the random list
    //if the cells are in different sets, i remove the wall and union them 
    void generateStep();


    // True when start (0) and end (rows*cols-1) are connected
    bool isFinished() const { 
        return finished; 
    }

    private:
    int modelRows;
    int modelCols;
    int modelNumCells;

    UnionFind modelUnionFind;

     // For each cell, we store whether each wall is present
    std::vector<bool> topWalls;
    std::vector<bool> rightWalls;
    std::vector<bool> bottomWalls;
    std::vector<bool> leftWalls;

    std::vector<Wall> walls; // List of all walls between cells
    std::size_t nextWallIndex; // Index of the next wall to consider
    bool finished;
  
    //some helpers
    int index(int row, int col) const {
        return row * modelCols + col;
    }
    void allPresentWalls(); // all walls present
    void shuffleWalls(); // randomize wall order
    void removeWallBetween(int cell1, int cell2);
    void updateFinishedStatus();
};
    #endif
    