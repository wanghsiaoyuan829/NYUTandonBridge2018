//
//  main.cpp
//  nn1338_hw9
//
//  Created by NomNomNam on 6/19/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

// Initialize the world with 5 doodlebugs and 100 ants
const int DOODLEBUGS_WORLD = 5;
const int ANTS_WORLD = 100;

// Critters live in a world composed of a 20 × 20 grid of cells
const int WORLD_SIZE = 20;

class Organism {
    
};
// Create a 2D predator-prey simulation of the world using ASCII characters: "o" for ant, "X" for doodlebug, "-" for empty space
// Create a class named Organism that encapsulates basic data common to both ants and doodlebugs
// Virtual function named 'move' that is defined in the derived classes of Ant and Doodlebug
// After each time step, prompt the user to press Enter to move to the next time step

// Only one critter may occupy a cell at a time.
// The grid is enclosed, so a critter is not allowed to move off the edges of the world.

// Ants (Move)
// Every time step, randomly try to move up, down, left, or right
// If the neighboring cell in the selected direction is occupied or would move the ant off the grid, then the ant stays in the current cell

// Ants (Breed)
// If an ant survives for three time steps, then at the end of the time step (that is; after moving) the ant will breed
// Create a new ant in an adjacent cell IF the cell is empty
// If Empty Cell is occupied then no breeding occurs
// After breeding, the ant cannot produce an offspring until three more time steps have elapsed

// Doodlebugs (Move)
// Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug will move to that cell and eat the ant
// Else, the doodlebug moves according to the same rules as the ant
// Doodlebugs cannot eat other doodlebugs or cannot move into the same cell as other doodlebugs
// Doodlebugs should move before ants move

// Doodlebugs (Starve)
// If a doodlebug has not eaten an ant within the last three time steps, then at the end of the third time step it will starve and be removed from the grid of cells


int main() {

    return 0;
}
