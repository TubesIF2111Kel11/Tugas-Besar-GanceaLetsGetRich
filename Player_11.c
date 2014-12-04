#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "player_11.h"
				
static FILE *textuser;
static FILE *hsdb;
				
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
		strcpy((*T).UserName[i], Blank);
		}
	}
	
void Register(UserTab *T, char c[20]){ 
	if (Neff == 100) 
		printf("Jumlah User telah mencapai batas maksimal\n");
	else{
		strcpy((*T).UserName, c);
		++(*T).Neff;
		Printf("Anda Berhasil Mendaftar\n");
		}
	}

void NextTurn(Queue *Q) {
	Head(*Q) = Next(Head(*Q));
	Tail(*Q) = Next(Tail(*Q));
	}
	
void init_player(Address P, char c[20]) {
	// Kamus Lokal
	// Address P;
	// bool b = 0;
	// Algoritma
	P = Head(*Q);
	strcpy(Nama(P), c);
	balance(P) = 10000000;
	aset(P) = balance(P);
	pos(P) = 0;
	}
	
int countplayer(Queue Q) {
	// Kamus Lokal
	int n = 0;
	bool b = 0;
	Address P;
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
	Address P = Head(Q);
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
	
void Login(Queue *Q, UserTab T, Address P, char c[20]) {
	// Algoritma
	Logon((&(*Q)), T);
	P = Tail(*Q);
	// init_player(P, c);
	}
	
void Logon(Queue *Q, UserTab T) {
	// Kamus Lokal
	address X, Hex;
	// Algoritma
	P = Head(*Q);
	if ((P) == Nil) {
		(P) = (address)malloc(sizeof(Pemain));
		if ((*P) != Nil) {
			Head(*Q) = (P);
			Tail(*Q) = (P);
			}
		}
	else {
		P = Tail(*Q);
		Hex = (address)malloc(sizeof(Pemain));
		P  = Next(P);
		P = Hex;
		Tail(*Q) = P;
		}
	}
	
void open() {
	//text = fopen(f, "ab+");
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
	for (i ; i <= T.neff; ++i) {
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
	while(!feof(text)) {
		fscanf(textuser, "%s", cc);
		strcpy((*T).UserName[i]), cc);
		++i;
		}
	*Neff = i;
	}
	
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
		strcpy((*SB)[i].NameRec, BlankScore);
		(*SB)[i].AssetsRec = 0;
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
	while (aset(Head(Q)) <= (*SB)[i].AssetsRec);
	for (j = 9; j < i; --j) {
		(*SB)[j].AssetsRec = (*SB)[j-1].AssetsRec;
		strcpy((*SB)[j].AssetsRec, (*SB)[j-1].AssetsRec);
		}
	strcpy((*SB)[i].NameRec, Name(Head(Q)));
	(*SB)[i].AssetsRec = aset(Head(Q));
	}
	
void PrintHS(ScoreBoard SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	printf("High Score Board\n\n");
	for (i; i <= 9; ++i) {
		printf("%d\t%s\t%ld\n", i, SB[i].NameRec, SB[i].AssetsRec);
		}
	}
	
	//3. load/save High Score ke eksternal	
	
void loadHS() {
	text = fopen ("Highscore.dbgc", "r+");
	if (textuser == NULL )
		textuser = fopen("Highscore.dbgc", "w+");
	} 
	
void saveHS(ScoreBoard SB) {
	// Kamus Lokal
	int i = 0;
	// Algoritma
	for (i; i <= 9; ++i) {
		fprintf(hsdb, "%s\t%ld", SB[i].NameRec, SB[i].AssetsRec);
		}
	}
	
void closeHS() {
	fclose(hsdb);
	}
	
