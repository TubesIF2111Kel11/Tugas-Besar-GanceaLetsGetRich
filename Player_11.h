// player.h

typedef struct tpemain {
				char Nama[20];
				long balance;
				long Assets;
				int position;
				address Next;
				} Pemain;

typedef struct tpemain *address;

typedef struct {
				address Head;
				address Tail;
				} Queue;
				
#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define Name(P) (P)->Nama
#define balance(P) (P)->balance
#define aset(P) (P)->Assets
#define pos(P) (P)->position
#define Next(P) (P)->Next
#define Blank ' '
#define BlankScore "..."

typedef struct {
				char UserName[100][20];
				int Neff;
				} UserTab;
				
typedef struct {
				char NameRec[20]
				long AssetsRec;
				} HighScore;

typedef struct {
				HighScore HS[10];
				} ScoreBoard;
