// main file

#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "player.h"

UserTab T;
Queue Q;
char c[20];
address P;
static FILE *textuser;
char l;
int k, y, nump, i;
ScoreBoard SB;
static FILE *hsdb;
static FILE *ingameplayer;


int main() {
	i = 0;
	srand(time(0));
	open();
	//f2arrcpy(&a, &Neff);
	while(fgets(a, 20, text) != NULL) {
		read();
		strcpy(((a)[i]), cc);
		++i;
		}
	Neff = i;
	do {
		printf("Main Menu\n");
		printf("1. Register\n");
		printf("2. Login\n");
		printf("3. About\n");
		printf("4. Keluar\n");
		printf("Pilihan Anda : ");
		scanf("%d", &k);
		switch (k) {
			case 1 :	printf("--Register--\n");
						do {
							printf("Masukkan User Name yang ingin digunakan\n");
							scanf("%s", &c);
							if (NCmp(T, c))
								printf("Nama sudah digunakan\n");
							else
								Register(&T, c);
							}
						while (Ncmp(T, c));
						break;							
			case 2 :	printf("--Login--\n");
						printf("Masukkan User Name\n");
						scanf("%s", &c);
						if (NCmp(T, c)) {
							Login(&Q,P);
							printf("Login Berhasil/n");
							loadHS();
							ftoHS(&SB);
							initgame();
							}
							do {
								printf("Preparation Menu\n");
								printf("1. New Game\n");
								printf("2. Load Game\n");
								printf("3. High Score Board\n");
								printf("4. Log Out\n");
								printf("Pilihan Anda : ");
								scanf("%d", &y);
								switch (y) {
									case 1 :	do {
													printf("Jumlah Pemain\n");
													scanf("%d", &nump);
													if ((nump > 4) || (nump < 2))
														printf("Jumlah pemain harus kurang dari 2 atau lebih dari 4\n");
													}
												while ((nump > 4) || (nump < 2));
												printf("Nama Pemain 1 : %s\n", Name(Tail(Q)));
												for (i = 2; i <= nump; ++i) {
													printf("Nama Pemain %d : ", c);
													scanf("%s", &c);
													Login(&Q, P);
													init_player(P, c)
													}
												finlist(&Q);
												// diisi oleh bagian board & game
												break;
									case 2 :	if (emptygame()) {
													printf("Tidak ada game yang disimpan\n");
													break;
													}
												else {
													loadgame(&Q, P);
													finlist(&Q);
													// diisi oleh bagian board & game
													break;
													}
									case 3 :	PrintHS(SB);
									case 4 :	saveHS(SB);
												closeHS();
												fclose(ingameplayer);
												printf("Anda berhasil Log Out\n\n");
												break;
									default :	printf("Input salah! mohon ulangi\n\n");
												break;
									}
								}
							while ((y != 1) && (y != 2) && (y != 4));
													
						printf("\n");
						break;
			case 3 :	printf("About the Developers\n\n");
						// Isi dengan Nama/NIM kelompok
						
						break;
			case 4 :	printf("Selamat Tinggal!\n\n");
						close();
						break;
			default :	printf("Input salah! mohon ulangi\n\n");
						break;
			}
		}
	while (k != 3);
	return 0;
	}
	
	
