// player

typedef struct tpemain {
				char Nama;
				longint balance;
				properti *props
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
#define balance(P) (P)->balance
#define aset(P) (P)->properti
#define pos(P) (P)->position
#define Next(P) (P)->Next

void CreateReg(Queue *Q) {
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	}

	
void Register(Queue *Q) {
	// Kamus Lokal
	address P, Hex;
	// Algoritma
	P = Head(*Q);
	if ((P) == Nil) {
		(P) = (address)malloc(sizeof(Pemain));
		if ((*P) != Nil) {
			&Head(*Q) = (P);
			&Tail(*Q) = (P);
			}
		}
	else {
		P = Tail(*Q);
		Hex = (address)malloc(sizeof(Pemain));
		P  = Next(P);
		P = Hex;
		&Tail(*Q) = P;
		}
	}
