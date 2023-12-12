#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0)); // Initialize random number generator.

    std::string moves[3] = {"Rock", "Paper", "Scissors"};

    while (true)
    {
        std::cout << "Enter your move (Rock, Paper, Scissors): ";
        std::string user_move;
        std::cin >> user_move;

        int random_num = rand() % 3; // Generate a random number between 0 and 2.
        std::string computer_move = moves[random_num];

        std::cout << "Computer chose: " << computer_move << std::endl;

        if (user_move == computer_move)
        {
            std::cout << "It's a tie!" << std::endl;
        }
        else if ((user_move == "Rock" && computer_move == "Scissors") ||
                 (user_move == "Scissors" && computer_move == "Paper") ||
                 (user_move == "Paper" && computer_move == "Rock"))
        {
            std::cout << "You win!" << std::endl;
        }
        else
        {
            std::cout << "You lose!" << std::endl;
        }
    }

    return 0;
}