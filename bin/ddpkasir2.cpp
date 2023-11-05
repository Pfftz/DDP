#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <tuple>

using namespace std;

map<string, tuple<double, int, string>> items{
    {"Beras", {15000, 20, "kg"}},
    {"Terigu", {14000, 20, "kg"}},
    {"Telur", {35000, 20, "kg"}},
    {"Minyak sayur", {20000, 20, "liter"}},
    {"Sabun 900ml", {54000, 20, "pcs"}},
    {"Sampo 340ml", {35000, 20, "pcs"}},
    {"Mie instan", {128000, 20, "dus"}},
    {"Gula", {15000, 20, "kg"}},
    {"Detergen 1.8kg", {35000, 20, "pcs"}},
    {"Rokok", {150000, 20, "slop"}}};

double get_total(const map<string, int> &cart)
{
    double total = 0;
    for (const auto &item : cart)
    {
        total += item.second * std::get<0>(items.at(item.first));
    }
    return total;
}

int main()
{
    map<string, int> cart;
    string input;
    int jumlah;
    long long int total_harga;
    int diskon;
    int pil;
    diskon = 0;

    do
    {
        cout << "===========================================================" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "####----         Kasir Grosir Kelompok 5 DDP      ----####" << endl;
        cout << "\n\tKasir sederhana" << endl;
        cout << "\t1. Pembayaran\n";
        cout << "\t2. Cek stock\n";
        cout << "\t3. Update stock\n";
        cout << "\t0. keluar\n";
        cout << "\tmasukan pilihan: ";
        cin >> pil;
        cout << endl;
        switch (pil)
        {
        case 1:
        {
            cout << "\tmasukan jumlah barang yang dibeli: ";
            cin >> jumlah;
            do
            {
                cout << "\tmasukan nama barang: ";
                cin.ignore();
                getline(cin, input);
                if (items.find(input) != items.end() && jumlah > 0)
                {
                    int quantity;
                    cout << "\tMasukkan jumlah barang (stok: " << std::get<1>(items[input]) << "): ";
                    cin >> quantity;

                    if (quantity > std::get<1>(items[input]))
                    {
                        cout << "\tStok tidak mencukupi!" << endl;
                        continue;
                    }

                    cart[input] += quantity;
                    std::get<1>(items[input]) -= quantity;
                    jumlah -= quantity;
                }
                else
                {
                    cout << "\tBarang tidak tersedia atau jumlah salah." << endl;
                    break;
                }
            } while (jumlah > 0);

            total_harga = get_total(cart);

            if (total_harga >= 500000)
            {
                diskon += (total_harga * 0.3);
            }
            else if (total_harga < 500000 && total_harga >= 250000)
            {
                diskon += (total_harga * 0.2);
            }
            else if (total_harga < 250000 && total_harga >= 120000)
            {
                diskon += (total_harga * 0.1);
            }
            int harga_bayar = total_harga - diskon;
            cout << "\tTotal belanja: Rp." << harga_bayar << endl;
            double uang_dibayarkan;
            cout << "\tMasukkan jumlah uang yang dibayarkan: Rp.";
            cin >> uang_dibayarkan;
            double kembalian = uang_dibayarkan - harga_bayar;
            cout << endl;

            cout << "===========================================================" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "####----         Struk Grosir Kelompok 5 DDP      ----####" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Nama Barang         Jumlah       Harga Satuan      Subtotal" << endl;
            for (const auto &item : cart)
            {
                double harga_awal = std::get<0>(items[item.first]);
                double sub_total = harga_awal * item.second;
                cout << left << setw(20) << item.first;
                cout << setw(10) << item.second << get<2>(items[item.first]);
                cout << setw(20) << "Rp." << harga_awal;
                cout << setw(20) << "Rp." << sub_total << endl;
            }

            cout << "===========================================================" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Total Pembelian   : Rp." << total_harga << endl;
            cout << "Total diskon      : Rp." << diskon << endl;
            cout << "Total biaya       : Rp." << harga_bayar << endl;
            cout << "Tunai             : Rp." << uang_dibayarkan << endl;
            cout << "Kembalian         : Rp." << kembalian << endl;
            cout << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "===========================================================" << endl;
            cout << endl;
            cout << endl;
            break;
        }

        case 2:
        {
            cout << "Stok barang saat ini:" << endl;
            for (const auto &item : items)
            {
                cout << item.first << " - Stok: " << std::get<1>(item.second) << endl;
            }
            break;
        }

        case 3:
        {
            cout << "Masukkan nama barang yang akan diupdate stoknya: ";
            cin >> input;
            if (items.find(input) != items.end())
            {
                int newStock;
                cout << "Masukkan jumlah stok baru: ";
                cin >> newStock;
                std::get<1>(items[input]) = newStock;
                cout << "Stok barang '" << input << "' telah diupdate menjadi " << newStock << endl;
            }
            else
            {
                cout << "Barang tidak ditemukan." << endl;
            }
            break;
        }
        }
    } while (pil != 0);

    return 0;
}
