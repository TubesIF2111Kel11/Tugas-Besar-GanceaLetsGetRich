#include "boolean.h"
#include "player_11.h"


// board T3
typedef struct{
				char kotak[4][4];
				} BoardT3;

// fungsi dan prosedur
boolean CekIsi(BoardT3 A, int x, int y);
// melakukan pengecekan isi posisi tertentu di board
// mengembalikan true bila kosong dan false bila berisi

void Tampilkan_BoardT3 (BoardT3 A);
// menampilkan board ke layar

void Kosongin (BoardT3 *A);
// mengosongkan board tictactoe A

int JumlahKosong(BoardT3 A);
// mengembalikan jumlah kotak kosong di board

void MauMenang (BoardT3 *A);
// melakukan turn komp bila komp akan menang (digunakan pada turn4)

void MauKalah (BoardT3 *A);
// melakukan turn komp bila komp hampir kalah (digunakan pada turn4)

void PlayerJalan (BoardT3 *A);
// melakukan turn player

void KompJalan (BoardT3 *A, int turn);
// melakukan turn komputer pada turn ke-sekian

boolean PlayerMenang (BoardT3 A);
// mengembalikan true bila player menang

boolean KompMenang (BoardT3 A);
// mengembalikan true bila komputer menang

void KompJalan1 (BoardT3 *A);
// melakukan turn komputer pada level 1

void KompJalan2 (BoardT3 *A, int turn);
// melakukan turn komputer pada level 2

void playtictactoe(BoardT3 *P, Queue *Q);
// Prosedur untuk memanggil game tictactoe
