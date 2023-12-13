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
                                                                                                                
                                                                        ,,                                      
        `7MMF'  `7MMF'                           `7MM"""YMM             db                                      
          MM      MM                               MM    `7                                                     
          MM      MM  .gP"Ya `7M'   `MF' ,6"Yb.    MM   d   `7MMpdMAo.`7MM  ,p6"bo `7MM  `7MM  `7Mb,od8 .gP"Ya  
          MMmmmmmmMM ,M'   Yb  `VA ,V'  8)   MM    MMmmMM     MM   `Wb  MM 6M'  OO   MM    MM    MM' "',M'   Yb 
          MM      MM 8M""""""    XMX     ,pm9MM    MM   Y  ,  MM    M8  MM 8M        MM    MM    MM    8M"""""" 
          MM      MM YM.    ,  ,V' VA.  8M   MM    MM     ,M  MM   ,AP  MM YM.    ,  MM    MM    MM    YM.    , 
        .JMML.  .JMML.`Mbmmd'.AM.   .MA.`Moo9^Yo..JMMmmmmMMM  MMbmmd' .JMML.YMbmd'   `Mbod"YML..JMML.   `Mbmmd' 
                                                              MM                                                
                                                            .JMML.                                              
)";
    // fontnya NV Script
    cout << endl
         << opening << "\n"
         << endl;
    cout << "                    Welcome to HexaEpicure! Experience culinary magic with the essence of six. \n\n\n";
    cout << "  \"Embrace the harmony of HexaEpicure, where the essence of six transforms every bite into a symphony of perfection.\"\n\n\n"
         << endl;
    system("pause"); // command line for stopping the program
}

int main()
{
    welcome();
    system("cls"); // command line for clearing the screen
    cout << "+--------------------------------------------------+" << endl;
    cout << " Masukkan Kalimat: ";
    getline(cin, kalimat);
    cout << "\n Jumlah kata dari kalimat yang dimasukkan: " << kalimat.length() << endl;

    // Memasukkan setiap karakter ke dalam stack
    for (int i = 0; i < kalimat.length(); i++)
    {
        kata.push(kalimat[i]);
    }

    // Membandingkan elemen pertama dan terakhir pada stack
    for (int i = 0; i < kalimat.length() / 2; i++)
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
    cout << "          ______    __          __        ______    " << endl;
    cout << "         /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
    cout << "        (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
    cout << "         \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
    cout << "         //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
    cout << "        (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
    cout << "         \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
    cout << "                                                     " << endl;

    return 0;
}