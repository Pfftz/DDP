#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <map>
#include <tuple>
#include <stdio.h>

using namespace std;

map<string, int> cart;
string input;
long long int total_harga;
bool ulang = true;
int diskon = 0, pil, jumlah;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

map<string, tuple<double, int, string>> items{
    {"beras", {15000, 20, "kg"}},
    {"terigu", {14000, 20, "kg"}},
    {"telur", {35000, 20, "kg"}},
    {"minyak sayur", {20000, 20, "liter"}},
    {"sabun 900ml", {54000, 20, "pcs"}},
    {"sampo 340ml", {35000, 20, "pcs"}},
    {"mie instan", {128000, 20, "dus"}},
    {"gula", {15000, 20, "kg"}},
    {"detergen 1.8kg", {35000, 20, "pcs"}},
    {"rokok", {150000, 20, "slop"}}};

double get_total(const map<string, int> &cart)
{
    double total = 0;
    for (const auto &item : cart)
    {
        total += item.second * std::get<0>(items.at(item.first));
    }
    return total;
}

void loading()
{
    system("cls");
    printf("\e[?25l");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\tLoading...";
    cout << "\n\n\n\t\t";

    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar1;
    }
    cout << "\r";
    cout << "\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }

    cout << "\n\t\t"
         << (char)1 << "!";
    system("pause");
}

double calculate_discount(double total)
{
    if (total >= 500000)
    {
        return total * 0.3;
    }
    else if (total >= 250000)
    {
        return total * 0.2;
    }
    else if (total >= 120000)
    {
        return total * 0.1;
    }
    else
    {
        return 0;
    }
}

void print_receipt(double total, double discount, double paid)
{
    cout << "\n\n ==========================================================================" << endl;
    cout << " --------------------------------------------------------------------------" << endl;
    cout << "        ####----         Struk Grosir Kelompok 5 DDP      ----####" << endl;
    cout << " --------------------------------------------------------------------------" << endl;
    cout << " " << left << setw(20) << "Nama Barang"
         << setw(10) << "Jumlah"
         << setw(10) << "Satuan"
         << setw(20) << "Harga Satuan"
         << setw(20) << " Subtotal"
         << endl;

    for (const auto &item : cart)
    {
        double harga_awal = get<0>(items[item.first]);
        double sub_total = harga_awal * item.second;

        cout << " " << left << setw(20) << item.first
             << setw(10) << item.second
             << setw(10) << get<2>(items[item.first])
             << "Rp. " << setw(17) << fixed << setprecision(2) << harga_awal
             << "Rp. " << setw(17) << fixed << setprecision(2) << sub_total
             << endl;
    }
    cout << " ==========================================================================" << endl;
    cout << " --------------------------------------------------------------------------" << endl;
    cout << " Total Pembelian   : Rp." << total << endl;
    cout << " Total diskon      : Rp." << discount << endl;
    cout << " Total biaya       : Rp." << total - discount << endl;
    cout << " Tunai             : Rp." << paid << endl;
    cout << " Kembalian         : Rp." << paid - (total - discount) << endl;
    cout << " --------------------------------------------------------------------------" << endl;
    cout << " ==========================================================================" << endl;
    cout << endl;
    cout << endl;
}

void welcome()
{
    /*
    R"()" is used to create a raw string literal
    Raw string literal adalah sebuah tipe data yang sama dengan literal string,
    namun raw string literal memungkinkan pengguna
    untuk menyertakan karakter khusus dalam teks tanpa harus meng-escape-nya (menambahkan karakter khusus seperti backslash '\').
    */
    string opening = R"(
                                                                                                                                         
                                         _|                                                        _|                      _|            
   _|_|_|  _|  _|_|    _|_|      _|_|_|      _|  _|_|      _|_|_|      _|_|    _|_|_|      _|_|_|  _|    _|_|_|  _|  _|_|        _|_|_|  
 _|    _|  _|_|      _|    _|  _|_|      _|  _|_|          _|    _|  _|_|_|_|  _|    _|  _|    _|  _|  _|    _|  _|_|      _|  _|_|      
 _|    _|  _|        _|    _|      _|_|  _|  _|            _|    _|  _|        _|    _|  _|    _|  _|  _|    _|  _|        _|      _|_|  
   _|_|_|  _|          _|_|    _|_|_|    _|  _|            _|_|_|      _|_|_|  _|    _|    _|_|_|  _|    _|_|_|  _|        _|  _|_|_|    
       _|                                                  _|                                  _|                                        
   _|_|                                                    _|                              _|_|                                          
)";
    // fontnya Block
    SetConsoleTextAttribute(h, 4); // merah
    cout << endl
         << opening << "\n\n\n"
         << endl;
    SetConsoleTextAttribute(h, 7); // putih
    cout << " Version: alpha\n\n\n\n eres el mejor programador del mundo - Bang Messi\n\n\n\n";
    system("pause"); // command line for stopping the program
}

string login()
{
    bool is_correct = false;
    string username;
    while (!is_correct)
    {
        system("cls");
        cout << "  ---------------- " << endl;
        cout << " |     Log In     |\n";
        cout << "  ---------------- \n";
        cout << "\n Username : ";
        getline(cin, username);
        cout << " Password : ";
        string password;
        getline(cin, password);

        if (password == "adalahbenar" || password == "nausicaa" || password == "ahok")
        {
            system("cls");
            cout << "\n  ===============================\n";
            cout << " | Sukses Anda Berhasil Login !! |\n";
            cout << "  ===============================\n\n";
            is_correct = true;
            system("pause");
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
    return username;
}

void menu1()
{
    int jumlah;
    double paid, total = 0;
    string input;

    cout << "+============================================================+" << endl;
    cout << "\tMasukan jumlah barang yang akan dibeli: ";
    cin >> jumlah;
    cin.ignore(); // Ignore the newline character left by cin >> jumlah

    bool itemFound = false;

    while (jumlah > 0)
    {
        cout << "\tMasukan nama barang: ";
        getline(cin, input);

        if (items.find(input) != items.end())
        {
            itemFound = true;
            int quantity;
            cout << "\tMasukkan jumlah barang (stok: " << get<1>(items[input]) << "): ";
            cin >> quantity;
            cin.ignore(); // Ignore the newline character left by cin >> quantity

            if (quantity <= get<1>(items[input]))
            {
                cart[input] += quantity;
                get<1>(items[input]) -= quantity;
            }
            else
            {
                cout << "\tStok tidak mencukupi!\n"
                     << endl;
                continue;
            }
            cout << endl;
        }
        else
        {
            cout << "\tBarang tidak tersedia atau jumlah salah.\n"
                 << endl;
            continue;
        }
        jumlah--;
    }

    if (itemFound)
    {
        for (const auto &item : cart)
        {
            total += get<0>(items[item.first]) * item.second;
        }

        double discount = calculate_discount(total);

        cout << "\tTotal belanja: Rp." << total - discount << endl;
        cout << "\tMasukkan jumlah uang yang dibayarkan: Rp.";
        cin >> paid;

        cout << "+============================================================+" << endl;

        system("pause");
        SetConsoleTextAttribute(h, 13);
        loading();
        SetConsoleTextAttribute(h, 7);
        system("cls");

        print_receipt(total, discount, paid);
    }

    system("pause");
    system("cls");
}

void menu2()
{
    cout << "\n\n -----------------------------------------------------------" << endl;
    cout << " Daftar barang:" << endl;
    for (const auto &item : items)
    {
        cout << "  - " << item.first << " (" << get<1>(item.second) << " " << get<2>(item.second) << ")" << endl;
    }
    cout << " -----------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu3()
{
    cout << "\n\n -----------------------------------------------------------" << endl;
    cout << " Masukkan nama barang yang akan dicek stoknya: ";
    cin >> input;
    if (items.find(input) != items.end())
    {
        cout << " Stok barang '" << input << "' adalah " << get<1>(items[input]) << " " << get<2>(items[input]) << endl;
    }
    else
    {
        cout << " Barang tidak ditemukan." << endl;
    }
    cout << " -----------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu4()
{
    cout << "\n\n -----------------------------------------------------------" << endl;
    cout << " Masukkan nama barang yang akan diupdate stoknya: ";
    cin >> input;
    if (items.find(input) != items.end())
    {
        int newStock;
        cout << " Masukkan jumlah stok baru: ";
        cin >> newStock;
        std::get<1>(items[input]) = newStock;
        cout << " Stok barang '" << input << "' telah diupdate menjadi " << newStock << endl;
    }
    else
    {
        cout << " Barang tidak ditemukan." << endl;
    }
    cout << " -----------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu5()
{
    cout << "\n\n -----------------------------------------------------------" << endl;
    cout << " Masukkan nama barang yang akan dihapus: ";
    cin >> input;
    if (items.find(input) != items.end())
    {
        items.erase(input);
        cout << " Barang '" << input << "' telah dihapus." << endl;
    }
    else
    {
        cout << " Barang tidak ditemukan." << endl;
    }
    cout << " -----------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu6()
{
    SetConsoleTextAttribute(h, 5);
    cout << "\n\n";
    cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << "-";
    }
    cout << "\n Credit: " << endl;
    cout << " 1. Abdulhadi Muntashir (3337230041)" << endl;
    cout << " 2. Maulana Faizar Rasyadan (3337230072)" << endl;
    cout << " 3. Usamah Abdul Aziz (3337230079)" << endl;
    cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << "-";
    }
    SetConsoleTextAttribute(h, 7);
    cout << "\n"
         << endl;
    system("pause");
    system("cls");
}

int main()
{
    welcome();
    SetConsoleTextAttribute(h, 10);
    loading();
    SetConsoleTextAttribute(h, 7);
    string user = login();
    system("cls");
    while (ulang)
    {
        cout << " ============================================================" << endl;
        cout << " ------------------------------------------------------------" << endl;
        cout << " ####----           Kasir Grosir Penglaris           ----####" << endl;
        cout << " ------------------------------------------------------------" << endl;
        cout << " ============================================================" << endl;
        cout << " Pegawai: " << user << endl;
        cout << " ------------------------------------------------------------" << endl;
        cout << "\n\n";
        cout << "\tMenu: \n";
        cout << "\t1. Pembayaran\n";
        cout << "\t2. Daftar Barang\n";
        cout << "\t3. Cek stock\n";
        cout << "\t4. Update stock\n";
        cout << "\t5. Hapus barang\n";
        cout << "\t6. Credit\n";
        cout << "\t0. keluar\n";
        cout << "\tmasukan pilihan: ";
        cin >> pil;
        cout << endl;
        switch (pil)
        {
        case 0:
        {
            ulang = false;
            SetConsoleTextAttribute(h, 5);
            cout << "   ______    __          __        ______    " << endl;
            cout << "  /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
            cout << " (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
            cout << "  \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
            cout << "  //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
            cout << " (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
            cout << "  \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
            break;
        }
        case 1:
        {
            menu1();
            break;
        }

        case 2:
        {
            menu2();
            break;
        }

        case 3:
        {
            menu3();
            break;
        }
        case 4:
        {
            menu4();
            break;
        }
        case 5:
        {
            menu5();
            break;
        }
        case 6:
        {
            menu6();
            break;
        }
        default:
        {
            cout << "Pilihan tidak tersedia." << endl;
            break;
        }
        }
    }
    return 0;
}
