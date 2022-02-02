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
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define SPACE 32
#include "login.h"

// login untuk admin
int loginAdmn(){
	FILE *fp;
	char unameA[50],pwordA[50];
	struct admin usrA;
	int usrFoundA = 0;
	printf("\nSilahkan Masukkan Username dan Password Anda untuk Login sebagai Admin\n\n");
	printf("\nUsername\t: ");
	input(unameA);
	printf("Password\t: ");
	masking(pwordA);
	
	// membuka file
	fp = fopen("Admin.dat","r");
	
	// membaca struct dalam file hingga match dengan yang diketikan
	while(fread(&usrA,sizeof(struct admin),1,fp)){
		if(strcmp(usrA.username,unameA)==0){
			if(strcmp(usrA.password,pwordA)==0){
				system("cls");
				printf("Anda berhasil Login sebagai Admin");
				printf("\n\nTekan enter untuk melanjutkan ...");
				getch();
				system("cls");
				return 1;
			}
			else {
				printf("\n\nPassword yang Anda masukkan salah");
				printf("\n\nTekan enter untuk kembali ...\n\n");						
				Beep(800,300);
				getch();
				main();
				return 0;
			}
			usrFoundA = 1;
		}
	}
	if(!usrFoundA){
		printf("\n admin belum terdaftar!");
		Beep(800,300);
		printf("\n\ntekan entar untuk kembali...");
		getch();
		main();
		return 0;
	}
	fclose(fp);
	system("cls");
	return 0;
}
