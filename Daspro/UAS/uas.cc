#include <iostream>
#include <string>
#include <stack>
using namespace std;

string kalimat;
stack<char> kata;
bool palindrom = true;

int main()
{
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
        cout << "\n Kalimat tersebut palindrom " << endl;
    }
    else
    {
        cout << "\n Kata tersebut bukan palindrom" << endl;
    }
    return 0;
}