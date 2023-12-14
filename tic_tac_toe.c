#include <stdio.h>
#include <string.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void system();

/// check win cindition function:
int checkwin()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }
    if (count == 9)
    {
        return 0;
    }
}

/// function for print board:
void printboard()
{

    system("cls");

    printf("\n\n===Tic Tac Toe===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
}

int main()
{

    printboard();
    system("COLOR 0A");
    int player = 1;

    /// infinty loop:
    while (1)
    {
        if (player % 2 == 0)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }

        char mark;
        if (player == 1)
        {
            mark = 'X';
        }
        else if (player == 2)
        {
            mark = 'O';
        }
        /// input player's choice:
        int input;
        printf("Enter a Number for player %d : ", player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("Invalid input");
        }
        else
        {
            board[input] = mark;
        }
        int result = checkwin();
        printboard();
        if (result == 1)
        {

            printf("Congratulation !!! Player %d win!!", player);
            break;
        }
        if (result == 0)
        {

            printf("Match Draw");
            break;
        }

        player++;
    }

    return 0;
}
