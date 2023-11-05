#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <map>
#include <tuple>

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
    cout << "\n\n ===========================================================" << endl;
    cout << " -----------------------------------------------------------" << endl;
    cout << " ####----         Struk Grosir Kelompok 5 DDP      ----####" << endl;
    cout << " -----------------------------------------------------------" << endl;
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
    cout << " ===========================================================" << endl;
    cout << " -----------------------------------------------------------" << endl;
    cout << " Total Pembelian   : Rp." << total << endl;
    cout << " Total diskon      : Rp." << discount << endl;
    cout << " Total biaya       : Rp." << total - discount << endl;
    cout << " Tunai             : Rp." << paid << endl;
    cout << " Kembalian         : Rp." << paid - (total - discount) << endl;
    cout << endl;
    cout << " -----------------------------------------------------------" << endl;
    cout << " ===========================================================" << endl;
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

void login()
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

void menu1()
{
    int jumlah;
    double paid, total = 0;
    string input;

    cout << "+============================================================+" << endl;
    cout << "\tMasukan barang yang akan dibeli: ";
    cin >> jumlah;

    while (jumlah > 0)
    {
        cout << "\tMasukan nama barang: ";
        cin.ignore();
        getline(cin, input);

        if (items.find(input) != items.end())
        {
            int quantity;
            cout << "\tMasukkan jumlah barang (stok: " << get<1>(items[input]) << "): ";
            cin >> quantity;

            if (quantity <= get<1>(items[input]))
            {
                cart[input] += quantity;
                get<1>(items[input]) -= quantity;
            }
            else
            {
                cout << "\tStok tidak mencukupi!" << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "\tBarang tidak tersedia atau jumlah salah." << endl;
            break;
        }
        jumlah--;
    }

    for (const auto &item : cart)
    {
        total += get<0>(items[item.first]) * item.second;
    }

    double discount = calculate_discount(total);

    cout << "\tTotal belanja: Rp." << total - discount << endl;
    cout << "\tMasukkan jumlah uang yang dibayarkan: Rp.";
    cin >> paid;
    cout << "+============================================================+" << endl;

    print_receipt(total, discount, paid);

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

int main()
{
    welcome();
    login();
    system("cls");
    while (ulang)
    {
        cout << " ===========================================================" << endl;
        cout << " -----------------------------------------------------------" << endl;
        cout << " ####----         Kasir Grosir Kelompok 5 DDP      ----####" << endl;
        cout << "\n\tKasir sederhana" << endl;
        cout << "\t1. Pembayaran\n";
        cout << "\t2. Daftar Barang\n";
        cout << "\t3. Cek stock\n";
        cout << "\t4. Update stock\n";
        cout << "\t5. Hapus barang\n";
        cout << "\t0. keluar\n";
        cout << "\tmasukan pilihan: ";
        cin >> pil;
        cout << endl;
        switch (pil)
        {
        case 0:
        {
            ulang = false;
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
        default:
        {
            cout << "Pilihan tidak tersedia." << endl;
            break;
        }
        }
    }
    return 0;
}
