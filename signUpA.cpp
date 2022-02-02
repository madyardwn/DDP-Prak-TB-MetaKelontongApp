/*
  PROGRAM META KELONTONG
  Deskripsi: Program Ini Berisi Mengenai Transaksi Simple
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

// melakukan penginputan
void input(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0; 
}

// masking password menjadi tidak terlihat
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

// variable struct untuk signup sebagai admin
struct admin{
	char username[25];
	char password[25];
};

// module untuk signup sebagai admin
int main(){
	FILE *fp;
	struct admin signup;
	char passwordkonf[50];
	system("cls");
	printf("\nSilahkan Masukkan Username dan Password untuk registrasi Admin\n\n");
	printf("\nEnter your username\t: ");
	input(signup.username);
	
	printf("\nMasukkan password\t: ");
	masking(signup.password);
	printf("\nkonfirmasi password\t: ");
	masking(passwordkonf);
	
	// membandingkan password
	if(strcmp(signup.password,passwordkonf)==0){
		
		// membuka file
		fp = fopen("Admin.dat","w");
		
		// menuliskan struct yang tertulis dalam file dalam hardisk
		fwrite(&signup,sizeof(struct admin),1,fp);
		if(fwrite == 0){
			printf("\n\nFile tidak ditemukan");
		}
		else {
			printf("\n\nRegistrasi berhasil!!, Username Anda %s\n\n", signup.username);
		}
		fclose(fp);
		printf("Tekan tombol pada keyboard untuk keluar...");
		getch();
	}
	else{
		printf("\n\nPassword yang Anda masukkan tidak sesuai\n");
		printf("\n\nTekan enter untuk kembali dan melakukan pengecekan ulang...");
		Beep(750,300);
		getch();
		main();
	}
	return 0;
}
