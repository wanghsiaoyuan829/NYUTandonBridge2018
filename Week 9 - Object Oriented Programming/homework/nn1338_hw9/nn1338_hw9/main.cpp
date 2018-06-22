//
//  main.cpp
//  nn1338_hw9
//
//  Created by NomNomNam on 6/19/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Initialize the world with 5 doodlebugs and 100 ants
const int INITIALBUGS = 5;
const int INITIALANTS = 100;

// Critters live in a world composed of a 20 × 20 grid of cells
const int WORLDSIZE = 20;
const int DOODLEBUG = 1;
const int ANT = 2;
const int ANTBREED = 3;
const int DOODLEBREED = 8;
const int DOODLESTARVE = 3;

class Organism;
class Doodlebug;
class Ant;

class World
{
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    // Constructor
    World();
    // Destructor
    ~World();
    // Methods
    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Display();
    void SimulateOneStep();
private:
    Organism* grid[WORLDSIZE][WORLDSIZE];
};

class Organism
{
    friend class World;
public:
    // Constructors
    Organism();
    Organism(World *world, int x, int y);
    // Destructor
    ~Organism();
    // Methods
    virtual void breed() =0;
    virtual void move() =0;
    virtual int getType() =0;
    virtual bool starve() =0;
protected:
    int x, y;
    bool moved;
    int breedTicks;
    World *world;
};

// Constructor Definition
World::World()
{
    // Initialize world to empty spaces
    int i, j;
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            grid[i][j] = NULL;
        }
    }
}

// Destructor Definition
World::~World()
{
    // Release any allocated memory
    int i, j;
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != NULL)
                delete (grid[i][j]);
        }
    }
}

// Member function definitions
Organism* World::getAt(int x, int y)
{
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
        return grid[x][y];
    return NULL;
}

// Method Definition of setAt
void World::setAt(int x, int y, Organism *org)
{
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
        grid[x][y] = org;
}

// Method definition of Display
void World::Display()
{
    int i, j;
    cout<<endl<<endl;
    for (j = 0; j < WORLDSIZE; j++) {
        for (i = 0; i < WORLDSIZE; i++) {
            if (grid[i][j] == NULL)
                cout<<".";
            else if (grid[i][j] -> getType() == ANT)
                cout<<"o";
            else
                cout<<"X";
        } // End of i for loop
        cout<<endl;
    } // End of j for loop
}

// Method definition of SimulateOneStep
void World::SimulateOneStep()
{
    int i, j;
    // First reset all organisms to not moved
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != NULL)
                grid[i][j] -> moved = false;
        }
    }
    // Loop through cells in order and move if it's a Doodlebug
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j] -> getType() == DOODLEBUG)) {
                if (grid[i][j] -> moved == false) {
                    grid[i][j] -> moved = true;
                    grid[i][j] -> move();
                }
            }
            
        }
    }
    // Loop through cells in order and move if it's an Ant
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j] -> getType() == ANT)) {
                if (grid[i][j] -> moved == false) {
                    grid[i][j] -> moved = true;
                    grid[i][j] -> move();
                }
            }
            
        }
    }
    // Loop through cells in order and check if should breed
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            // Kill off any doodlebugs that have not eaten recently
            if ((grid[i][j] != NULL) && (grid[i][j] -> getType() == DOODLEBUG)) {
                if (grid[i][j] -> starve()) {
                    delete (grid[i][j]);
                    grid[i][j] = NULL;
                }
            }
        }
    }
    // Loop through cells in order and check if should breed
    for (i = 0; i < WORLDSIZE; i++) {
        for (j = 0; j < WORLDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j] -> moved == true))
                grid[i][j] -> breed();
        }
    }
}

// Default constructor of Organism
Organism::Organism()
{
    world = NULL;
    moved = false;
    breedTicks = 0;
    x = 0;
    y = 0;
}

// Constructor with parameters
Organism:: Organism(World *wrld, int x, int y)
{
    this -> world = wrld;
    moved = false;
    breedTicks = 0;
    this -> x = x;
    this -> y = y;
    wrld -> setAt(x, y, this);
}

// Destructor
Organism::~Organism()
{
}

// Start with the Ant Class
class Ant : public Organism
{
    friend class World;
public:
    // Constructors
    Ant();
    Ant(World *world, int x, int y);
    // Methods
    void breed();
    void move();
    int getType();
    bool starve() { return false; }
};

// Default constructor
Ant::Ant() : Organism() {}

// Constructor with parameters
Ant::Ant(World *world, int x, int y) : Organism(world, x, y) {}

// Method definition of move
void Ant::move()
{
    // Pick random direction to move
    int dir = rand() % 4;
    // Try to move up, if not at an edge and empty spot
    if (dir == 0) {
        if ((y > 0) && (world -> getAt(x, y - 1) == NULL)) {
            world -> setAt(x, y - 1, world -> getAt(x, y));
            // Move to new spot
            world -> setAt(x, y, NULL);
            y--;
        }
    }
    // Try to move down
    else if (dir == 1) {
        if ((y < WORLDSIZE - 1) && (world -> getAt(x, y + 1) == NULL)) {
            world -> setAt(x, y + 1, world -> getAt(x, y));
            // Move to new spot
            world -> setAt(x, y, NULL);
            y++;
        }
    }
    // Try to move left
    else if (dir == 2) {
        if ((x > 0) && (world -> getAt(x - 1, y) == NULL)) {
            world -> setAt(x - 1, y, world -> getAt(x, y));
            // Move to new spot
            world -> setAt(x, y, NULL);
            x--;
        }
    }
    // Try to move right
    else {
        if ((x < WORLDSIZE - 1) && (world -> getAt(x + 1, y) == NULL)) {
            world -> setAt(x + 1, y, world -> getAt(x, y));
            // Move to new spot
            world -> setAt(x, y, NULL);
            x++;
        }
    }
}

// Method definition of getType
int Ant::getType() { return ANT; }

// Method definition of breed
void Ant::breed() {
    breedTicks++;
    if (breedTicks == ANTBREED) {
        breedTicks = 0;
        //Try to make a new ant either above, left, right, below
        if ((y > 0) && (world -> getAt(x, y - 1) == NULL))
            Ant *newAnt = new Ant(world, x, y - 1);
        else if ((y < WORLDSIZE - 1) && (world -> getAt(x, y + 1) == NULL))
            Ant *newAnt = new Ant(world, x, y + 1);
        else if ((x > 0) && (world -> getAt(x - 1, y) == NULL))
            Ant *newAnt = new Ant(world, x - 1, y);
        else if ((x < WORLDSIZE - 1) && (world -> getAt(x + 1, y) == NULL))
            Ant *newAnt = new Ant(world, x + 1, y);
    }
}

// Create a class Doodlebug
class Doodlebug : public Organism
{
    friend class World;
public:
    Doodlebug();
    Doodlebug(World *world, int x, int y);
    void breed();
    void move();
    int getType();
    bool starve();
private:
    int starveTicks;
};

// Default constructor
Doodlebug::Doodlebug() : Organism() { starveTicks = 0; }

// Constructor with parameters
Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world, x, y) { starveTicks = 0; }

// Member functions
void Doodlebug::move() {
    if ((y > 0) && (world -> getAt(x, y - 1) != NULL) &&
        (world -> getAt(x, y - 1) -> getType() == ANT)) {
        delete (world -> grid[x][y - 1]);
        world -> grid[x][y - 1] = this;
        world -> setAt(x, y, NULL);
        starveTicks = 0;
        y--;
        return;
    }
    else if ((y < WORLDSIZE - 1) && (world -> getAt(x, y + 1) != NULL) && (world -> getAt(x, y+1)) -> getType() == ANT) {
        delete (world -> grid[x][y + 1]);
        world -> grid[x][y + 1] = this;
        world -> setAt(x, y, NULL);
        starveTicks = 0;
        y++;
        return;
    }
    else if ((x > 0) && (world -> getAt(x - 1, y) != NULL) && (world -> getAt(x - 1, y) -> getType() == ANT)) {
        delete (world -> grid[x - 1][y]);
        world -> grid[x - 1][y] = this;
        world -> setAt(x, y, NULL);
        starveTicks = 0;
        x--;
        return;
    }
    else if ((x < WORLDSIZE - 1) && (world -> getAt(x + 1, y) != NULL) && (world -> getAt(x + 1, y) -> getType() == ANT)) {
        delete (world -> grid[x + 1][y]);
        world -> grid[x + 1][y] = this;
        world -> setAt(x, y, NULL);
        starveTicks = 0;
        x++;
        return;
    }
    int dir = rand() % 4;
    // Try to move up, if not at an edge and empty spot
    if (dir == 0) {
        if ((y > 0) && (world -> getAt(x, y - 1) == NULL)) {
            world -> setAt(x, y - 1, world -> getAt(x, y));
            // Move to new spot
            world -> setAt(x, y, NULL);
            y--;
        }
    }
    // Try to move down
    else if (dir == 1) {
        if ((y < WORLDSIZE - 1) && (world -> getAt(x, y + 1) == NULL)) {
            // Move to new spot
            world -> setAt(x, y + 1, world -> getAt(x, y));
            // Set current spot to empty
            world -> setAt(x, y, NULL);
            y++;
        }
    }
    // Try to move left
    else if (dir == 2) {
        if ((x > 0) && (world -> getAt(x - 1, y) == NULL)) {
            // Move to new spot
            world -> setAt(x - 1, y, world -> getAt(x, y));
            // Set current spot to empty
            world -> setAt(x, y, NULL);
            x--;
        }
    }
    // Try to move right
    else {
        if ((x < WORLDSIZE - 1) && (world -> getAt(x + 1, y) == NULL)) {
            // Move to new spot
            world -> setAt(x + 1, y, world -> getAt(x, y));
            // Set current spot to empty
            world -> setAt(x, y, NULL);
            x++;
        }
    }
    // Increment starve tick since didn't eat on this turn
    starveTicks++;
}

// Method definition of getType
int Doodlebug::getType() { return DOODLEBUG; }

// Method definition of breed
void Doodlebug::breed() {
    breedTicks++;
    if (breedTicks == DOODLEBREED) {
        breedTicks = 0;
        // Try to make a new adjacent ant (above, below, right, left)
        if ((y > 0) && (world -> getAt(x, y - 1) == NULL))
            Doodlebug *newDoodle = new Doodlebug(world, x, y - 1);
        else if ((y < WORLDSIZE - 1) && (world -> getAt(x, y + 1) == NULL))
            Doodlebug *newDoodle = new Doodlebug(world, x, y + 1);
        else if ((x > 0) && (world -> getAt(x - 1, y) == NULL))
            Doodlebug *newDoodle = new Doodlebug(world, x - 1, y);
        else if ((x < WORLDSIZE - 1) && (world -> getAt(x + 1, y) == NULL))
            Doodlebug *newDoodle = new Doodlebug(world, x + 1, y);
    }
}

// Method definition of starve
bool Doodlebug::starve() {
    // Starve if no food eaten in last DOODLESTARVE time ticks
    if (starveTicks > DOODLESTARVE)
        return true;
    else
        return false;
}

int main() {
    string s;
    // Seed random generator
    srand(time(NULL));
    World w;
    int antcount = 0;
    
    // Create 100 random ants
    while (antcount < INITIALBUGS) {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        
        // Only put ants in empty spot
        if (w.getAt(x, y) == NULL) {
            antcount++;
            Ant *a1 = new Ant(&w, x, y);
        }
    }
    
    // Randomly create 5 doodlebugs
    int doodlecount = 0;
    while (doodlecount < INITIALBUGS) {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        
        // Only put doodlebugs in empty spot
        if (w.getAt(x, y) == NULL) {
            doodlecount++;
            Doodlebug *d1 = new Doodlebug(&w, x, y);
        }
    }
    
    // Ends only when user cancels
    while (true) {
        w.Display();
        w.SimulateOneStep();
        cout<<endl<<"Please press 'enter' for the next step"<<endl;
        getline(cin, s);
    }
    
    return 0;
}
