//id: field

// props

typedef struct {
				int Kompleks;
				char Gedung[20];
				longint harga;
				} properti;

// Board
typedef struct{
				properti petak[20];
				}Board;

#include <stdio.h>
#include <stdlib.h>
#define nil NULL
#define fieldmax 19
typedef int address;
typedef char string[20];
typedef int infotype;
typedef struct{
		infotype own[fieldmax]; //area ini dipunyai pemain ke berapa (0= belum dimiliki)
    	infotype compx[fieldmax]; // area ini masuk kompleks berapa
    	infotype price[fieldmax]; //area ini harganya berapa
	}
	field;
void createfield(field *X);
void printfield(infotype no_field);
void purchase(infotype no_field, infotype no_player, field *X); //Field relatednya doang
void sell(infotype no_field, field *X); //Field relatednya doang

int main(){
	createfield(&X);
	infotype n;
	scanf ("%d", &n);
	printfield(n);
	return 0;
}

void createfield(field *X){ //INISIASI
	//Kompleks
	//Asumsi: soalnya salah ketik (kompleks terakhir adalah kompleks ke 5, bukan 6)
	int k=6;
	int x=0;
	(*X).compx[0] = x;
	(*X).compx[1] = 1;
	(*X).compx[2] = 1;
	(*X).compx[3] = 2;
	(*X).compx[4] = 2;
	(*X).compx[5] = x;
	(*X).compx[6] = k;
	(*X).compx[7] = x;
	(*X).compx[8] = 3;
	(*X).compx[9] = 3;
	(*X).compx[10] = x;
	(*X).compx[11] = 4;
	(*X).compx[12] = 4;
	(*X).compx[13] = x;
	(*X).compx[14] = k;
	(*X).compx[15] = x;
	(*X).compx[16] = x;
	(*X).compx[17] = k;
	(*X).compx[18] = 5;
	(*X).compx[19] = 5;
	
	//Kepemilikan
	//0 buat bukan punya siapa"
	int i;
	for (i=0; i <= fieldmax; i++){
		(*X).own[i] = 0;
	}
		
	//Harga
	(*X).price[0] = x;
	(*X).price[1] = 500;
	(*X).price[2] = 750;
	(*X).price[3] = 1200;
	(*X).price[4] = 1500;
	(*X).price[5] = x;
	(*X).price[6] = 3500;
	(*X).price[7] = x;
	(*X).price[8] = 1900;
	(*X).price[9] = 2300;
	(*X).price[10] = x;
	(*X).price[11] = 2700;
	(*X).price[12] = 3100;
	(*X).price[13] = x;
	(*X).price[14] = 3500;
	(*X).price[15] = x;
	(*X).price[16] = x;
	(*X).price[17] = 3500;
	(*X).price[18] = 3500;
	(*X).price[19] = 4000;
	
}

void printfield(infotype no_field){
	switch(no_field){
		case 0 : printf("START");
		case 1 : printf("Oktagon");
		case 2 : printf("Comlabs");
		case 3 : printf("TVST");
		case 4 : printf("Telkom");
		case 5 : printf("PENJARA");
		case 6 : printf("K Bengkok");
		case 7 : printf("KESEMPATAN");
		case 8 : printf("GKU Barat");
		case 9 : printf("GKU Timur");
		case 10: printf("UNDIAN");
		case 11: printf("Aula Barat");
		case 12: printf("Aula Timur");
		case 13: printf("KESEMPATAN");
		case 14: printf("K Barrack");	
		case 15: printf("Bus_ITB");
		case 16: printf("KESEMPATAN");
		case 17: printf("K Borju");
		case 18: printf("Labtek VIII");
		case 19: printf("Labtek V");
		default: ;
	}
}
	
void purchase(infotype no_field, infotype no_player, field *X){
	(*X).own[no_field] = no_player;
}

void sell(infotype no_field, field *X){
	(*X).own[no_field] = 0;
}

void jail() {
	// skip 3 turn
	int r,t;
	randdice(&r);
	ranndice(&t);
	if (r == t) {
		// Jalan
		}
	}
	
	
	
void randdice(int *r) {
	//#include <time.h>
	//#include <stdlib.h>

	// srand(time(NULL)); // Dipanggil hanya sekali, pindah ke main
	int r = rand() % 6 + 1;
	}

void freepark(address P) {
	if (travb(x, c)) {
		pos(P) = travbn(x, c);
		printf("bacot\n");
		}
	else {
		printf("bacot\n");
		}
	}
		
bool travb(Board x, char c[20]) {
	// Kamus Lokal
	int i = 1;
	bool b = 0;
	// Algoritma
	while((!(b)) && (i <= 20)) {
		if (strcmp(x.petak[i], c) == 1)
			b = 1;
		++i;
		}
	return b;
	}
	
int tranvbn(Board x, char c[20]) {
	// Kamus Lokal
	int i = 1;
	// Algoritma
	while ((strcmp(x.petak[i], c) != 1) && (i <= 20)) {
		++i;
		}
	return i;
	}

void init_chance(chances *ch) { // Inisialisasi array kesempatan
	strcpy((*ch)[1].Type, "Masuk Penjara");
	strcpy((*ch)[2].Type, "Tiket Bus");
	strcpy((*ch)[3].Type, "Tukar Gedung");
	strcpy((*ch)[4].Type, "Mini Game TicTacToe");
	}
	
void chance(chances ch) {
	// Kamus Lokal
	int x;
	// Algoritma
	x = rand() & 4;
	switch (x) {
		case 1	:	// isi dengan fungsi board
		case 2	:
		case 3	:
		case 4	:
		default	:
		}
	}
	
void undian(Address *P) {
	char q[5];
	char w[2][4];
	int x,y;
	bool b,c ;
	scanf("%s", &q);
	y = 1;
	strcpy(w[1] , "Head");
	strcpy(w[2], "Tail");
	c = 0;
	b = 0;
	do {
		printf("Taruhan Anda (Head/Tail) : ");
		scanf("&s", &q);
		if ((strcmp(q, w[1]) != 1) && (strcmp(q, w[2]) != 1)) {
			// c = 1;
			printf("Input salah! Mohon ulangi! (case sensitive)\n");
			}
		else {
			x = rand() % 2;
			y += 1;
			if ((strcmp(q, w[1]) != 1) || (strcmp(q, w[2]) != 1)) {
				b = 1;
				y = 1;
				}
			}
		}
	while ((y != 4) && (!(b)));
	balance(P) *= y;
	}
