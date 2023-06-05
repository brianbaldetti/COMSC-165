//
//  main.cpp
//  TikTacToe
//
//  Created by brian on 6/25/22.
//  allows for two players to play a game of tic-tac-toe
//
#include <iostream>
using namespace std;

const int SIZE = 3;

//initializes functions
void displayBoard(const char[][SIZE], int);
void playerTurn(char[][SIZE], int, char);
bool game(const char[][SIZE], int);
bool winner(const char[][SIZE], int,  char);
bool canWin(const char[][SIZE], int);
void showWinner(const char[][SIZE], int);

int main()
{
    //creates board variables
    char board[SIZE][SIZE] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    
    //loop runs while no one wins
    do
    {
        //shows starting board
        displayBoard(board, SIZE);
        
        //gives player X turn
        playerTurn(board, SIZE, 'X');
        
        //shows board after turn
        displayBoard(board, SIZE);
        
        //if player X hasn't one player O goes
        if (!game(board, SIZE))
            playerTurn(board, SIZE, 'O');
        
    } while(!game(board, SIZE));
    
    displayBoard(board, SIZE);
    
    showWinner(board, SIZE);
    
    return 0;
}

//displays the contents of the game board
void displayBoard(const char board[][SIZE], int size)
{
    cout << "       Columns:\n";
    cout << "       0 1 2\n";
    
    for (int row = 0; row < size; row++)
    {
        cout << "Row " << row << ": ";
        for (int col = 0; col < size; col++)
        {
            cout << board[row][col] << " ";
        }
        
        cout << endl;
    }
}

//allows either player to make a turn on the board and validates input
void playerTurn(char board[][SIZE], int size, char input)
{
    //declares variables
    int row = -1, col = -1;
    bool available = false;
    
    //validates user input
    while (!available)
    {
        do
        {   cout << "Please enter a row and column seperated by a space: ";
            cin >> row >> col;
            
            if (row > 2 || row < 0 || col > 2 || col < 0)
                cout << "That is an invalid input try again.\n";
        
        } while (row > 2 || row < 0 || col > 2 || col < 0);
        
        if (board[row][col] != '*')
        {
            cout << "That spot is already taken. Try again.\n";
        }
        else
        {
            board[row][col] = input;
            available = true;
        }
    }
}

//determines if a player wins or can win by calling winner function and canwin function
bool game(const char board[][SIZE], int size)
{
    if (winner(board, size, 'X') || winner(board, size, 'O'))
        return true;
    else if (canWin(board, size))
        return false;
    else
        return true;
}

//checks if either player has won
bool winner(const char board[][SIZE], int size, char input)
{
    if (board[0][0] == input && board[0][1] == input && board[0][2] == input)
        return true;
    else if (board[1][0] == input && board[1][1] == input && board[1][2] == input)
        return true;
    else if (board[2][0] == input && board[2][1] == input && board[2][2] == input)
        return true;
    else if (board[0][0] == input && board[1][0] == input && board[2][0] == input)
        return true;
    else if (board[1][0] == input && board[1][1] == input && board[1][2] == input)
        return true;
    else if (board[2][0] == input && board[2][1] == input && board[2][2] == input)
        return true;
    else if (board[0][0] == input && board[1][1] == input && board[2][2] == input)
        return true;
    else if (board[0][2] == input && board[1][1] == input && board[2][0] == input)
        return true;
    else
        return false;
}

//checks if there is any more spots on the board open
bool canWin(const char board[][SIZE], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (board[row][col] == '*')
                return true;
        }
    }
    
    return false;
}

//displays the winner
void showWinner(const char board[][SIZE], int size)
{
    if (winner(board, size, 'X'))
        cout << "Player X wins!\n";
    else if (winner(board, size, 'O'))
        cout << "Player O wins!\n";
    else
        cout << "The game is a tie.\n";
}

