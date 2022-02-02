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

// Penginputan
void input(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1] = 0; 
}

// masking passowrd menjadi tidak terlihat
void masking(char teks[50]){
	int i=0;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER){
			teks[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else if(ch == TAB || ch == SPACE){
			continue;
		}
		else{
			teks[i++] = ch;
			printf("* \b");
		}
	}
}

// Signup untuk user
void signUp(){
	FILE *fp;
	struct user member;
	char passwordkonf[50];
	
	while(1)
  {
    fflush(stdin);
    system("cls");
  	printf("\nMasukkan nama lengkap\t: ");
  	input(member.fullName);
  	fflush(stdin);

  	printf("\nMasukkan Username\t: ");
  	input(member.username);
  	fflush(stdin);

  	printf("\nMasukkan password\t: ");
  	masking(member.password);
  	fflush(stdin);
  	
  	printf("\nkonfirmasi password\t: ");
  	masking(passwordkonf);
  	fflush(stdin);

  	// membandingkan 2 password yang telah di ketik
  	if(!strcmp(member.password,passwordkonf)){

  		// membuka file
  		fp = fopen("Users.dat","a+");

  		// menuliskan isi struct ke file dalam hardisk
  		fwrite(&member,sizeof(struct user),1,fp);
  		if(fwrite == 0){
  			printf("\n\nFile tidak ditemukan");
  		}
  		else {
  			printf("\n\nRegistrasi berhasil!!, Username Anda %s\n\n", member.username);
  		}
  		fclose(fp);
  		printf("Tekan tombol pada keyboard untuk kembali...");
  		getch();
  		break;
  	}
  	else{
  		printf("\n\nPassword yang Anda masukkan tidak sesuai\n");
  		printf("\n\nTekan enter untuk kembali dan melakukan pengecekan ulang...");
  		Beep(750,300);
  		getch();
  		break;
  	}
  }
  system("cls");
}

// Login untuk user
void login(char *status_member){
	FILE *fp;
	char uname[50],pword[50];
	struct user usr;
	int usrFound = 0;
	
	while(1)
  {
    fflush(stdin);
    printf("\nSilahkan Masukkan Username dan Password Anda untuk Login sebagai member\n\n");
  	printf("\nUsername\t: ");
  	input(uname);
  	fflush(stdin);
  	printf("Password\t: ");
  	masking(pword);
  	fflush(stdin);

  	// membuka file
  	fp = fopen("Users.dat","r");

  	// membaca struct dalam file hingga match dengan yang diketikan
  	while(fread(&usr,sizeof(struct user),1,fp)){
  		if(strcmp(usr.username,uname)==0){
  			if(strcmp(usr.password,pword)==0){
  				system("cls");
  				printf("\n\t\t\t\t\t---INFORMASI AKUN---");
  				printf("\n|Username\t: %s",usr.username);
  				printf("\n|Nama Lengkap\t: %s",usr.fullName);
  				// printf("\n|Email\t\t: %s",usr.email);
  				printf("\n\nTekan enter untuk melanjutkan ...");
  				getch();
          *status_member = 'Y';
  				system("cls");
  			}
  			else {
  				printf("\n\nPassword yang Anda masukkan salah");
  				printf("\nHubungi kami untuk informasi lebih lanjut cs@metakelontong.com\n");
  				printf("\n\nTekan enter untuk kembali ...\n\n");
  				Beep(800,300);
  				getch();
  				system("cls");
  				*status_member = 'T';
  				break;
  			}
  			usrFound = 1;
  		}
  	}
  	if(!usrFound){
  		printf("\n\nUsername belum terdaftar!");
  		Beep(800,300);
  		printf("\n\ntekan enter untuk kembali...");
  		getch();
  	}
    fclose(fp);
    fflush(stdin);
    system("cls");
    break;
  }
}
	

	
