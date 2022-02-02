/*
  PROGRAM META KELONTONG
  Deskripsi: Program Ini Berisi Mengenai Monitoring danTransaksi
  Dalam Sebuah Toko Kelontong Sederhana.
  Dibuat Oleh:
    - Achmadya Ridwan Ilyawan  : 211511001
    - Fahmi Ahmad Fadilah      : 211511013
    - Muhammad Zidan Hidayat   : 211511026
  Kelas: 1A
  Program Studi: D3 - Teknik Informatika
  Jurusan: Teknik Komputer & Informatika
*/

#ifndef admin_h
#define admin_H

typedef struct{
  int nomor;
  char barang[100];
  float harga;
  int stok;
}list;

// Modul Admin
int admin();                              // Menampilkan Menu Admin
void entry_data();                        // Prosedur Entry Data
void delete_data();                        // Prosedur Delete Data
void cek_data();                          // Prosedur Cek Data
void reset_data();                        // Prosedur Reset Data
void stok_data();                         // Prosedur Update Stok
void diskon_data();                       // Prosedur Update Diskon
float diskon(float i, float *potongan);   // Fungsi Menyimpan Hasil Diskon Pada File

#endif
