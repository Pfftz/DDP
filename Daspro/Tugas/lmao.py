def hitung_nilai_akhir(nilai_uts, nilai_uas, nilai_tugas):
    return (nilai_uts * 0.3) + (nilai_uas * 0.4) + (nilai_tugas * 0.3)

def tentukan_grade(nilai_akhir):
    if nilai_akhir >= 80:
        return "A"
    elif nilai_akhir >= 68:
        return "B"
    elif nilai_akhir >= 56:
        return "C"
    elif nilai_akhir >= 45:
        return "D"
    else:
        return "E"

def cek_kelulusan(nilai_akhir):
    return nilai_akhir >= 55

def main():
    nilai_uts = float(input("Masukkan nilai UTS: "))
    nilai_uas = float(input("Masukkan nilai UAS: "))
    nilai_tugas = float(input("Masukkan nilai Tugas: "))

    nilai_akhir = hitung_nilai_akhir(nilai_uts, nilai_uas, nilai_tugas)
    grade = tentukan_grade(nilai_akhir)
    lulus = cek_kelulusan(nilai_akhir)

    print("Nilai akhir:", nilai_akhir)
    print("Grade:", grade)
    print("Kelulusan:", lulus)

if __name__ == "__main__":
    main()
