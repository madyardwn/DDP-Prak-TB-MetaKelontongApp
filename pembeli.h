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

#ifndef pembeli_h
#define pembeli_h

typedef struct{
  int nomor;
  char barang[100];
  float harga;
  int jumlah_beli;
  float total;
}laporan;

// Modul Pembeli
void pembelian();                         // Prosedur Transaksi Barang
void checkout(char *status_member);       // Prosedur Check-out (Laporan Pembelian)

#endif



