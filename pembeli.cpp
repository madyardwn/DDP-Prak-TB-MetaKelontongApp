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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "admin.h"
#include "pembeli.h"

/* PROGRAM TRANSAKSI */
void pembelian(){
  FILE *list_file;        // Variabel File List Barang Utama
  list daftar;     // Struct/Record Untuk List
  
  FILE *laporan_file;     // Variabel File Laporan Untuk Check Out
  laporan data;           // Struct/Record Untuk Check Out
  
  FILE *temp_file;        // Variabel Penampung File List Barang Sementara
  list temp;       // Struct/Record Untuk Temp List

  int pilihan;            // Pilihan Nomor Untuk Memilih Kategori Barang Yang Ingin Dibeli
  int nomor_beli;         // Pilihan Nomor Untuk Memilih Jenis Barang Yang Ingin Dibeli
  int jum_beli;           // Jumlah Banyaknya Barang Yang Ingin Dibeli
  char ulang;             // Pilihan Untuk Pengulangan
  char status;            // Status Valid Tidaknya Nomor Barang

  /* MELAKUKAN TRANSAKSI */
  laporan_file=fopen("laporan-transaksi.dat", "wb");
  while(1){
    //Keadaan Awal
    data.nomor = 0;
    data.jumlah_beli = 0;
    pilihan = 0;
    status = 'Y';
    
    if (ulang == 'Y'){
      laporan_file=fopen("laporan-transaksi.dat", "ab");
    }
    
    system("color 0E");
    printf("===============================================================================================================\n");
    printf("===============|                  >>>>> SELAMAT DATANG PEMBELI <<<<<                           |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                PILIH KATEGORI BARANG YANG INGIN DIBELI                        |===============\n");
    printf("===============================================================================================================\n\n");
    if (pilihan != 6){
      printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
      printf("\n");
    }

    while(1){
    /* PILIHAN KATEGORI BARANG YANG AKAN DIBELI */
      // PILIHAN MAKANAN RINGAN
      if (pilihan == 1){
        list_file=fopen("list_makanan_ringan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                     >>>>> LIST MAKANAN RINGAN <<<<<                           |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("  Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
      }
      
      // PILIHAN MINUMAN
      if (pilihan == 2){
        list_file=fopen("list_minuman.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                        >>>>> LIST MINUMAN <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("  Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
      }
      
      // PILIHAN BUMBU MASAKAN
      if (pilihan == 3){
        list_file=fopen("list_bumbu_masakan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                      >>>>> LIST BUMBU DAPUR <<<<<                             |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("  Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
      }
      
      // PILIHAN OBAT-OBATAN
      if (pilihan == 4){
        list_file=fopen("list_obat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                      >>>>> LIST OBAT-OBATAN <<<<<                             |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("  Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
      }
      
      // PILIHAN ALAT KEBERSIHAN & KESEHATAN
      if (pilihan == 5){
        list_file=fopen("list_alat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|              >>>>> LIST ALAT KEBERSIHAN & KESEHATAN <<<<<                     |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("  Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
      }

      // PILIHAN SELESAI
      if (pilihan == 6){
        system("cls");
        break;
      }

      // PILIHAN TIDAK VALID
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
      system("cls");
      ulang = 'Y';
      printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
      break;
      }
    /* LIST PILIHAN SELESAI */

    /* PEMILIHAN JENIS BARANG YANG AKAN DIBELI */
      printf("Silahkan Pilih Barang Yang Ingin Dibeli (^_^)\n");
      while(1)
      {
        // Memasukkan Nomor Barang Yang Ingin Dibeli
        printf("Nomor: "); scanf("%d", &data.nomor); fflush(stdin);
        // Validasi Nomor Jenis Barang
        rewind(list_file);
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == data.nomor)
          {
            break;
          }
        }
        if (daftar.nomor != data.nomor or daftar.nomor == NULL)
        {
          // Kembali Ke List Kategori Barang Awal
          ulang = 'Y';
          status = 'T';
          break;
        }
        
        // Memasukkan Jumlah Barang Yang Ingin Dibeli
        printf("Jumlah Beli: "); scanf("%d", &data.jumlah_beli); fflush(stdin);

      /* ANALISIS STOK */
        // Mengulang List File Dengan Rewind Untuk Dibaca & Membuka List Temp Untuk Tempat Sementara Menyimpan Pengurangan Stok
        rewind(list_file);
        temp_file=fopen("list-temp.dat", "wb");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == data.nomor)
          {
            // Jika Jumlah Barang Yang Dimasukkan Invalid Atau Stok Habis
            if (data.jumlah_beli > daftar.stok or daftar.stok <= 0 or data.jumlah_beli <= 0)
            {
            printf("Pembelian Gagal Karena Stok Tidak Mencukupi atau Invalid\n");
            // Jika Jumlah Barang Yang Dimasukkan Valid & Stok Mencukupi
            }else{
              daftar.stok = daftar.stok - data.jumlah_beli;
              
              // Memasukkan Transaksi Pembelian Ke Dalam Laporan Checkout
              data.nomor = data.nomor;
              strcpy(data.barang, daftar.barang);
              data.jumlah_beli = data.jumlah_beli;
              data.harga = daftar.harga;
              data.total = daftar.harga * data.jumlah_beli;
              fwrite(&data, sizeof(data), 1, laporan_file);
            }
          }
          // Memasukkan List Yang Stoknya Sudah Dikurangi Ke Dalam List Temp (Sementara)
          temp.nomor = daftar.nomor;
          strcpy(temp.barang, daftar.barang);
          temp.harga = daftar.harga;
          temp.stok = daftar.stok;
          fwrite(&temp, sizeof(temp), 1, temp_file);
        }
        fclose(temp_file);
        fclose(list_file);
        fclose(laporan_file);
      /* ANALISIS STOK SELESAI */
      
      /* REPLACE LIST FILE UTAMA DENGAN LIST FILE TEMP YANG STOKNYA SUDAH DIKURANGI */
        if (pilihan == 1){
          list_file=fopen("list_makanan_ringan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 2){
          list_file=fopen("list_minuman.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 3){
          list_file=fopen("list_bumbu_masakan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 4){
          list_file=fopen("list_obat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 5){
          list_file=fopen("list_alat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }
        fclose(list_file);
        fclose(temp_file);
      /* REPLACE LIST STOK PADA FILE UTAMA SELESAI */
        
        // Jika Ingin Membeli Barang Lain
        printf ("\nIngin Membeli Barang Lainnya (Y/T)? ");
        ulang = toupper(getche());
        
        // Kembali Ke Menu List
        if (ulang == 'Y' or ulang != 'Y')
        {
          break;
        }
      }
      // Kembali Ke Menu Kategori Barang
      if (ulang == 'Y' or ulang != 'Y'){
        system("cls");
        if (status == 'T')
        {
          printf("Nomor Barang Yang Kamu Masukkan Sebelumnya Tidak Valid!\n\n");
        }
        break;
      }
    }
    // Keluar Untuk Melanjutkan Ke Checkout
    if (ulang != 'Y' or pilihan == 6){
      break;
    }
  }
}





/* PROGRAM MEMPROSES & MENAMPILKAN HASIL PEMBELIAN */
void checkout(char *status_member){
  FILE *checkout_file;
  laporan data;
  int i = 1;
  float total_pembayaran = 0;
  float j, potongan;
  
  // Memasukkan Alamat
  char nama[50];
  char kecamatan[30];
  char kelurahan[30];
  char rt[5];
  char rw[5];
  char alamat[100];
  char nomor[10];
  
  system("color 0B");
  printf("===============================================================================================================\n");
  printf("===============|                  >>>>> DESTINASI / ALAMAT PEMBELI <<<<<                       |===============\n");
  printf("===============================================================================================================\n\n");
  printf("Contoh: Nama: ... | Alamat: ... | Nomor: ... | RT: ... | RW: ... | Kecamatan: ... | Kelurahan: ...\n\n");

  // Memasukkan Identitas Alamat Pembeli
  printf("  Nama: "); gets(nama); fflush(stdin);
  printf("  Alamat: Jl."); gets(alamat); fflush(stdin);
  printf("  Nomor: "); gets(nomor); fflush(stdin);
  printf("  RT: "); gets(rt); fflush(stdin);
  printf("  RW: "); gets(rw); fflush(stdin);
  printf("  Kecamatan: "); gets(kecamatan); fflush(stdin);
  printf("  Kelurahan: "); gets(kelurahan); fflush(stdin);
  system("cls");
  
  system("color 0A");
  checkout_file=fopen("laporan-transaksi.dat", "rb");
  printf("===============================================================================================================\n");
  printf("===============|                     >>>>> META KELONTONG CHECKOUT <<<<<                       |===============\n");
  printf("===============================================================================================================\n\n");
  printf("--------------------------------------------[DATA ALAMAT PEMBELI]----------------------------------------------\n");
  printf("|>  Nama      : %s\n", nama);
  printf("|>  Alamat    : Jl.%s\n", alamat);
  printf("|>  Nomor     : %s\n", nomor);
  printf("|>  RT        : %s\n", rt);
  printf("|>  RW        : %s\n", rw);
  printf("|>  Kecamatan : %s\n", kecamatan);
  printf("|>  Kelurahan : %s\n", kelurahan);
  printf("---------------------------------------------------------------------------------------------------------------\n\n");
  while(fread(&data, sizeof(data), 1, checkout_file))
  {
    data.nomor = i;
    printf("[%d]. Nama Barang: %-10s | Harga Satuan: Rp%-10.2f | Jumlah Beli: %-10d | Harga Total: Rp%.2f\n\n", data.nomor, data.barang, data.harga, data.jumlah_beli, data.total);
    total_pembayaran = total_pembayaran + data.total;
    i++;
  }
  printf("---------------------------------------------------------------------------------------------------------------\n");
  printf("     TOTAL PEMBAYARAN = Rp%.2f\n\n", total_pembayaran);
  if (*status_member == 'Y'){
    printf("     SELAMAT KAMU TERMASUK MEMBER!\n");
    potongan = diskon(j, &potongan);
    if (potongan < 1){
      total_pembayaran = total_pembayaran - (total_pembayaran * potongan);
      printf("     KAMU MENDAPATKAN DISKON SEBESAR %.0f PERSEN\n", potongan * 100);
    }else{
      if (total_pembayaran <= potongan){
        total_pembayaran = 0;
      }else{
        total_pembayaran = total_pembayaran - potongan;
      }
      printf("     KAMU MENDAPATKAN DISKON SEBESAR -Rp%.2f\n", potongan);
    }
    printf("     TOTAL PEMBAYARAN MENJADI = Rp%.2f\n\n", total_pembayaran);
  }
  
  printf("|> Kurir Akan Segera Berangkat Sesegara Mungkin!\n");
  printf("|> Pembayaran Akan Dilakukan Secara Langsung di Alamat Pembeli.\n\n");
  printf("===============================================================================================================\n");
  printf("===============|                            ~ TERIMA KASIH ~                                   |===============\n");
  printf("===============================================================================================================\n");
  printf("\n\n   Tekan enter untuk kembali...");
  getch();
  system("cls");
  system("color 07");
}
