#include <iostream>
using namespace std;

float hitung_nilai_akhir(float nilai_uts, float nilai_uas, float nilai_tugas)
{
    return (nilai_uts * 0.3) + (nilai_uas * 0.4) + (nilai_tugas * 0.3);
}

char tentukan_grade(float nilai_akhir)
{
    if (nilai_akhir >= 80)
    {
        return 'A';
    }
    else if (nilai_akhir >= 68)
    {
        return 'B';
    }
    else if (nilai_akhir >= 56)
    {
        return 'C';
    }
    else if (nilai_akhir >= 45)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

void cek_kelulusan(float nilai_akhir)
{
    if(nilai_akhir >= 55){
        cout << "Anda lulus" << endl;
    }else{
        cout << "Anda tidak lulus" << endl;
    }
}

int main()
{
    float nilai_uts, nilai_uas, nilai_tugas;

    cout << "Masukkan nilai UTS: ";
    cin >> nilai_uts;
    cout << "Masukkan nilai UAS: ";
    cin >> nilai_uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> nilai_tugas;

    float nilai_akhir = hitung_nilai_akhir(nilai_uts, nilai_uas, nilai_tugas);
    char grade = tentukan_grade(nilai_akhir);
    
    cout << "Nilai akhir: " << nilai_akhir << endl;
    cout << "Grade: " << grade << endl;
    cout << "Kelulusan: " << endl;
    cek_kelulusan(nilai_akhir);

    return 0;
}
