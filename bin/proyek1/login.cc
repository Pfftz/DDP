#include <iostream>

using namespace std;

void welcome()
{
    bool is_correct = false;
    while (!is_correct)
    {
        system("cls");
        string user, password;
        cout << "  ---------------- " << endl;
        cout << " |     Log In     |\n";
        cout << "  ---------------- \n";
        cout << "\n Username : ";
        getline(cin, user);
        cout << " Password : ";
        getline(cin, password);

        if (password == "adalahbenar" || password == "nausicaa" || password == "ahok")
        {
            system("cls");
            cout << "\n  ===============================\n";
            cout << " | Sukses Anda Berhasil Login !! |\n";
            cout << "  ===============================\n";
            is_correct = true;
        }
        else
        {
            system("cls");
            cout << "\n  =============\n";
            cout << " | Login Gagal |\n";
            cout << "  =============\n\n";
            system("pause");
        }
    }
}

int main()
{
    welcome();
    return 0;
}