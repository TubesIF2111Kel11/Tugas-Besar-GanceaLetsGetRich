#include "TicTacToe.h"


int main()
{
	// Kamus
	BoardT3 P;
	int i, hold;
	char lanjut;
	
	//Algoritma
	srand(time(NULL));
	Kosongin(&P);
	printf("Level 1\n");
	Tampilkan_BoardT3(P);
	
	i = 1;
	do
	{
		printf("%d\n",JumlahKosong(P));
		PlayerJalan(&P);
		if (!(PlayerMenang(P)))
		{
			KompJalan1(&P);
		}
		Tampilkan_BoardT3(P);
		i = i + 1;
	}
	while ((i <= 4) && (!(PlayerMenang(P)) && !(KompMenang(P))));
	
	if ((i == 5) && (!(PlayerMenang(P)) && !(KompMenang(P))))
	{
		PlayerJalan(&P);
		if (PlayerMenang(P))
		{
			Tampilkan_BoardT3(P);
			printf("Kamu Menang!!\n");
		}
		else if (KompMenang(P))
		{
			Tampilkan_BoardT3(P);
			printf("Kamu Kalah!!\n");
		}
		else
		{
			Tampilkan_BoardT3(P);
			printf("Yah, Seri dong...\n");
		}
	}
	else
	{
		if (PlayerMenang(P))
		{
			printf("Kamu Menang!!\n");
		}
		else if (KompMenang(P))
		{
			printf("Kamu Kalah!!\n");
		}
	}
	
	if ( PlayerMenang(P))
	{
		printf("Lanjut ke level 2?");
		scanf(" %c", &lanjut);
		
		if (lanjut == 'Y')
		{
			Kosongin(&P);
		i = 1;
		do
		{
			printf("%d\n",JumlahKosong(P));
			PlayerJalan(&P);
			if (!(PlayerMenang(P)))
			{
				KompJalan2(&P, i);
			}
			Tampilkan_BoardT3(P);
			i = i + 1;
		}
		while ((i <= 4) && (!(PlayerMenang(P)) && !(KompMenang(P))));
	
		if ((i == 5) && (!(PlayerMenang(P)) && !(KompMenang(P))))
		{
			PlayerJalan(&P);
			if (PlayerMenang(P))
			{
				Tampilkan_BoardT3(P);
				printf("Kamu Menang!!\n");
			}
			else if (KompMenang(P))
			{
				Tampilkan_BoardT3(P);
				printf("Kamu Kalah!!\n");
			}
			else
			{
				Tampilkan_BoardT3(P);
				printf("Yah, Seri dong...\n");
			}
		}
		else
		{
			if (PlayerMenang(P))
			{
				printf("Kamu Menang!!\n");
			}
			else if (KompMenang(P))
			{
				printf("Kamu Kalah!!\n");
			}
		}
	}
}
	
	if (PlayerMenang(P))
	{
		printf("Lanjut ke level 3?");
		scanf(" %c", &lanjut);
		
		if (lanjut == 'Y')
		{
			Kosongin(&P);
		i = 1;
		do
		{
			printf("%d\n",JumlahKosong(P));
			PlayerJalan(&P);
			KompJalan(&P,i);
			Tampilkan_BoardT3(P);
			i = i + 1;
		}
		while ((i <= 4) && (!(PlayerMenang(P)) && !(KompMenang(P))));
	
		if ((i == 5) && (!(PlayerMenang(P)) && !(KompMenang(P))))
		{
			PlayerJalan(&P);
			if (PlayerMenang(P))
			{
				Tampilkan_BoardT3(P);
				printf("Kamu Menang!!\n");
			}
			else if (KompMenang(P))
			{
				Tampilkan_BoardT3(P);
				printf("Kamu Kalah!!\n");
			}
			else
			{
				Tampilkan_BoardT3(P);
				printf("Yah, Seri dong...\n");
			}
		}
		else
		{
			if (PlayerMenang(P))
			{
				printf("Kamu Menang!!\n");
			}
			else if (KompMenang(P))
			{
				printf("Kamu Kalah!!\n");
			}
		}
	}
}
	scanf ("%d", &hold);
	return 0;
}

