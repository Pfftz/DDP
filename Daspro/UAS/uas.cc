#include <iostream>
#include <string>
#include <stack>
using namespace std;

string kalimat;
stack<char> kata;
bool palindrom = true;

void welcome()
{
    /*
    R"()" is used to create a raw string literal
    Raw string literal adalah sebuah tipe data yang sama dengan literal string,
    namun raw string literal memungkinkan pengguna
    untuk menyertakan karakter khusus dalam teks tanpa harus meng-escape-nya (menambahkan karakter khusus seperti backslash '\').
    */
    string opening = R"(
                                                                                                           
        ##### ##           ###                          ##                                                 
     ######  /###           ###    #                     ##                                                
    /#   /  /  ###           ##   ###                    ##                                                
   /    /  /    ###          ##    #                     ##                                                
       /  /      ##          ##                          ##                                                
      ## ##      ##  /###    ##  ###   ###  /###     ### ##  ###  /###     /###   ### /### /###     /##    
      ## ##      ## / ###  / ##   ###   ###/ #### / ######### ###/ #### / / ###  / ##/ ###/ /##  / / ###   
    /### ##      / /   ###/  ##    ##    ##   ###/ ##   ####   ##   ###/ /   ###/   ##  ###/ ###/ /   ###  
   / ### ##     / ##    ##   ##    ##    ##    ##  ##    ##    ##       ##    ##    ##   ##   ## ##    ### 
      ## ######/  ##    ##   ##    ##    ##    ##  ##    ##    ##       ##    ##    ##   ##   ## ########  
      ## ######   ##    ##   ##    ##    ##    ##  ##    ##    ##       ##    ##    ##   ##   ## #######   
      ## ##       ##    ##   ##    ##    ##    ##  ##    ##    ##       ##    ##    ##   ##   ## ##        
      ## ##       ##    /#   ##    ##    ##    ##  ##    /#    ##       ##    ##    ##   ##   ## ####    / 
      ## ##        ####/ ##  ### / ### / ###   ###  ####/      ###       ######     ###  ###  ### ######/  
 ##   ## ##         ###   ##  ##/   ##/   ###   ###  ###        ###       ####       ###  ###  ### #####   
###   #  /                                                                                                 
 ###    /                                                                                                  
  #####/                                                                                                   
    ###                                                                                                    
)";
    // fontnya NV Script
    cout << endl
         << opening << "\n"
         << endl;
    cout << "====================================" << endl;
    cout << " Nama: Abdulhadi Muntashir" << endl;
    cout << " NIM: 3337230041" << endl;
    cout << "====================================" << endl;
    cout << endl;
    system("pause"); // command line for stopping the program
}

int main()
{
    welcome();
    system("cls"); // command line for clearing the screen
    cout << "\n\n Program Palindrom Checker" << endl;
    cout << "+--------------------------------------------------+" << endl;
    cout << " Masukkan Kalimat: ";
    getline(cin, kalimat);
    cout << "\n Jumlah kata dari kalimat yang dimasukkan: " << kalimat.length() << endl;

    // Memasukkan setiap karakter ke dalam stack
    for (std::string::size_type i = 0; i < kalimat.length(); i++)
    {
        kata.push(kalimat[i]);
    }

    // Membandingkan elemen pertama dan terakhir pada stack
    for (std::string::size_type i = 0; i < kalimat.length() / 2; i++)
    {
        if (kata.top() != kalimat[i])
        {
            palindrom = false;
            break;
        }
        kata.pop();
    }

    if (palindrom)
    {
        cout << "\n Kalimat tersebut adalah palindrom " << endl;
    }
    else
    {
        cout << "\n Kata tersebut bukan palindrom" << endl;
    }
    cout << "+--------------------------------------------------+" << endl;
    cout << "       ______    __          __        ______    " << endl;
    cout << "      /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
    cout << "     (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
    cout << "      \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
    cout << "      //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
    cout << "     (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
    cout << "      \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
    cout << "                                                  " << endl;

    return 0;
}