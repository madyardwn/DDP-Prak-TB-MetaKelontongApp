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

#include <iostream>
#include <stdio.h>
#include "admin.h"
#include "pembeli.h"
#include "login.h"

int main(){
  // Deklarasi & Keadaan Awal
  fflush(stdin);
  system("cls");
	int pilihan;
	char member;

  // Menu
  while(1)
  {
    pilihan = 0;

    printf("===============================================================================================================\n");
    printf("===============|                  >>>>> META KELONTONG APPLICATION <<<<<                       |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Login\n");
    printf("  2. Sign Up\n");
    printf("  3. Guest\n");
    printf("  4. Admin\n");
    printf("  5. Exit\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                             MENU SECTION                                      |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: ");
    scanf("%d", &pilihan);
    fflush(stdin);

    switch(pilihan)
    {
      case 1:
      {
        system("cls");
        login(&member);
        if (member == 'Y')
        {
          pembelian();
          checkout(&member);
        }
        break;
      }
      case 2:
      {
        system("cls");
        signUp();
        break;
      }
      case 3:
      {
        system("cls");
        member = 'T';
        pembelian();
        checkout(&member);
        break;
      }
      case 4:
      {
        system("cls");
      	int check = loginAdmn();
      	if (check == 1){
      		admin();
  		}else{
  			main();
  		}

  	  }
        break;
      case 5:
      {
        exit(0);
      }
      default:
      {
        system("cls");
        printf("Pilihan Menu Tidak Valid!\n");
        printf("Silahkan Pilih Nomor Menu Yang Tersedia!\n\n");
        break;
      }
    }
  }
}



