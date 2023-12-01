#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void welcome()
{
    /*
    R"()" is used to create a raw string literal
    Raw string literal adalah sebuah tipe data yang sama dengan literal string,
    namun raw string literal memungkinkan pengguna
    untuk menyertakan karakter khusus dalam teks tanpa harus meng-escape-nya (menambahkan karakter khusus seperti backslash '\').
    */
    string opening = R"(
   ___                    _                _                         ___                    __ _     _                       _            
  / __|    ___    _ __   | |__    __ _    | |__    ___      o O O   | _ \   ___    _ _     / _` |   | |    __ _      _ _    (_)     ___   
  \__ \   / -_)  | '  \  | '_ \  / _` |   | / /   / _ \    o        |  _/  / -_)  | ' \    \__, |   | |   / _` |    | '_|   | |    (_-<   
  |___/   \___|  |_|_|_| |_.__/  \__,_|   |_\_\   \___/   TS__[O]  _|_|_   \___|  |_||_|   |___/   _|_|_  \__,_|   _|_|_   _|_|_   /__/_  
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_| """ |_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
)";
    // fontnya Alligator2
    SetConsoleTextAttribute(h, 3); // biru
    cout << endl
         << opening << "\n\n\n"
         << endl;
    SetConsoleTextAttribute(h, 7); // putih
    cout << " Version: alpha\n\n\n\n eres el mejor programador del mundo - Bang Messi\n\n\n\n";
    system("pause"); // command line for stopping the program
}

int main()
{
    welcome();
    return 0;
}