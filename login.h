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

#ifndef login_h
#define login_h

// variable struct untuk login user
struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
};
struct admin{
	char username[25];
	char password[25];
};

// modul main 
int main();

// Modul Login
void login(char *status_member);

// modul signup
void signUp();

// modul menginput
void input(char ch[50]);

// modul masking
void masking(char teks[50]);

// modul untuk login sebagai admin
int loginAdmn();

#endif



