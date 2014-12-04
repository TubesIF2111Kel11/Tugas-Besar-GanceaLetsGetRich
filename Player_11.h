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

// Registrasi

bool IsNP(Queue *Q);
/* Mengecek apakah daftar registered player kosong atau tidak */

void CreateReg(Queue *Q);
/* Membuat tabel untuk registrasi pemain untuk pemain */

void CreateUTEmpty(UserTab *T);
/* Melakukan assigning dengan nilai kosong ke seluruh bagian tabel registrasi pemain */
	
void Register(UserTab *T, char c[20]);
/* Prosedur untuk mengisi tabel registrasi pemain */

// Konstruksi list-queue pemain

void NextTurn(Queue *Q);
/* Prosedur saat turn seorang pemain telah habis */
	
void init_player(Address P, char c[20]);
/* prosedur untuk inisialisasi keadaan awal pemain */
	
int countplayer(Queue Q);
	
bool NCmp(UserTab T, char c[20]);
/* Mengembalikan kondisi True/False mengenai perbandingan adanya nama pemain di tabel registrasi dengan nama pemain yang diinput oleh user */
	
void Login(Queue *Q, UserTab T, Address P, char c[20]);
/* Prosedur untuk login pemain, yaitu membuat list-queue yang berisi data pemain */
	
void Logon(Queue *Q, UserTab T);
/* Prosedur tambahan yang digunakan dalam prosedur Login */
	
// File I/O untuk registrasi
	
void open();
/* Prosedur membuka filestream yang berisi tabel registrasi pemain*/

void close();
/* Prosedur menutup filestream yang berisi tabel registrasi pemain */

/* void read(); */
		
void write(char c[20], UserTab T);
/* Prosedur mengisi filestream yang berisi tabel registrasi pemain */

void f2arrcpy(UserTab *T);
/* Prosedur untuk menyalin isi filestream tabel registrasi pemain ke dalam tabel registrasi pemain */

// Finalisasi circular list-queue pemain
	
void finlist(Queue *Q);
/* Prosedur untuk membuat list-queue pemain yang akan bermain menjadi circular list-queue */
	
// High Score Board
	
	// 1. Konstruktor
void createHSB(ScoreBoard *SB);
	/* prosedur membuat tabel Highscore */
	
	// 2. Fungsi Utama
	
void AddHS(ScoreBoard *SB, Queue Q);
/* Prosedur untuk menambah/mengubah isi dari tabel Highscore */
	
void PrintHS(ScoreBoard SB);
/* Prosedur untuk mencetak isi dari tabel Highscore ke layar */
	
	//3. load/save High Score ke eksternal	
	
void loadHS();
/* Prosedur untuk membuka filestream yang berisi tabel highscore */
	
void saveHS(ScoreBoard SB);
/* Prosedur untuk menyimpan isi dari tabel Highscore ke dalam filestream */
	
void closeHS();
/* Prosedur untuk menutup filestream */
