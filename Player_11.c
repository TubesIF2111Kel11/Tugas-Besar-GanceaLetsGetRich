#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "player_11.h"
#include <stddef.h>
				
static FILE *textuser;
static FILE *hsdb;
static FILE *ingameplayer;
				
// Registrasi

bool IsNP(Queue *Q){
	return ((Head(*Q) == Nil) && (Tail(*Q) = Nil));
	}

void CreateReg(Queue *Q) {
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	}

void CreateUTEmpty(UserTab *T) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	(*T).Neff = 0;
	for (i ; i <= 100; ++i) {
		(*T).UserName[i][1] = Blank;
		}
	}
	
void Register(UserTab *T, char c[20]){ 
	// Kamus Lokal
	int i = 0;
	// Algoritma
	if ((*T).Neff == 100) 
		printf("Jumlah User telah mencapai batas maksimal\n");
	else{
		// strcpy((*T).UserName, c);
		++(*T).Neff;
		do {
			(*T).UserName[(*T).Neff][i] = c[i];
			}
		while(i<=19);			
		printf("Anda Berhasil Mendaftar\n");
		}
	}
	
// Konstruksi list-queue pemain

void NextTurn(Queue *Q) {
	Head(*Q) = Next(Head(*Q));
	Tail(*Q) = Next(Tail(*Q));
	}
	
void init_player(address P, char c[20]) {
	// Kamus Lokal
	// address P;
	// bool b = 0;
	// Algoritma
	strcpy(Name(P), c);
	balance(P) = 10000000;
	aset(P) = balance(P);
	pos(P) = 0;
	}
	
int countplayer(Queue Q) {
	// Kamus Lokal
	int n = 0;
	bool b = 0;
	address P;
	// Algoritma
	if (IsNP) 
		return 0;
	else {
		do {
			++n;
			if ( P == Tail(Q)) 
				b = 1;
			P = Next(P);
			}
		while (!(b));
		}
	return n;
	}
	
bool NCmp(UserTab T, char c[20]) {
	// Kamus Lokal
	// address P = Head(Q);
	int i = 1;
	bool b = 0;
	// Algoritma
	while ((!(b)) && (i <= T.Neff)) {
		if (strcasecmp(T.UserName[1], c) == 1) 
			b = 1;
		++i;
		}
	return (b);
	}
	
void Login(Queue *Q, address P) {
	// Algoritma
	Logon((&(*Q)));
	P = Tail(*Q);
	}
	
void Logon(Queue *Q) {
	// Kamus Lokal
	address X, Hex;
	// Algoritma
	X = Head(*Q);
	if ((X) == Nil) {
		X = (address)malloc(sizeof(Pemain));
		if (X != Nil) {
			Head(*Q) = (X);
			Tail(*Q) = (X);
			}
		}
	else {
		X = Tail(*Q);
		Hex = (address)malloc(sizeof(Pemain));
		Hex  = Next(X);
		Tail(*Q) = Hex;
		}
	}
	
// File I/O untuk registrasi
	
void open() {
	textuser = fopen ("accountdb.txt", "r+");
	if (textuser == NULL )
		textuser = fopen("accountdb.txt", "w+");
	}

void close() {
	fclose(textuser);
	}

/* void read() {
	fscanf(textuser, "%s", cc);
	} */
		
void write(char c[20], UserTab T) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	for (i ; i <= T.Neff; ++i) {
		fprintf(textuser, "%s", c);
		}
	}	

void f2arrcpy(UserTab *T) {
	// Kamus Lokal
	int i;
	char cc[20];
	// Algoritma
	i = 0;
	(*T).Neff = 0;
	while(!feof(textuser)) {
		fscanf(textuser, "%s", cc);
		strcpy((*T).UserName[i], cc);
		++i;
		}
	(*T).Neff = i;
	}
	
// File I/O untuk list-queue pemain

bool emptygame() {
	// Kamus Lokal
	char cc[20];
	// Algoritma
	return(fgets(cc, 20, ingameplayer) == NULL);
	}

void initgame() {
	ingameplayer = fopen ("game.dbgc", "r+");
	if (ingameplayer == NULL )
		ingameplayer = fopen("game.dbgc", "w+");
	}
	
void savegame(Queue Q) {
	// Kamus Lokal
	address P;
	int i = 1;
	// Algoritma
	P = Head(Q);
	for (i; i <= countplayer(Q); ++i) {
		fprintf(ingameplayer, "%s\t%ld\t%ld\t%d", Name(P), balance(P), aset(P), pos(P));
		P = Next(P);
		}
	}
	
void loadgame(Queue *Q, address P) {
	// Kamus Lokal
	int i = 1;
	char c[20];
	long bal, ast;
	int post;
	// Algoritma
	for (i; i <= countplayer(*Q); ++i) {
		fscanf(ingameplayer,"%s\t%ld\t%ld\t%d", &c, &bal, &ast, &post);
		Login((&(*Q)), P);
		strcpy(Name(P), c);
		balance(P) = bal;
		aset(P) = ast;
		pos(P) = post;
		}
	}
	
// Finalisasi circular list-queue pemain

void finlist(Queue *Q) {
	Next(Tail(*Q)) = Head(*Q);
	}
	
// High Score Board
	
	// 1. Konstruktor
void createHSB(ScoreBoard *SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	for (i; i <= 9; ++i) {
		strcpy((*SB).HS[i].NameRec, BlankScore);
		(*SB).HS[i].AssetsRec = 0;
		}
	}
	
	// 2. Fungsi Utama
	
void AddHS(ScoreBoard *SB, Queue Q) {
	// Kamus Lokal
	int i, j;
	// Algoritma
	i = 0;
	j = 9;
	do {
		++i;
		}
	while (aset(Head(Q)) <= (*SB).HS[i].AssetsRec);
	for (j = 9; j < i; --j) {
		(*SB).HS[j].AssetsRec = (*SB).HS[j-1].AssetsRec;
		strcpy((*SB).HS[j].NameRec, (*SB).HS[j-1].NameRec);
		}
	strcpy((*SB).HS[i].NameRec, Name(Head(Q)));
	(*SB).HS[i].AssetsRec = aset(Head(Q));
	}
	
void PrintHS(ScoreBoard SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	printf("High Score Board\n\n");
	for (i; i <= 9; ++i) {
		printf("%d\t%s\t%ld\n", i, SB.HS[i].NameRec, SB.HS[i].AssetsRec);
		}
	}
	
void ftoHS(ScoreBoard *SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	for (i; i <= 9; ++i) {
		fscanf(hsdb, "%s\t%ld", (*SB).HS[i].NameRec, (*SB).HS[i].AssetsRec);
		}
	}
	
	//3. load/save High Score ke eksternal	
	
void loadHS() {
	// Kamus Lokal
	hsdb = fopen ("Highscore.dbgc", "r+");
	if (hsdb == NULL )
		hsdb = fopen("Highscore.dbgc", "w+");
	} 
	
void saveHS(ScoreBoard SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	for (i; i <= 9; ++i) {
		fprintf(hsdb, "%s\t%ld", SB.HS[i].NameRec, SB.HS[i].AssetsRec);
		}
	}
	
void closeHS() {
	fclose(hsdb);
	}
	
	
