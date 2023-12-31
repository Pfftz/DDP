#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk menggunakan std::setw

using namespace std;

struct Booking
{
    string kelas;
    int jamMulai;
    int jamSelesai;
};

class Kelas
{
public:
    string nama;
    int kapasitas;
    vector<Booking> bookingList;
    vector<string> fasilitas;

    Kelas(string n, int k) : nama(n), kapasitas(k) {}

    bool isAvailable(int jamMulai, int jamSelesai)
    {
        for (const Booking &booking : bookingList)
        {
            if (jamMulai < booking.jamSelesai && jamSelesai > booking.jamMulai)
            {
                return false; // Kelas tidak tersedia pada rentang waktu tersebut
            }
        }
        return true; // Kelas tersedia pada rentang waktu tersebut
    }

    void displayAvailability()
    {
        cout << "Kelas " << nama << endl;
        cout << "Kapasitas: " << kapasitas << endl;
        cout << "Daftar jam tersedia:\n";

        int currentStart = 0;

        for (const Booking &booking : bookingList)
        {
            if (currentStart < booking.jamMulai)
            {
                cout << " (" << setw(2) << setfill('0') << currentStart << ":00 - " << setw(2) << setfill('0') << booking.jamMulai << ":00) ";
            }
            currentStart = booking.jamSelesai;
        }

        if (currentStart < 24)
        {
            cout << " (" << setw(2) << setfill('0') << currentStart << ":00 - 24:00)";
        }

        cout << endl;
    }

    void displayBookings()
    {
        cout << "Daftar Booking untuk Kelas " << nama << ":\n";
        for (const Booking &booking : bookingList)
        {
            cout << "Jam " << setw(2) << setfill('0') << booking.jamMulai << ":00 - " << setw(2) << setfill('0') << booking.jamSelesai << ":00\n";
        }
    }

    bool bookClass(int jamMulai, int jamSelesai)
    {
        if (jamMulai < 0 || jamSelesai > 24 || jamMulai >= jamSelesai)
        {
            cout << "Maaf, rentang waktu tidak valid.\n";
            return false;
        }

        if (isAvailable(jamMulai, jamSelesai))
        {
            Booking newBooking = {nama, jamMulai, jamSelesai};
            bookingList.push_back(newBooking);
            cout << "Booking berhasil untuk kelas " << nama << " dari jam " << jamMulai << ":00 sampai jam " << jamSelesai << ":00\n";
            return true;
        }
        else
        {
            cout << "Maaf, kelas tidak tersedia pada jam tersebut.\n";
            return false;
        }
    }
};

class Admin
{
public:
    vector<Kelas> classList; // Add this line
    vector<Kelas> fasilitas;

    void addClass()
    {
        string className;
        int classCapacity;

        cout << "Masukkan nama kelas: ";
        cin.ignore();
        getline(cin, className);

        cout << "Masukkan kapasitas kelas: ";
        cin >> classCapacity;

        classList.push_back(Kelas(className, classCapacity));
    }

    void deleteClass()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin dihapus: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                classList.erase(classList.begin() + i);
                cout << "Kelas berhasil dihapus.\n";
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }

    void editClass()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin diubah: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                cout << "Masukkan nama baru: ";
                getline(cin, classList[i].nama);
                cout << "Masukkan kapasitas baru: ";
                cin >> classList[i].kapasitas;
                cout << "Kelas berhasil diubah.\n";
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }

    void addFacility()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin ditambah fasilitas: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                string fasilitas;
                cout << "Masukkan fasilitas yang ingin ditambahkan: ";
                getline(cin, fasilitas);
                classList[i].fasilitas.push_back(fasilitas);
                cout << "Fasilitas berhasil ditambahkan.\n";
                return;
            }
        }
        cout << "Kelas tidak ditemukan" << endl;
    }
    void deleteFacility()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin dihapus fasilitas: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                string fasilitas;
                cout << "Masukkan fasilitas yang ingin dihapus: ";
                getline(cin, fasilitas);
                for (vector<Kelas>::size_type j = 0; j < classList[i].fasilitas.size(); j++)
                {
                    if (classList[i].fasilitas[j] == fasilitas)
                    {
                        classList[i].fasilitas.erase(classList[i].fasilitas.begin() + j);
                        cout << "Fasilitas berhasil dihapus.\n";
                        return;
                    }
                }
                cout << "Fasilitas tidak ditemukan.\n";
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }
    void deleteBooking()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin dihapus booking: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                int jamMulai, jamSelesai;
                cout << "Masukkan jam mulai booking yang ingin dihapus: ";
                cin >> jamMulai;
                cout << "Masukkan jam selesai booking yang ingin dihapus: ";
                cin >> jamSelesai;
                for (vector<Kelas>::size_type j = 0; j < classList[i].bookingList.size(); j++)
                {
                    if (classList[i].bookingList[j].jamMulai == jamMulai && classList[i].bookingList[j].jamSelesai == jamSelesai)
                    {
                        classList[i].bookingList.erase(classList[i].bookingList.begin() + j);
                        cout << "Booking berhasil dihapus.\n";
                        return;
                    }
                }
                cout << "Booking tidak ditemukan.\n";
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }
    void displayClassInfo()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin ditampilkan: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                classList[i].displayAvailability();
                cout << "Daftar fasilitas:\n";
                for (const string &fasilitas : classList[i].fasilitas)
                {
                    cout << fasilitas << endl;
                }
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }
    void displayBooking()
    {
        string nama;
        cout << "Masukkan nama kelas yang ingin ditampilkan booking: ";
        cin.ignore();
        getline(cin, nama);
        for (vector<Kelas>::size_type i = 0; i < classList.size(); i++)
        {
            if (classList[i].nama == nama)
            {
                classList[i].displayBookings();
                return;
            }
        }
        cout << "Kelas tidak ditemukan.\n";
    }
};

void displayClassInfo(Kelas &kelas)
{
    kelas.displayAvailability();
    cout << "Daftar Booking:\n";
    kelas.displayBookings();
}

void menuAdmin(Admin &admin)
{
    bool isLooping = true;
    int pilih;

    while (isLooping)
    {
        cout << " Selamat datang di OpenBO\n";
        cout << " 1. Tambah Kelas\n";
        cout << " 2. Hapus Kelas\n";
        cout << " 3. Ubah data Kelas\n";
        cout << " 4. Tambah fasilitas Kelas\n";
        cout << " 5. Hapus fasilitas Kelas\n";
        cout << " 6. Hapus Bookingan\n";
        cout << " 7. Lihat Daftar Kelas\n";
        cout << " 8. Lihat Daftar Booking\n";
        cout << " 0. Keluar\n";
        cout << " Pilih: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            admin.addClass();
            break;
        case 2:
            admin.deleteClass();
            break;
        case 3:
            admin.editClass();
            break;
        case 4:
            admin.addFacility();
            break;
        case 5:
            admin.deleteFacility();
            break;
        case 6:
            admin.deleteBooking();
            break;
        case 7:
            admin.displayClassInfo();
            break;
        case 8:
            admin.displayBooking();
            break;
        case 0:
            cout << "Program selesai.\n";
            isLooping = false;
            break;
        default:
            cout << "Pilihan tidak valid\n";
        }
    }
}

void menuUser(Admin &admin)
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Lihat Daftar Kelas dan Ketersediaan\n";
        cout << "2. Booking Kelas\n";
        cout << "3. Lihat Daftar Booking\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (Kelas &kelas : admin.classList)
            {
                displayClassInfo(kelas);
            }
            break;
        case 2:
        {
            int jamMulai, jamSelesai;
            string nama;
            cout << "Masukkan nama kelas yang ingin di booking: ";
            cin.ignore();
            getline(cin, nama);

            Kelas *kelas = nullptr;
            for (Kelas &k : admin.classList)
            {
                if (k.nama == nama)
                {
                    kelas = &k;
                    break;
                }
            }

            if (!kelas)
            {
                cout << "Kelas tidak ditemukan.\n";
                break;
            }

            cout << "Masukkan jam mulai booking: ";
            cin >> jamMulai;
            cout << "Masukkan jam selesai booking: ";
            cin >> jamSelesai;

            kelas->bookClass(jamMulai, jamSelesai);
            break;
        }
        case 3:
            cout << "Daftar Booking:\n";
            for (Kelas &kelas : admin.classList)
            {
                displayClassInfo(kelas);
            }
            break;
        case 0:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (choice != 0);
}

bool adminLogin()
{
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin")
    {
        cout << "Login berhasil.\n";
        return true;
    }
    else
    {
        cout << "Login gagal.\n";
        return false;
    }
}

bool userLogin()
{
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "user" && password == "user")
    {
        cout << "Login berhasil.\n";
        return true;
    }
    else
    {
        cout << "Login gagal.\n";
        return false;
    }
}

int main()
{
    Admin admin;
    int pilih;
    bool isLooping = true;
    while (isLooping)
    {
        cout << " Selamat datang di OpenBO\n";
        cout << " 1. Login Admin\n";
        cout << " 2. Login User\n";
        cout << " 0. Keluar\n";
        cout << " Pilih: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            if (adminLogin()) // Call the function here
            {
                menuAdmin(admin);
            }
            else
            {
                cout << " Anda tidak bisa mengakses menu admin\n";
            }
            break;
        case 2:
            if (userLogin()) // Call the function here
            {
                menuUser(admin);
            }
            else
            {
                cout << " Anda tidak bisa mengakses menu user\n";
            }
            break;
        case 0:
            cout << " Program selesai\n";
            isLooping = false;
            break;
        default:
            cout << " Pilihan tidak valid\n";
        }
    }
    return 0;
}
