#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Petugas;
class Admin;

// =====================
// CLASS BUKU
// =====================
class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul << ", Penulis: " << penulis
             << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    // Friend class
    friend class Petugas;

    // Friend function untuk Admin
    friend void lihatStatusBuku(const Buku& b, const Admin& a);
};

// =====================
// CLASS PEMINJAM
// =====================
class Peminjam {
private:
    string nama;
    string id;
    int totalPinjaman;

public:
    Peminjam(string n, string i) : nama(n), id(i), totalPinjaman(0) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama << ", ID: " << id << ", Total Pinjaman: " << totalPinjaman << endl;
    }

    // Friend class
    friend class Petugas;

    // Friend function untuk Admin
    friend void lihatTotalPinjaman(const Peminjam& p, const Admin& a);
};

// =====================
// CLASS PETUGAS
// =====================
class Petugas {
private:
    string nama;
    string id;
    string levelAkses;

public:
    Petugas(string n, string i, string level) : nama(n), id(i), levelAkses(level) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku berhasil dipinjam oleh " << p->nama << endl;
        } else {
            cout << "Buku sudah dipinjam!" << endl;
        }
    }

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku berhasil dikembalikan oleh " << p->nama << endl;
        } else {
            cout << "Buku belum dipinjam!" << endl;
        }
    }

    void tampilkanInfo() {
        cout << "Petugas: " << nama << ", ID: " << id << ", Akses: " << levelAkses << endl;
    }

    // Friend class
    friend class Admin;
};

// =====================
// CLASS ADMIN
// =====================
class Admin {
public:
    void ubahLevelAkses(Petugas* p, const string& levelBaru) {
        p->levelAkses = levelBaru;
        cout << "Level akses petugas " << p->nama << " diubah menjadi " << levelBaru << endl;
    }

    void tampilkanStatistik(const Buku& b, const Peminjam& p) const {
        lihatStatusBuku(b, *this);
        lihatTotalPinjaman(p, *this);
    }

    string getNama() const {
        return "Wildhan Valerian";
    }
};

// =====================
// FRIEND FUNCTIONS
// =====================
void lihatStatusBuku(const Buku& b, const Admin& a) {
    cout << "[Admin " << a.getNama() << "] Status Buku: "
         << (b.dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

void lihatTotalPinjaman(const Peminjam& p, const Admin& a) {
    cout << "[Admin " << a.getNama() << "] Total Buku Dipinjam: " << p.totalPinjaman << endl;
}

// =====================
// MAIN FUNCTION
// =====================
int main() {
    Buku buku1("Wildhan Valerian", "Andrea Hirata");   // judul diubah jadi "Wildhan Valerian"
    Peminjam user1("Wildhan Valerian", "U123");       // nama diubah jadi "Wildhan Valerian"
    Petugas petugas1("Budi", "P001", "Standar");
    Admin admin1;

    // Menampilkan informasi awal
    buku1.tampilkanInfo();
    user1.tampilkanInfo();
    petugas1.tampilkanInfo();

    cout << "\n=== Proses Peminjaman ===\n";
    petugas1.prosesPinjam(&buku1, &user1);

    cout << "\n=== Statistik oleh Admin ===\n";
    admin1.tampilkanStatistik(buku1, user1);

    cout << "\n=== Ubah Level Akses Petugas oleh Admin ===\n";
    admin1.ubahLevelAkses(&petugas1, "Tinggi");

    cout << "\n=== Proses Pengembalian ===\n";
    petugas1.prosesKembali(&buku1, &user1);

