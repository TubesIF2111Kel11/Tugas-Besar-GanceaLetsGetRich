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
	char nameonboard[20];
	infotype own; //area ini dipunyai pemain ke berapa (0= belum dimiliki)
    	infotype compx; // area ini masuk kompleks berapa
    	long price; //area ini harganya berapa
	}field;
typedef struct{
		field idx[fieldmax];
	}Board;
infotype globalturn = 0;

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
	
		//nama yang dicetak
	(*X).idx[0 ].nameonboard = "   START   ";
	(*X).idx[1 ].nameonboard = "  OKTAGON  ";
	(*X).idx[2 ].nameonboard = "  COMLABS  ";
	(*X).idx[3 ].nameonboard = "    TVST   ";
	(*X).idx[4 ].nameonboard = "   TELKOM  ";
	(*X).idx[5 ].nameonboard = "  PENJARA  ";
	(*X).idx[6 ].nameonboard = " K_BENGKOK ";
	(*X).idx[7 ].nameonboard = " KESEMPATAN";
	(*X).idx[8 ].nameonboard = " GKU_BARAT ";
	(*X).idx[9 ].nameonboard = " GKU_TIMUR ";
	(*X).idx[10].nameonboard = "   UNDIAN  ";
	(*X).idx[11].nameonboard = " AULA_BARAT";
	(*X).idx[12].nameonboard = " AULA_TIMUR";
	(*X).idx[13].nameonboard = " KESEMPATAN";
	(*X).idx[14].nameonboard = " K_BARRACK ";	
	(*X).idx[15].nameonboard = "  BUS_ITB  ";
	(*X).idx[16].nameonboard = " KESEMPATAN";
	(*X).idx[17].nameonboard = "  K_BORJU  ";
	(*X).idx[18].nameonboard = "LABTEK_VIII";
	(*X).idx[19].nameonboard = "  LABTEK_V ";
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

void Showboard (Board X)
{
	printf(" _______________________________________________________________________ \n");
	printf("|           |           |           |           |           |           |\n");
	printf("|%s|%s|%s|%s|%s|%s|\n", X.idx[11].nameonboard, X.idx[12].nameonboard, X.idx[13].nameonboard, X.idx[14].nameonboard, X.idx[15].nameonboard, X.idx[16].nameonboard);
	printf("|           |           |           |           |           |           |\n");
	printf("|___________|___________|___________|___________|___________|___________|\n");
	printf("|           |                                               |           |\n");
	printf("|%s|                                               |%s|\n", X.idx[10].nameonboard, X.idx[17].nameonboard);
	printf("|           |                                               |           |\n");
	printf("|___________|                                               |___________|\n");
	printf("|           |                                               |           |\n");
	printf("|%s|                                               |%s|\n", X.idx[9].nameonboard, X.idx[18].nameonboard);
	printf("|           |                                               |           |\n");
	printf("|___________|                                               |___________|\n");
	printf("|           |                                               |           |\n");
	printf("|%s|                                               |%s|\n", X.idx[8].nameonboard, X.idx[19].nameonboard);
	printf("|           |                                               |           |\n");
	printf("|___________|                                               |___________|\n");
	printf("|           |                                               |           |\n");
	printf("|%s|                                               |%s|\n", X.idx[7].nameonboard, X.idx[20].nameonboard);
	printf("|           |                                               |           |\n");
	printf("|___________|_______________________________________________|___________|\n");
	printf("|           |           |           |           |           |           |\n");
	printf("|%s|%s|%s|%s|%s|%s|\n", X.idx[6].nameonboard, X.idx[5].nameonboard, X.idx[4].nameonboard, X.idx[3].nameonboard, X.idx[2].nameonboard, X.idx[1].nameonboard);
	printf("|           |           |           |           |           |           |\n");
	printf("|___________|___________|___________|___________|___________|___________|\n");
}
	
void purchase(infotype no_field, infotype no_player, Board *X){
	printf("Beli gedung? (Tekan 'Ya' untuk membeli gedung(case sensitive))");
	char yesorno[5];
	if (balance(P) >= (*X).idx[no_field].price){
	scanf ("%s", &yesorno);
	}
	switch(yesorno){
		case "Ya":{
			(*X).idx[no_field].own = no_player;
			aset(P)=aset(P)+(*X).idx[no_field].price;
			printf("bacot\n");
		}
		default :{;}
	}
}

void sell(infotype no_player, Board *X){
	
	(*X).idx[no_field].own = 0;
	aset(P)=aset(P)-(*X).idx[no_field].price;
}

void rent(infotype no_field, infotype no_player, Board *X){
	int rentrate = (*X).idx[no_field].price*30/100;
	//pemilik nambah duit
	//yang masuk ilang duit
	printf("bacot\n");// *pemasuk membayar uang sewa ke *pemilik sebesar *rentrate
}

void move(address P, Board X) {	
	int r,t;
	randdice(&r);
	ranndice(&t);
	pos(P) = pos(P)+r+t;
	printf("%s maju sebanya %d langkah!\n", Name(P), r+t);
	printf("%s berada pada Gedung %s\n", X.idx[pos(P)].name);
	castoff(pos(P),P,&X);
	if (pos(P)>fieldmax)&&(pos(P)!=0){
		pos(P) = pos(P)-fieldmax;
		balance(P) = balance(P)+1500000;
	}
	if (r==t){
		printf("%s mendapatkan dadu yang sama.\n"), Name(P);
		move(P);
	}
}

void building(infotype no_field, infotype no_player, Board *X){
	if ((*X).idx[no_field].own == 0){
		purchase(no_field, Board X);
	} else if ((*X).idx[no_field].own == no_player) {
	} else {
			rent(no_field, no_player, Board X);
		}
}
	
void jailed(address P){
	Jail(P) = 2;
	printf("bacot\n");
}

void castoff(infotype no_field, address P, Board *X){
	
	if (no_field==0){
		//do nothin
	}else if (no_field==5){
		jailed(P);
	}else if (no_field==7)||(no_field==13)||(no_field==16){
		chance();
	}else if (no_field==10){
		undian(P);
	}else{
		building(no_field, Index(P), &X);
	}
}
	
void turn(address P) {
	globalturn++;
	printf("-----Turn &d-----\n", globalturn);
	int r,t;
	printf("Giliran : %s \n", Name(P));
	printf("Tekan Enter untuk mengocok dadu!\n");
	scanf(); 
	randdice(&r);
	printf("Dadu 1 : %d\n", r);
	ranndice(&t);
	printf("Dadu 2 : %d\n", t);
	if ((r == t)||(Jail(P) = 0)) {
		Jail(P) = 0;
		move(player);
		printf("%s mendapatkan dadu yang sama\n",Name(P));
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
		castoff(pos(P),P,&x);
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
			jailed(P);
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

