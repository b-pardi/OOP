#ifndef SNAKE_H_INCLUDE
#define SNAKE_H_INCLUDE

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>

// snake body object knows its position, and next/prev body part
// implementation akin to a doubly linked list
typedef struct Snake
{
    int x, y;
    Snake *next, *prev;
} Snake;

// deleteSnake deallocates space for each snake piece
// iterate down the snake with a cursor and deleting pieces individually until head is left
void deleteSnake(Snake **head)
{
    Snake *temp = *head;
    Snake *cursor;
    while (temp != NULL)
    {
        cursor = temp->next;
        delete temp;
        temp = cursor;
    }
    *head = NULL;
}

/**
 * @brief game class will hold details about the snake placement, as well as displaying screens for start/end game
 *
 * x/y start will contain the starting coordinates for the head of the snake when new game starts
 * x/y max contain the maximum x and y coordinates of the screen the graphics driver displays on
 * x/y incr hold how much to increment the snake each frame
 * score will show the score of the player (how many pieces of fruit it has eaten)
 *      - score will also correspond to the speed the snake is moving at to increase difficulty
 * size box represents how many pixels span one grid space
 * head will contain the head of the 'Snake' to reference all the other snake pieces
 *      - note the snake is essentially a doubly linked list
 */
class Game
{
    int x_start, y_start, x_max, y_max, x_incr, y_incr;
    int score, size_box;
    Snake *head;

public:
    // Game constructor to initialize game object
    Game(int x_start, int y_start, int size_box)
    {
        this->x_start = x_start;
        this->y_start = y_start;
        // functions from graphics.h to get max x and y coords for current graphics driver
        x_max = 1280;
        y_max = 720;
        x_incr = size_box;
        y_incr = size_box;
        score = 0;
        this->size_box = size_box;
        head = NULL;
    }

    // Game deconstructor only needs to call delete snake
    ~Game()
    {
        deleteSnake(&head);
    }

    void startGame();
    void endGame();
    void showInfo();
    int randomLocation(int, int);
};

// grow snake inserts a node between before head and reassigns next and prev
// first checks if any other parts exist, if not makes new node the head
void growSnake(Snake **head, int x, int y)
{
    Snake *s;
    s = new Snake;
    s->x = x;
    s->y = y;
    s->next = NULL;
    s->prev = NULL;

    // base case check if node being added is first node
    // if it is, make it the head
    if ((*head) == NULL)
    {
        *head = s;
    }
    else
    {
        s->next = (*head);
        (*head)->prev = s;
        (*head) = s;
    }
}

// random number generator to place fruit on the screen
// takes in upper and lower bounds for range of random numbers
// bounds determined by screen size (see x/y_max in Game constructor)
int Game::randomLocation(int l, int u)
{
    int loc = (rand() % (u - l + 1));
    return loc + l;
}

#endif // SNAKE_H_INCLUDE