#include <iostream>
using namespace std;

void hitung_gaji(int golongan, int jam_lembur)
{
    // Deklarasi variabel
    int gaji_pokok, transport, lembur, total_gaji, lembar;

    // Hitung gaji pokok dan transport
    switch (golongan)
    {
    case 1:
        gaji_pokok = 5500000;
        transport = 900000;
        lembar = 150000;
        break;
    case 2:
        gaji_pokok = 6500000;
        transport = 1200000;
        lembar = 180000;
        break;
    case 3:
        gaji_pokok = 7500000;
        transport = 1500000;
        lembar = 200000;
        break;
    default:
        cout << "Golongan tidak valid" << endl;
        return;
    }

    // Hitung lembur
    if (jam_lembur > 4)
    {
        cout << "Jam lembur tidak boleh lebih dari 4" << endl;
        return;
    }
    else
    {
        lembur = jam_lembur * lembar;
    }

    // Hitung total gaji
    total_gaji = gaji_pokok + transport + lembur;

    // Tampilkan hasil perhitungan
    cout << "Gaji Pokok: " << gaji_pokok << endl;
    cout << "Transport: " << transport << endl;
    cout << "Lembur: " << lembur << endl;
    cout << "Total Gaji: " << total_gaji << endl;
}

int main()
{
    // Membaca input golongan dan jam lembur
    int golongan, jam_lembur;
    cout << "Masukkan golongan: ";
    cin >> golongan;
    cout << "Masukkan jam lembur: ";
    cin >> jam_lembur;

    // Menghitung total gaji
    hitung_gaji(golongan, jam_lembur);

    return 0;
}