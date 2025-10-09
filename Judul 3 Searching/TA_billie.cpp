#include <iostream>
#include <string>
using namespace std;

int main() {
    const int JUMLAH_SISWA = 10;
    string daftarSiswa[JUMLAH_SISWA] = {
        "Andi", "Budi", "Citra", "Dewi", "Eka",
        "Fajar", "Bambang", "Hadi", "Bambang", "Joko"
    };

    string cariNama;
    int counter = 0;

    cout << "=== PROGRAM PENCARIAN NAMA SISWA (SEQUENTIAL SEARCH) ===" << endl;
    cout << "Daftar siswa hari ini:" << endl;
    for (int i = 0; i < JUMLAH_SISWA; i++) {
        cout << i + 1 << ". " << daftarSiswa[i] << endl;
    }

    cout << "\nMasukkan nama siswa yang ingin dicari: ";
    getline(cin, cariNama);

    for (int i = 0; i < JUMLAH_SISWA; i++) {
        if (daftarSiswa[i] == cariNama) {
            counter++;
        }
    }

    if (counter > 0) {
        cout << "\nNama " << cariNama << " ditemukan sebanyak " << counter << " kali dalam daftar hadir." << endl;
    } else {
        cout << "\nNama " << cariNama << " tidak ditemukan dalam daftar hadir." << endl;
    }

    return 0;
}
