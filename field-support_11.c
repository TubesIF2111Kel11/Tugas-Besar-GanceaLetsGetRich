//id: field
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "player_11.h"

// Board

#include <stdio.h>
#include <stdlib.h>
#define nil NULL
#define fieldmax 19
typedef int address;
typedef char string[20];
typedef int infotype;
typedef struct{
		char name[20];			
		infotype own; //area ini dipunyai pemain ke berapa (0= belum dimiliki)
    	infotype compx; // area ini masuk kompleks berapa
    	long price; //area ini harganya berapa
	}field;
typedef struct{
		field idx[fieldmax];
	}Board;
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

void createfield(Board *X){ //INISIASI
	//Kompleks
	//Asumsi: soal salah ketik (kompleks terakhir adalah kompleks ke 5, bukan 6)
	int k=6;
	int x=0;
	(*X).idx[0].compx = x;
	(*X).idx[1].compx = 1;
	(*X).idx[2].compx = 1;
	(*X).idx[3].compx = 2;
	(*X).idx[4].compx = 2;
	(*X).idx[5].compx = x;
	(*X).idx[6].compx = k;
	(*X).idx[7].compx = x;
	(*X).idx[8].compx = 3;
	(*X).idx[9].compx = 3;
	(*X).idx[10].compx = x;
	(*X).idx[11].compx = 4;
	(*X).idx[12].compx = 4;
	(*X).idx[13].compx = x;
	(*X).idx[14].compx = k;
	(*X).idx[15].compx = x;
	(*X).idx[16].compx = x;
	(*X).idx[17].compx = k;
	(*X).idx[18].compx = 5;
	(*X).idx[19].compx = 5;
	
	//Kepemilikan
	//0 buat bukan punya siapa"
	int i;
	for (i=0; i <= fieldmax; i++){
		(*X).idx[i].own = 0;
	}
		
	//Harga
	(*X).idx[0].price = x;
	(*X).idx[1].price = 500000;
	(*X).idx[2].price = 750000;
	(*X).idx[3].price = 1200000;
	(*X).idx[4].price = 1500000;
	(*X).idx[5].price = x;
	(*X).idx[6].price = 3500000;
	(*X).idx[7].price = x;
	(*X).idx[8].price = 1900000;
	(*X).idx[9].price = 2300000;
	(*X).idx[10].price = x;
	(*X).idx[11].price = 2700000;
	(*X).idx[12].price = 3100000;
	(*X).idx[13].price = x;
	(*X).idx[14].price = 3500000;
	(*X).idx[15].price = x;
	(*X).idx[16].price = x;
	(*X).idx[17].price = 3500000;
	(*X).idx[18].price = 3500000;
	(*X).idx[19].price = 4000000;
	
	//Nama
	(*X).idx[0].name = "START";
	(*X).idx[1].name = "Oktagon";
	(*X).idx[2].name = "Comlabs";
	(*X).idx[3].name = "TVST";
	(*X).idx[4].name = "Telkom";
	(*X).idx[5].name = "PENJARA";
	(*X).idx[6].name = "K Bengkok";
	(*X).idx[7].name = "KESEMPATAN";
	(*X).idx[8].name = "GKU Barat";
	(*X).idx[9].name = "GKU Timur";
	(*X).idx[10].name = "UNDIAN";
	(*X).idx[11].name = "Aula Barat";
	(*X).idx[12].name = "Aula Timur";
	(*X).idx[13].name = "KESEMPATAN";
	(*X).idx[14].name = "K Barrack";	
	(*X).idx[15].name = "Bus_ITB";
	(*X).idx[16].name = "KESEMPATAN";
	(*X).idx[17].name = "K Borju";
	(*X).idx[18].name = "Labtek VIII";
	(*X).idx[19].name = "Labtek V";
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
	
void purchase(infotype no_field, infotype no_player, Board *X){
	printf("bacot\n");
	(*X).idx[no_field].own = no_player;
	aset(P)=aset(P)+(*X).idx[no_field].price;
}

void sell(infotype no_field, Board *X){
	printf("bacot\n");
	(*X).idx[no_field].own = 0;
	aset(P)=aset(P)-(*X).idx[no_field].price;
}

void rent(infotype no_field, infotype no_player, Board *X){
	printf("bacot\n");
	if ((*X).idx[no_field].own != no_player){
		//si no player kasih ..->price*30/100 ke si .own
	}
}

void turn(address P) {	
	int r,t;
	randdice(&r);
	ranndice(&t);
	pos(P) = pos(P)+r+t;
	if (pos(P)>fieldmax)&&(pos(P)!=0){
		pos(P) = pos(P)-fieldmax;
		balance(P) = balance(P)+1500000;
	}
	if (r==t){
		printf("bacot\n");
		turn(P);
	}
}

void building(infotype no_field, infotype no_player, Board *X){
	if ((*X).idx[no_field].own == 0){
		purchase(no_field, no_player, Board X);
	} else if ((*X).idx[no_field].own == no_player) {
	} else {
			rent(no_field, no_player, Board X);
		}
}
	
void castoff(infotype no_field, address P, Board *X){
	
	if (no_field==0){
		//do nothin
	}else if (no_field==5){
		Jail(P) = 3;
	}else if (no_field==7)||(no_field==13)||(no_field==16){
		chance();
	}else if (no_field==10){
		undian(P);
	}else{
		building(no_field, Index(P), &X);
	}
}
	
void jail(address P) {
	int r,t;
	randdice(&r);
	ranndice(&t);
	if ((r == t)||(Jail(P) = 0)) {
		Jail(P) = 0;
		turn(player);
	}else{
		Jail(P) = Jail(P) - 1;
	}
}
	
	
	
void randdice(int *r) {
	srand(time(NULL)); // Dipanggil hanya sekali, pindah ke main
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
	while((!(b)) && (i <= 19)) {
		if (strcmp(x.idx[i], c) == 1)
			b = 1;
		++i;
		}
	return b;
	}
	
int tranvbn(Board x, char c[20]) {
	// Kamus Lokal
	int i = 1;
	// Algoritma
	while ((strcmp(x.idx[i], c) != 1) && (i <= 19)) {
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
		case 1	:{
			pos(P) = 5;
			Jail(P) = 3;
		}
		case 2	:{
			freepark(P);
		}
		case 3	:{
			int a, b, temp;
			//lupa gimana teknik si pemain milih
			temp = (*X).idx[a].own;
			(*X).idx[a].own = (*X).idx[b].own;
			(*X).idx[b].own = temp;
		}
		case 4	:{
			//cast tictactoenya
		}
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

