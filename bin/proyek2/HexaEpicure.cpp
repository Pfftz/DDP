#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <iomanip>
#include <tuple>
#include <cctype>
#include <vector>

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

vector<map<string, int>> pesanan;
string input;
vector<long long int> total_harga;
int pil;
char kode;
long long int diskon = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void tampilkan_daftar_menu()
{
    std::cout << "\n\t--- Daftar Menu ---" << endl;
    for (const auto &item : menu)
    {
        const string &nama_menu = item.first;
        const double harga_menu = std::get<0>(item.second);

        std::cout << "\t" << nama_menu << " - Rp" << harga_menu << endl;
    }
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
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
    std::cout << endl;
}

void menu1()
{
    tampilkan_daftar_menu();
    char pesan_lagi;
    map<string, int> pesanan_saat_ini;
    long long int total_harga_saat_ini = 0; // Declare total_harga_saat_ini here

    do
    {
        std::cout << "+---------------------------------------------------------+" << endl;
        std::cout << "\tPilih menu yang ingin dipesan: ";
        std::cin.ignore();
        getline(std::cin, input);
        // Pass input to the to_lowercase function
        to_lowercase(input);

        if (menu.find(input) != menu.end())
        {
            int quantity;
            std::cout << "\tMasukkan jumlah porsi: ";
            std::cin >> quantity;

            pesanan_saat_ini[input] += quantity;

            std::cout << "\tApakah Anda ingin memesan menu lagi? (y/n): ";
            std::cin >> pesan_lagi;
            std::cout << endl;
        }
        else
        {
            std::cout << "\tMenu tidak tersedia. Silakan pilih menu lain.\n";
        }

        total_harga_saat_ini += get_total({{input, pesanan_saat_ini[input]}}); // Use += instead of =

        std::cout << "\tTotal belanja untuk pesanan ini: Rp" << total_harga_saat_ini << endl;

    } while (pesan_lagi == 'y' || pesan_lagi == 'Y');

    pesanan.push_back(pesanan_saat_ini);
    total_harga.push_back(total_harga_saat_ini);

    std::cout << "\tMasukan kode diskon: ";
    std::cin >> kode;
    if (kode == 'A' || kode == 'a')
    {
        diskon += (total_harga_saat_ini * 0.1);
    }
    else if (kode == 'B' || kode == 'b')
    {
        diskon += (total_harga_saat_ini * 0.2);
    }
    else if (kode == 'C' || kode == 'c')
    {
        diskon += (total_harga_saat_ini * 0.3);
    }
    long long int harga_bayar = total_harga_saat_ini - diskon;

    std::cout << "\tTotal belanja: Rp" << total_harga_saat_ini << endl;
    std::cout << "\tTotal diskon: Rp" << diskon << endl;
    std::cout << "\tTotal yang harus dibayarkan: Rp" << harga_bayar << endl;
    std::cout << endl;

    long long int uang_bayar;
    std::cout << "\tMasukan jumlah uang yang dibayarkan: Rp";
    std::cin >> uang_bayar;
    long long int kembalian = uang_bayar - harga_bayar;
    std::cout << "\tKembalianmu adalah: Rp" << kembalian << endl;

    kurangi_stok_bahan_baku(pesanan.back());

    std::cout << "\tPesanan berhasil diproses!" << endl;
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu3()
{
    std::cout << "\n\tStok bahan baku saat ini:" << endl;
    for (const auto &bahan : bahan_baku_stok)
    {
        std::cout << "\t" << bahan.first << " - Stok: " << bahan.second << endl;
    }
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu4()
{
    std::cout << "\n\tPesanan saat ini:" << std::endl;
    for (std::vector<std::map<std::string, int>>::size_type i = 0; i < pesanan.size(); i++)
    {
        std::cout << "\tPesanan - " << i + 1 << std::endl;
        for (const auto &item : pesanan[i])
        {
            std::cout << "\t" << item.first << " - " << item.second << " porsi" << std::endl;
        }
        std::cout << "\n\tDengan Total harga: Rp" << total_harga[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "===========================================================" << std::endl;
    std::cout << std::endl;
}

void menu5()
{
    long long int total_pendapatan = 0;
    for (const auto &harga : total_harga)
    {
        total_pendapatan += harga;
    }

    std::cout << "\n\tTotal pendapatan saat ini: Rp" << total_pendapatan << endl;
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu6()
{
    std::cout << "\n\tMasukkan nama bahan baku yang akan diupdate stoknya: ";
    std::cin >> input;
    if (bahan_baku_stok.find(input) != bahan_baku_stok.end())
    {
        int newStock;
        std::cout << "\tMasukkan jumlah stok baru: ";
        std::cin >> newStock;
        bahan_baku_stok[input] = newStock;
        std::cout << "\tStok bahan baku '" << input << "' telah diupdate menjadi " << newStock << endl;
    }
    else
    {
        std::cout << "\tBahan baku tidak ditemukan." << endl;
    }
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu7()
{
    std::cout << "\n\tMasukkan nama menu yang akan ditambahkan: ";
    std::cin.ignore();
    getline(std::cin, input);

    if (menu.find(input) != menu.end())
    {
        std::cout << "\tMenu '" << input << "' sudah ada." << endl;
    }
    else
    {
        double harga;
        std::cout << "\tMasukkan harga menu: Rp";
        std::cin >> harga;
        std::cin.ignore();

        int jumlah_bahan;
        std::cout << "\tBerapa banyak bahan baku yang dibutuhkan: ";
        std::cin >> jumlah_bahan;
        std::cin.ignore();

        map<string, int> bahan_menu;
        for (int i = 0; i < jumlah_bahan; i++)
        {
            string nama_bahan;
            int jumlah_bahan_dibutuhkan;

            std::cout << "\tMasukkan nama bahan baku: ";
            getline(std::cin, nama_bahan);
            std::cout << "\tMasukkan jumlah bahan   : ";
            std::cin >> jumlah_bahan_dibutuhkan;
            std::cin.ignore();

            bahan_menu[nama_bahan] = jumlah_bahan_dibutuhkan;

            // Check if the ingredient already exists in the bahan_baku_stok map
            if (bahan_baku_stok.find(nama_bahan) == bahan_baku_stok.end())
            {
                // If the ingredient doesn't exist, add it to the map and initialize its stock to a default value
                int stok_bahan;
                std::cout << "\tMasukkan stok bahan baku '" << nama_bahan << "': ";
                std::cin >> stok_bahan;
                std::cin.ignore();
                bahan_baku_stok[nama_bahan] = stok_bahan;
            }
        }

        menu[input] = {harga, bahan_menu};
        std::cout << "\tMenu '" << input << "' berhasil ditambahkan." << endl;
    }
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu8()
{
    std::cout << "\n\tMasukkan nama menu yang akan dihapus: ";
    std::cin.ignore();
    getline(std::cin, input);
    to_lowercase(input);

    if (menu.find(input) != menu.end())
    {
        menu.erase(input);
        std::cout << "\tMenu '" << input << "' berhasil dihapus." << endl;
    }
    else
    {
        std::cout << "\tMenu tidak ditemukan." << endl;
    }
    std::cout << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
}

void menu9()
{
    SetConsoleTextAttribute(h, 5);
    std::cout << "\n";
    std::cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        std::cout << "-";
    }
    std::cout << "\n Credit: " << endl;
    std::cout << " 1. Abdulhadi Muntashir (3337230041)" << endl;
    std::cout << " 2. Ezra Darrel Prasetya P (3337230069)" << endl;
    std::cout << " 3. Maulana Faizar Rasyadan (3337230072)" << endl;
    std::cout << " 4. Usamah Abdul Aziz (3337230079)" << endl;
    std::cout << " 5. Muhammad Daffi Maulana (3337230080) " << endl;
    std::cout << " 6. Dinda oktavia (3337230082)" << endl;
    std::cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        std::cout << "-";
    }
    SetConsoleTextAttribute(h, 7);
    std::cout << "\n"
              << endl;
    std::cout << "-----------------------------------------------------------" << endl;
    std::cout << "===========================================================" << endl;
    std::cout << endl;
    system("pause");
    system("cls");
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
    SetConsoleTextAttribute(h, 13); // merah
    cout << endl
         << opening << "\n"
         << endl;
    SetConsoleTextAttribute(h, 7); // putih
    cout << "                    Welcome to HexaEpicure! Experience culinary magic with the essence of six. \n\n\n";
    cout << "  \"Embrace the harmony of HexaEpicure, where the essence of six transforms every bite into a symphony of perfection.\"\n\n\n"
         << endl;
    system("pause"); // command line for stopping the program
    loading();
}

int main()
{
    welcome();
    system("cls");
    do
    {
        std::cout << "\n===========================================================" << endl;
        std::cout << "-----------------------------------------------------------" << endl;
        std::cout << "####----        Kasir Restoran Kelompok 5 DDP      ----####" << endl;
        std::cout << "\n\tKasir restoran" << endl;
        std::cout << "\t1. Pesan Menu\n";
        std::cout << "\t2. Lihat Daftar Menu\n";
        std::cout << "\t3. Cek Stok Bahan Baku\n";
        std::cout << "\t4. Cek Pesanan\n";
        std::cout << "\t5. Cek Total Pendapatan\n";
        std::cout << "\t6. Update Stok Bahan Baku\n";
        std::cout << "\t7. Tambah Menu\n";
        std::cout << "\t8. Hapus Menu\n";
        std::cout << "\t9. Credit\n";
        std::cout << "\t0. Keluar\n\n";
        std::cout << "===========================================================" << endl;
        std::cout << "-----------------------------------------------------------" << endl;
        std::cout << endl;
        std::cout << "\tMasukkan pilihan: ";
        std::cin >> pil;
        std::cout << endl;
        std::cout << "-----------------------------------------------------------" << endl;

        switch (pil)
        {
        case 1:
        {
            menu1();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }

        case 2:
        {
            tampilkan_daftar_menu();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }

        case 3:
        {
            menu3();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }

        case 4:
        {
            menu4();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 5:
        {
            menu5();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 6:
        {
            menu6();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 7:
        {
            menu7();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 8:
        {
            menu8();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 9:
        {
            menu9();
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        case 0:
        {
            std::cout << "\tTerima kasih telah menggunakan aplikasi ini!" << endl;
            std::cout << "\tSampai jumpa kembali!" << endl;
            std::cout << endl;
            SetConsoleTextAttribute(h, 5);
            cout << "          ______    __          __        ______    " << endl;
            cout << "         /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
            cout << "        (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
            cout << "         \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
            cout << "         //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
            cout << "        (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
            cout << "         \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
            cout << "                                                     " << endl;
            std::cout << endl;
            std::cout << "-----------------------------------------------------------" << endl;
            std::cout << "===========================================================" << endl;
            std::cout << endl;
            break;
        }
        default:
        {
            std::cout << "\tPilihan tidak tersedia." << endl;
            system("pause");
            system("cls");
            std::cout << endl;
            break;
        }
        }
    } while (pil != 0);

    return 0;
}