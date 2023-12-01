#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk menggunakan std::setw

using namespace std;

struct Booking {
    string kelas;
    int jamMulai;
    int jamSelesai;
};

class Kelas {
public:
    string nama;
    int kapasitas;
    vector<Booking> bookingList;

    Kelas(string n, int k) : nama(n), kapasitas(k) {}

    bool isAvailable(int jamMulai, int jamSelesai) {
        for (const Booking& booking : bookingList) {
            if (jamMulai < booking.jamSelesai && jamSelesai > booking.jamMulai) {
                return false; // Kelas tidak tersedia pada rentang waktu tersebut
            }
        }
        return true; // Kelas tersedia pada rentang waktu tersebut
    }

    void displayAvailability() {
        cout << "Kelas " << nama << endl;
        cout << "Kapasitas: " << kapasitas << endl;
        cout << "Daftar jam tersedia:\n";

        int currentStart = 0;

        for (const Booking& booking : bookingList) {
            if (currentStart < booking.jamMulai) {
                cout << " (" << setw(2) << setfill('0') << currentStart << ":00 - " << setw(2) << setfill('0') << booking.jamMulai << ":00) ";
            }
            currentStart = booking.jamSelesai;
        }

        if (currentStart < 24) {
            cout << " (" << setw(2) << setfill('0') << currentStart << ":00 - 24:00)";
        }

        cout << endl;
    }

    void displayBookings() {
        cout << "Daftar Booking untuk Kelas " << nama << ":\n";
        for (const Booking& booking : bookingList) {
            cout << "Jam " << setw(2) << setfill('0') << booking.jamMulai << ":00 - " << setw(2) << setfill('0') << booking.jamSelesai << ":00\n";
        }
    }

    bool bookClass(int jamMulai, int jamSelesai) {
        if (jamMulai < 0 || jamSelesai > 24 || jamMulai >= jamSelesai) {
            cout << "Maaf, rentang waktu tidak valid.\n";
            return false;
        }

        if (isAvailable(jamMulai, jamSelesai)) {
            Booking newBooking = {nama, jamMulai, jamSelesai};
            bookingList.push_back(newBooking);
            cout << "Booking berhasil untuk kelas " << nama << " dari jam " << jamMulai << ":00 sampai jam " << jamSelesai << ":00\n";
            return true;
        } else {
            cout << "Maaf, kelas tidak tersedia pada jam tersebut.\n";
            return false;
        }
    }
};

int main() {
    Kelas kelasA("A", 30);
    Kelas kelasB("B", 25);

    int choice;
    string kelas; // Declare kelas outside the switch statement
    do {
        cout << "\nMenu:\n";
        cout << "1. Lihat Daftar Kelas dan Ketersediaan\n";
        cout << "2. Booking Kelas\n";
        cout << "3. Lihat Daftar Booking\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                kelasA.displayAvailability();
                kelasB.displayAvailability();
                cout << "Daftar Booking:\n";
                kelasA.displayBookings();
                kelasB.displayBookings();
                break;
            case 2:
                int jamMulai, jamSelesai;
                cout << "Masukkan kelas yang ingin di booking: ";
                cin.ignore();
                getline(cin, kelas);

                if (kelas != "A" && kelas != "B") {
                    cout << "Kelas tidak valid.\n";
                    break;
                }

                cout << "Masukkan jam mulai booking: ";
                cin >> jamMulai;
                cout << "Masukkan jam selesai booking: ";
                cin >> jamSelesai;

                if (kelas == "A") {
                    kelasA.bookClass(jamMulai, jamSelesai);
                } else {
                    kelasB.bookClass(jamMulai, jamSelesai);
                }
                break;
            case 3:
			    cout << "Daftar Booking:\n";
                kelasA.displayBookings();
                kelasB.displayBookings();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (choice != 0);

    return 0;
}

