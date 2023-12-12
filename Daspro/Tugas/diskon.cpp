#include <iostream>

using namespace std;
int harga;
float diskon, total, rate;
char kode;

void hitung(int harga, float rate){
    diskon = rate * harga;
    total = harga - diskon;
    cout << "\nharga asli = " << harga << "\ndiskon = " << diskon << "\nTotal harga: " << total << endl;
}

int main()
{
    cout << "Program diskon" << endl;
    cout << "Masukkan harga barang: ";
    cin >> harga;
    cout << "Masukkan kode diskon: ";
    cin >> kode;
    cout << endl;
    switch (kode)
    {
    case 'H':
        rate = 0.5;
        hitung(harga, rate);
        break;

    case 'F':
        rate = 0.4;
        hitung(harga, rate);
        break;

    case 'T':
        rate = 0.33;
        hitung(harga, rate);
        break;

    case 'Q':
        rate = 0.25;
        hitung(harga, rate);
        break;

    case 'Z':
        cout << "Tidak ada diskon" << endl;
        break;

    default:
        cout << "Kode diskon salah" << endl;
        break;
    }
    return 0;
}