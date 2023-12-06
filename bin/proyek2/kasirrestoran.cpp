#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <iomanip>
#include <tuple>
#include <cctype>

using namespace std;

map<string, int> bahan_baku_stok{
    {"ayam", 50},
    {"sayur", 100},
    {"bumbu", 50},
    {"tepung", 50},
    {"nasi", 100},
    {"telur", 50}};

map<string, tuple<double, map<string, int>>> menu{
    {"nasi goreng", {25000, {{"Nasi", 1}, {"Ayam", 1}, {"Telur", 1}}}},
    {"ayam goreng", {35000, {{"Ayam", 1}, {"Bumbu", 1}}}},
    {"capcay", {15000, {{"Sayur", 2}, {"Bumbu", 1}}}},
    {"nasi ayam", {30000, {{"Nasi", 1}, {"Ayam", 1}, {"Bumbu", 1}}}},
    {"bubur", {15000, {{"Nasi", 1}, {"Ayam", 1}, {"Sayur", 1}}}},
};

map<string, int> pesanan;
string input;
long long int total_harga;
int pil;
char kode;
long long int diskon = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void tampilkan_daftar_menu()
{
    cout << "\n\t--- Daftar Menu ---" << endl;
    for (const auto &item : menu)
    {
        const string &nama_menu = item.first;
        const double harga_menu = std::get<0>(item.second);

        cout << "\t" << nama_menu << " - Rp" << harga_menu << endl;
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

double get_total(const map<string, int> &pesanan)
{
    double total = 0;
    for (const auto &item : pesanan)
    {
        total += item.second * std::get<0>(menu.at(item.first));
    }
    return total;
}

auto to_lowercase = [](string &input)
{
    for (auto &c : input)
        c = tolower(c);
};

void kurangi_stok_bahan_baku(const map<string, int> &pesanan)
{
    for (const auto &item : pesanan)
    {
        string nama_menu = item.first;
        int jumlah_pesanan = item.second;

        const auto &bahan_menu = std::get<1>(menu.at(nama_menu));
        for (const auto &bahan : bahan_menu)
        {
            string nama_bahan = bahan.first;
            to_lowercase(nama_bahan); // Convert to lowercase
            int jumlah_bahan_dibutuhkan = bahan.second * jumlah_pesanan;

            if (bahan_baku_stok.find(nama_bahan) != bahan_baku_stok.end()) // Check if the ingredient exists
            {
                bahan_baku_stok[nama_bahan] -= jumlah_bahan_dibutuhkan;
            }
        }
    }
    cout << endl;
}

void menu1()
{
    tampilkan_daftar_menu();
    char pesan_lagi;
    do
    {
        cout << "+---------------------------------------------------------+" << endl;
        cout << "\tPilih menu yang ingin dipesan: ";
        cin.ignore();
        getline(cin, input);
        // Pass input to the to_lowercase function
        to_lowercase(input);

        if (menu.find(input) != menu.end())
        {
            int quantity;
            cout << "\tMasukkan jumlah porsi: ";
            cin >> quantity;

            pesanan[input] += quantity;

            cout << "\tApakah Anda ingin memesan menu lagi? (y/n): ";
            cin >> pesan_lagi;
            cout << endl;
        }
        else
        {
            cout << "\tMenu tidak tersedia. Silakan pilih menu lain.\n";
        }
    } while (pesan_lagi == 'y' || pesan_lagi == 'Y');

    total_harga = get_total(pesanan);

    cout << "\tMasukan kode diskon: ";
    cin >> kode;
    if (kode == 'A' || kode == 'a')
    {
        diskon += (total_harga * 0.1);
    }
    else if (kode == 'B' || kode == 'b')
    {
        diskon += (total_harga * 0.2);
    }
    else if (kode == 'C' || kode == 'c')
    {
        diskon += (total_harga * 0.3);
    }
    long long int harga_bayar = total_harga - diskon;

    cout << "\tTotal belanja: Rp" << total_harga << endl;
    cout << "\tTotal diskon: Rp" << diskon << endl;
    cout << "\tTotal yang harus dibayarkan: Rp" << harga_bayar << endl;
    cout << endl;

    long long int uang_bayar;
    cout << "\tMasukan jumlah uang yang dibayarkan: Rp";
    cin >> uang_bayar;
    long long int kembalian = uang_bayar - harga_bayar;
    cout << "\tKembalianmu adalah: Rp" << kembalian << endl;

    kurangi_stok_bahan_baku(pesanan);

    cout << "\tPesanan berhasil diproses!" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu3()
{
    cout << "\n\tStok bahan baku saat ini:" << endl;
    for (const auto &bahan : bahan_baku_stok)
    {
        cout << "\t" << bahan.first << " - Stok: " << bahan.second << endl;
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu4()
{
    cout << "\n\tPesanan saat ini:" << endl;
    for (const auto &item : pesanan)
    {
        cout << "\t" << item.first << " - " << item.second << " porsi" << endl;
    }
    cout << "\n\tDengan Total harga: Rp" << total_harga << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu5()
{
    cout << "\n\tTotal pendapatan saat ini: Rp" << total_harga << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu6()
{
    cout << "\n\tMasukkan nama bahan baku yang akan diupdate stoknya: ";
    cin >> input;
    if (bahan_baku_stok.find(input) != bahan_baku_stok.end())
    {
        int newStock;
        cout << "\tMasukkan jumlah stok baru: ";
        cin >> newStock;
        bahan_baku_stok[input] = newStock;
        cout << "\tStok bahan baku '" << input << "' telah diupdate menjadi " << newStock << endl;
    }
    else
    {
        cout << "\tBahan baku tidak ditemukan." << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu7()
{
    cout << "\n\tMasukkan nama menu yang akan ditambahkan: ";
    cin.ignore();
    getline(cin, input);

    if (menu.find(input) != menu.end())
    {
        cout << "\tMenu '" << input << "' sudah ada." << endl;
    }
    else
    {
        double harga;
        cout << "\tMasukkan harga menu: Rp";
        cin >> harga;
        cin.ignore();

        int jumlah_bahan;
        cout << "\tBerapa banyak bahan baku yang dibutuhkan: ";
        cin >> jumlah_bahan;
        cin.ignore();

        map<string, int> bahan_menu;
        for (int i = 0; i < jumlah_bahan; i++)
        {
            string nama_bahan;
            int jumlah_bahan_dibutuhkan;

            cout << "\tMasukkan nama bahan baku: ";
            getline(cin, nama_bahan);
            cout << "\tMasukkan jumlah bahan   : ";
            cin >> jumlah_bahan_dibutuhkan;
            cin.ignore();

            bahan_menu[nama_bahan] = jumlah_bahan_dibutuhkan;

            // Check if the ingredient already exists in the bahan_baku_stok map
            if (bahan_baku_stok.find(nama_bahan) == bahan_baku_stok.end())
            {
                // If the ingredient doesn't exist, add it to the map and initialize its stock to a default value
                int stok_bahan;
                cout << "\tMasukkan stok bahan baku '" << nama_bahan << "': ";
                cin >> stok_bahan;
                cin.ignore();
                bahan_baku_stok[nama_bahan] = stok_bahan;
            }
        }

        menu[input] = {harga, bahan_menu};
        cout << "\tMenu '" << input << "' berhasil ditambahkan." << endl;
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu8()
{
    cout << "\n\tMasukkan nama menu yang akan dihapus: ";
    cin.ignore();
    getline(cin, input);
    to_lowercase(input);

    if (menu.find(input) != menu.end())
    {
        menu.erase(input);
        cout << "\tMenu '" << input << "' berhasil dihapus." << endl;
    }
    else
    {
        cout << "\tMenu tidak ditemukan." << endl;
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

void menu9()
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
    cout << " 2. Ezra Darrel Prasetya P (3337230069)" << endl;
    cout << " 3. Maulana Faizar Rasyadan (3337230072)" << endl;
    cout << " 4. Usamah Abdul Aziz (3337230079)" << endl;
    cout << " 5. Muhammad Daffi Maulana (3337230080) " << endl;
    cout << " 6. Dinda oktavia (3337230082)" << endl;
    cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << "-";
    }
    SetConsoleTextAttribute(h, 7);
    cout << "\n"
         << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

int main()
{
    // welcome();
    // system("cls");
    do
    {
        cout << "\n===========================================================" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "####----        Kasir Restoran Kelompok 5 DDP      ----####" << endl;
        cout << "\n\tKasir restoran" << endl;
        cout << "\t1. Pesan Menu\n";
        cout << "\t2. Lihat Daftar Menu\n";
        cout << "\t3. Cek Stok Bahan Baku\n";
        cout << "\t4. Cek Pesanan\n";
        cout << "\t5. Cek Total Pendapatan\n";
        cout << "\t6. Update Stok Bahan Baku\n";
        cout << "\t7. Tambah Menu\n";
        cout << "\t8. Hapus Menu\n";
        cout << "\t9. Credit\n";
        cout << "\t0. Keluar\n\n";
        cout << "===========================================================" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << endl;
        cout << "\tMasukkan pilihan: ";
        cin >> pil;
        cout << endl;
        cout << "-----------------------------------------------------------" << endl;

        switch (pil)
        {
        case 1:
        {
            menu1();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }

        case 2:
        {
            tampilkan_daftar_menu();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }

        case 3:
        {
            menu3();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }

        case 4:
        {
            menu4();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 5:
        {
            menu5();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 6:
        {
            menu6();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 7:
        {
            menu7();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 8:
        {
            menu8();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 9:
        {
            menu9();
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        case 0:
        {
            cout << "\tTerima kasih telah menggunakan aplikasi ini!" << endl;
            cout << "\tSampai jumpa kembali!" << endl;
            cout << endl;
            break;
        }
        default:
        {
            cout << "\tPilihan tidak tersedia." << endl;
            system("pause");
            system("cls");
            cout << endl;
            break;
        }
        }
    } while (pil != 0);

    return 0;
}