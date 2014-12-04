#include "TicTacToe_11.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

boolean CekIsi(BoardT3 A, int x, int y)
{
	if (A.kotak[x][y] == Blank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tampilkan_BoardT3 (BoardT3 A)
{
	printf("+-----+-----+-----+\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n",A.kotak[1][1], A.kotak[1][2], A.kotak[1][3]);
	printf("|     |     |     |\n");
	printf("+-----+-----+-----+\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n",A.kotak[2][1], A.kotak[2][2], A.kotak[2][3]);
	printf("|     |     |     |\n");
	printf("+-----+-----+-----+\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n",A.kotak[3][1], A.kotak[3][2], A.kotak[3][3]);
	printf("|     |     |     |\n");
	printf("+-----+-----+-----+\n");
}

void Kosongin (BoardT3 *A)
{
	int i,j;
	for (i = 1; i<=3; i++)
	{
		for  (j = 1; j<=3; j++)
		{
			(*A).kotak[i][j] = Blank;
		}
	}
}

int JumlahKosong(BoardT3 A)
{
	int i,j,jlh;
	jlh = 0;
	for (i = 1; i<=3; i++)
	{
		for  (j = 1; j<=3; j++)
		{
			if (A.kotak[i][j] == Blank)
			{
				jlh = jlh + 1;
			}
		}
	}
	return (jlh);
}

void MauMenang (BoardT3 *A)
{
	if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[1][2] == 'O') && ((*A).kotak[1][3] == ' ') )
	{
		(*A).kotak[1][3] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[1][2] == ' ') && ((*A).kotak[1][3] == 'O') )
	{
		(*A).kotak[1][2] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[1][2] == 'O') && ((*A).kotak[1][3] == 'O') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[2][1] == 'O') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[2][3] == ' ') )
	{
		(*A).kotak[2][3] = 'O';
	}
	else if ( ((*A).kotak[2][1] == 'O') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[2][3] == 'O') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[2][1] == ' ') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[2][3] == 'O') )
	{
		(*A).kotak[2][1] = 'O';
	}
	
	else if ( ((*A).kotak[3][1] == 'O') && ((*A).kotak[3][2] == 'O') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[3][1] == 'O') && ((*A).kotak[3][2] == ' ') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[3][2] = 'O';
	}
	else if ( ((*A).kotak[3][1] == ' ') && ((*A).kotak[3][2] == 'O') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[3][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][3] == 'O') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][1] == ' ') )
	{
		(*A).kotak[3][1] = 'O';
	}
	else if ( ((*A).kotak[1][3] == 'O') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][1] == 'O') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][3] == ' ') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][1] == 'O') )
	{
		(*A).kotak[1][3] = 'O';
	}
	
	else if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[2][1] == 'O') && ((*A).kotak[3][1] == ' ') )
	{
		(*A).kotak[3][1] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'O') && ((*A).kotak[2][1] == ' ') && ((*A).kotak[3][1] == 'O') )
	{
		(*A).kotak[2][1] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[2][1] == 'O') && ((*A).kotak[3][1] == 'O') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][2] == 'O') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][2] == ' ') )
	{
		(*A).kotak[3][2] = 'O';
	}
	else if ( ((*A).kotak[1][2] == 'O') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][2] == 'O') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][2] == ' ') && ((*A).kotak[2][2] == 'O') && ((*A).kotak[3][2] == 'O') )
	{
		(*A).kotak[1][2] = 'O';
	}
	
	else if ( ((*A).kotak[1][3] == 'O') && ((*A).kotak[2][3] == 'O') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[1][3] == 'O') && ((*A).kotak[2][3] == ' ') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[2][3] = 'O';
	}
	else if ( ((*A).kotak[1][3] == ' ') && ((*A).kotak[2][3] == 'O') && ((*A).kotak[3][3] == 'O') )
	{
		(*A).kotak[1][3] = 'O';
	}
}

void MauKalah (BoardT3 *A)
{
	if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[1][2] == 'X') && ((*A).kotak[1][3] == ' ') )
	{
		(*A).kotak[1][3] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[1][2] == ' ') && ((*A).kotak[1][3] == 'X') )
	{
		(*A).kotak[1][2] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[1][2] == 'X') && ((*A).kotak[1][3] == 'X') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[2][1] == 'X') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[2][3] == ' ') )
	{
		(*A).kotak[2][3] = 'O';
	}
	else if ( ((*A).kotak[2][1] == 'X') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[2][3] == 'X') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[2][1] == ' ') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[2][3] == 'X') )
	{
		(*A).kotak[2][1] = 'O';
	}
	
	else if ( ((*A).kotak[3][1] == 'X') && ((*A).kotak[3][2] == 'X') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[3][1] == 'X') && ((*A).kotak[3][2] == ' ') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[3][2] = 'O';
	}
	else if ( ((*A).kotak[3][1] == ' ') && ((*A).kotak[3][2] == 'X') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[3][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][3] == 'X') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][1] == ' ') )
	{
		(*A).kotak[3][1] = 'O';
	}
	else if ( ((*A).kotak[1][3] == 'X') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][1] == 'X') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][3] == ' ') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][1] == 'X') )
	{
		(*A).kotak[1][3] = 'O';
	}
	
	else if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[2][1] == 'X') && ((*A).kotak[3][1] == ' ') )
	{
		(*A).kotak[3][1] = 'O';
	}
	else if ( ((*A).kotak[1][1] == 'X') && ((*A).kotak[2][1] == ' ') && ((*A).kotak[3][1] == 'X') )
	{
		(*A).kotak[2][1] = 'O';
	}
	else if ( ((*A).kotak[1][1] == ' ') && ((*A).kotak[2][1] == 'X') && ((*A).kotak[3][1] == 'X') )
	{
		(*A).kotak[1][1] = 'O';
	}
	
	else if ( ((*A).kotak[1][2] == 'X') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][2] == ' ') )
	{
		(*A).kotak[3][2] = 'O';
	}
	else if ( ((*A).kotak[1][2] == 'X') && ((*A).kotak[2][2] == ' ') && ((*A).kotak[3][2] == 'X') )
	{
		(*A).kotak[2][2] = 'O';
	}
	else if ( ((*A).kotak[1][2] == ' ') && ((*A).kotak[2][2] == 'X') && ((*A).kotak[3][2] == 'X') )
	{
		(*A).kotak[1][2] = 'O';
	}
	
	else if ( ((*A).kotak[1][3] == 'X') && ((*A).kotak[2][3] == 'X') && ((*A).kotak[3][3] == ' ') )
	{
		(*A).kotak[3][3] = 'O';
	}
	else if ( ((*A).kotak[1][3] == 'X') && ((*A).kotak[2][3] == ' ') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[2][3] = 'O';
	}
	else if ( ((*A).kotak[1][3] == ' ') && ((*A).kotak[2][3] == 'X') && ((*A).kotak[3][3] == 'X') )
	{
		(*A).kotak[1][3] = 'O';
	}
}

void PlayerJalan (BoardT3 *A)
{
	int x,y;
	scanf("%d,%d",&x,&y);
	while (!(CekIsi(*A,x,y)))
	{
		printf("Input gagal, posisi %d,%d sudah terisi oleh %c\n",x,y,(*A).kotak[x][y]);
		scanf("%d,%d",&x,&y);
	}
	(*A).kotak[x][y] = 'X';
}

void KompJalan (BoardT3 *A, int turn)
{
	unsigned int mungkin;
	int aa,bb;
	
	switch(turn)
	{
		case 1:
		{
			if (CekIsi(*A,2,2))
			{
				(*A).kotak[2][2] = 'O';
			}
			else
			{
				mungkin = rand() %4 + 1;
				switch (mungkin)
				{
					case 1:
					{
						(*A).kotak[1][1] = 'O';
						break;
					}
					case 2:
					{
						(*A).kotak[1][3] = 'O';
						break;
					}
					case 3:
					{
						(*A).kotak[3][1] = 'O';
						break;
					}
					case 4:
					{
						(*A).kotak[3][3] = 'O';
						break;
					}
				}
			}
			break;
		}
		case 2:
		{
			if ((*A).kotak[2][2] == 'X')
			{
				if (((*A).kotak[1][1] == 'X'))
				{
					if (((*A).kotak[3][3] == 'O'))
					{
//						X23
//						4X6
//						78O
						mungkin = rand() %2 + 1;
						switch (mungkin)
						{
							case 1:
							{
								(*A).kotak[3][1] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[1][3] = 'O';
								break;
							}
						}
					}
					else
					{
//						X2O		X23
//						4X6	or	4X6
//						789		O89
						(*A).kotak[3][3] = 'O';
					}
				}
				else if  ((*A).kotak[1][3] == 'X')
				{
					if  ((*A).kotak[3][1] == 'O')
					{
//						12X
//						4X6
//						O89
						mungkin = rand() %2 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][1] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[3][3] = 'O';
								break;
							}
						}
					}
					else
					{
//						12X		O2X
//						4X6	or	4X6
//						78O		789
						(*A).kotak[3][1] = 'O';
					}
				}
				else if ((*A).kotak[3][3] == 'X')
				{
					if ((*A).kotak[1][1] == 'O')
					{
//						O23
//						4X6
//						78X
						mungkin = rand() %2 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][3] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[3][1] = 'O';
								break;
							}
						}
					}
					else
					{
//						12O		123
//						4X6	or	4X6
//						78X		O8X
						(*A).kotak[1][1] = 'O';
					}
				}
				else if ((*A).kotak[3][1] == 'X')
				{
					if ((*A).kotak[1][3] == 'O')
					{
//						12O
//						4X6
//						X89
						mungkin = rand() %2 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][1] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[3][3] = 'O';
								break;
							}
						}
					}
					else
					{
//						123		O23
//						4X6	or	4X6
//						X8O		X89
						(*A).kotak[1][3] = 'O';
					}
				}
				else
				{
					if ((*A).kotak[1][2] == 'X')
					{
//						OX3		1XO		1X3		1X3
//						4X6	or	4X6	or	4X6	or	4X6
//						789		789		O89		78O
						(*A).kotak[3][2] = 'O';
					}
					if ((*A).kotak[2][1] == 'X')
					{
//						O23		12O		123		123
//						XX6	or	XX6	or	XX6	or	XX6
//						789		789		O89		78O
						(*A).kotak[2][3] = 'O';
					}
					if ((*A).kotak[2][3] == 'X')
					{
//						O23		12O		123		123
//						4XX	or	4XX	or	4XX	or	4XX
//						789		789		O89		78O
						(*A).kotak[2][1] = 'O';
					}
					if ((*A).kotak[3][2] == 'X')
					{
//						O23		12O		123		123
//						4X6	or	4X6	or	4X6	or	4X6
//						7X9		7X9		OX9		7XO
						(*A).kotak[1][2] = 'O';
					}
				}
			}
			else // player ambil ga tengah turn 1
			{
				if ((*A).kotak[1][1] == 'X')
				{
					if ((*A).kotak[1][2] == 'X')
					{
//						XX3
//						4O6
//						789
						(*A).kotak[1][3] = 'O';
					}
					else if ((*A).kotak[2][1] == 'X')
					{
//						X23
//						XO6
//						789
						(*A).kotak[3][1] = 'O';
					}
					else if ((*A).kotak[3][3] == 'X')
					{
//						X23
//						4O6
//						78X
						mungkin = rand() %4 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][2] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[2][1] = 'O';
								break;
							}
							case 3:
							{
								(*A).kotak[2][3] = 'O';
								break;
							}
							case 4:
							{
								(*A).kotak[3][2] = 'O';
								break;
							}
						}
					}
					else if ((*A).kotak[1][3] == 'X')
					{
//						X2X
//						4O6
//						789
						(*A).kotak[1][2] = 'O';
					}
					else if ((*A).kotak[3][1] == 'X')
					{
//						X23
//						4O6
//						X89
						(*A).kotak[2][1] = 'O';
					}
					else if ((*A).kotak[2][3] == 'X')
					{
//						X23
//						4OX
//						789
						// random kecuali 3,1 atau 2,1
						mungkin = rand() %4 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][2] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[1][3] = 'O';
								break;
							}
							case 3:
							{
								(*A).kotak[3][2] = 'O';
								break;
							}
							case 4:
							{
								(*A).kotak[3][3] = 'O';
								break;
							}
						}
					}
					else
					{
//						X23
//						4O6
//						7X9
						(*A).kotak[3][1] = 'O';
					}
				}
				else  if ((*A).kotak[1][3] == 'X')
				{
					if ((*A).kotak[1][2] == 'X')
					{
//						1XX
//						4O6
//						789
						(*A).kotak[1][1] = 'O';
					}
					else if ((*A).kotak[2][3] == 'X')
					{
//						12X
//						4OX
//						789
						(*A).kotak[3][3] = 'O';
					}
					else if ((*A).kotak[3][3] == 'X')
					{
//						12X
//						4O6
//						78X
						(*A).kotak[2][3] = 'O';
					}
					else if ((*A).kotak[3][1] == 'X')
					{
//						12X
//						4O6
//						X89
						mungkin = rand() %4 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][2] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[2][1] = 'O';
								break;
							}
							case 3:
							{
								(*A).kotak[2][3] = 'O';
								break;
							}
							case 4:
							{
								(*A).kotak[3][2] = 'O';
								break;
							}
						}
					}
					else if ((*A).kotak[2][1] == 'X')
					{
						(*A).kotak[1][1] = 'O';
					}
					else
					{
//						12X
//						4O6
//						7X9
						(*A).kotak[3][3] = 'O';
					}
				}
				else  if ((*A).kotak[3][1] == 'X')
				{
					if ((*A).kotak[3][2] == 'X')
					{
//						123
//						4O6
//						XX9
						(*A).kotak[3][3] = 'O';
					}
					else if ((*A).kotak[2][1] == 'X')
					{
//						123
//						XO6
//						X89
						(*A).kotak[1][1] = 'O';
					}
					else if ((*A).kotak[3][3] == 'X')
					{
//						123
//						4O6
//						X8X
						(*A).kotak[3][2] = 'O';
					}
					else if ((*A).kotak[2][3] == 'X')
					{
						(*A).kotak[3][3] = 'O';
					}
					else
					{
//						1X3
//						4O6
//						X89
						(*A).kotak[1][1] = 'O';
					}
				}
				else  if ((*A).kotak[3][3] == 'X')
				{
					if ((*A).kotak[3][2] == 'X')
					{
//						123
//						4O6
//						7XX
						(*A).kotak[3][1] = 'O';
					}
					else if ((*A).kotak[2][3] == 'X')
					{
//						123
//						4OX
//						78X
						(*A).kotak[1][3] = 'O';
					}
					else if ((*A).kotak[2][1] == 'X')
					{
						(*A).kotak[3][1] = 'O';
					}
					else
					{
//						1X3
//						4O6
//						78X
						(*A).kotak[1][3] = 'O';
					}
				}
				else if ((*A).kotak[1][2] == 'X')
				{
					// yang 1X3		1X3		1X3
//							4O6	or	4OX	or	XO6
//							7X9		789		789
					if ((*A).kotak[3][2] == 'X')
					{
//						1X3
//						4O6
//						7X9
						mungkin = rand() %6 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][1] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[1][3] = 'O';
								break;
							}
							case 3:
							{
								(*A).kotak[2][1] = 'O';
								break;
							}
							case 4:
							{
								(*A).kotak[2][3] = 'O';
								break;
							}
							case 5:
							{
								(*A).kotak[3][1] = 'O';
								break;
							}
							case 6:
							{
								(*A).kotak[3][3] = 'O';
								break;
							}
						}
					}
					else if ((*A).kotak[2][1] == 'X')
					{
//						1X3
//						XO6
//						789
						(*A).kotak[1][1] = 'O';
					}
					else if ((*A).kotak[2][3] == 'X')
					{
//						1X3
//						4OX
//						789
						(*A).kotak[1][3] = 'O';
					}
				}
				else if ((*A).kotak[3][2] == 'X')
					{
//						123		123
//						4OX	or	XO6
//						7X9		7X9
						if ((*A).kotak[2][3] == 'X')
						{
//							123
//							4OX
//							7X9
							(*A).kotak[3][3] = 'O';
						}
						else
						{
//							123
//							XO6
//							7X9
							(*A).kotak[3][1] = 'O';
						}
					}
					else if ((*A).kotak[2][1] == 'X')
					{
						mungkin = rand() %6 + 1;
						switch(mungkin)
						{
							case 1:
							{
								(*A).kotak[1][1] = 'O';
								break;
							}
							case 2:
							{
								(*A).kotak[1][2] = 'O';
								break;
							}
							case 3:
							{
								(*A).kotak[1][3] = 'O';
								break;
							}
							case 4:
							{
								(*A).kotak[3][1] = 'O';
								break;
							}
							case 5:
							{
								(*A).kotak[3][2] = 'O';
								break;
							}
							case 6:
							{
								(*A).kotak[3][3] = 'O';
								break;
							}
						}
					}
			}
			break;
		}
		case 3:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 3)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 3)
			{
				
			}
			else
			{
				aa = 1;
				bb = 1;
				while ( ((*A).kotak[aa][bb] != ' ') && (aa <= 3) )
				{
					while ( ((*A).kotak[aa][bb] != ' ') && (bb <= 3) )
					{
						bb = bb + 1;
					}
					if ((*A).kotak[aa][bb] != ' ')
					{
						aa = aa+1;
						bb = 1;
					}
				}
				(*A).kotak[aa][bb] = 'O';
			}
			break;
		}
		case 4:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 1)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 1)
			{
				
			}
			else
			{
				aa = 1;
				bb = 1;
				while ( ((*A).kotak[aa][bb] != ' ') && (aa <= 3) )
				{
					while ( ((*A).kotak[aa][bb] != ' ') && (bb <= 3) )
					{
						bb = bb + 1;
					}
					if ((*A).kotak[aa][bb] != ' ')
					{
						aa = aa+1;
						bb = 1;
					}
				}
				(*A).kotak[aa][bb] = 'O';
			}
		}
	}
}

boolean PlayerMenang (BoardT3 A)
{
	if ( ((A.kotak[1][1] == 'X') && (A.kotak[1][2] == 'X') && (A.kotak[1][3] == 'X')) || ((A.kotak[2][1] == 'X') && (A.kotak[2][2] == 'X') && (A.kotak[2][3] == 'X')) || ((A.kotak[3][1] == 'X') && (A.kotak[3][2] == 'X') && (A.kotak[3][3] == 'X')) || ((A.kotak[1][1] == 'X') && (A.kotak[2][1] == 'X') && (A.kotak[3][1] == 'X')) || ((A.kotak[1][2] == 'X') && (A.kotak[2][2] == 'X') && (A.kotak[3][2] == 'X')) || ((A.kotak[1][3] == 'X') && (A.kotak[2][3] == 'X') && (A.kotak[3][3] == 'X')) || ((A.kotak[1][1] == 'X') && (A.kotak[2][2] == 'X') && (A.kotak[3][3] == 'X')) || ((A.kotak[3][1] == 'X') && (A.kotak[2][2] == 'X') && (A.kotak[1][3] == 'X')) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean KompMenang (BoardT3 A)
{
	if ( ((A.kotak[1][1] == 'O') && (A.kotak[1][2] == 'O') && (A.kotak[1][3] == 'O')) || ((A.kotak[2][1] == 'O') && (A.kotak[2][2] == 'O') && (A.kotak[2][3] == 'O')) || ((A.kotak[3][1] == 'O') && (A.kotak[3][2] == 'O') && (A.kotak[3][3] == 'O')) || ((A.kotak[1][1] == 'O') && (A.kotak[2][1] == 'O') && (A.kotak[3][1] == 'O')) || ((A.kotak[1][2] == 'O') && (A.kotak[2][2] == 'O') && (A.kotak[3][2] == 'O')) || ((A.kotak[1][3] == 'O') && (A.kotak[2][3] == 'O') && (A.kotak[3][3] == 'O')) || ((A.kotak[1][1] == 'O') && (A.kotak[2][2] == 'O') && (A.kotak[3][3] == 'O')) || ((A.kotak[3][1] == 'O') && (A.kotak[2][2] == 'O') && (A.kotak[1][3] == 'O')) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void KompJalan1 (BoardT3 *A)
{
	int x,y;
	do
	{
		x = rand() %3 + 1;
		y = rand() %3 + 1;
	}
	while (!(CekIsi(*A,x,y)));
	(*A).kotak[x][y] = 'O';
}

void KompJalan2 (BoardT3 *A, int turn)
{
	int aa, bb;
	switch (turn)
	{
		case 1:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 7)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 7)
			{
				
			}
			else
			{
				do
				{
					aa = rand() %3 + 1;
					bb = rand() %3 + 1;
				}
				while ((*A).kotak[aa][bb] != ' ');
				(*A).kotak[aa][bb] = 'O';
			}
			break;
		}
		
		case 2:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 5)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 5)
			{
				
			}
			else
			{
				do
				{
					aa = rand() %3 + 1;
					bb = rand() %3 + 1;
				}
				while ((*A).kotak[aa][bb] != ' ');
				(*A).kotak[aa][bb] = 'O';
			}
			break;
		}
		
		case 3:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 3)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 3)
			{
				
			}
			else
			{
				do
				{
					aa = rand() %3 + 1;
					bb = rand() %3 + 1;
				}
				while ((*A).kotak[aa][bb] != ' ');
				(*A).kotak[aa][bb] = 'O';
			}
			break;
		}
		
		case 4:
		{
			MauMenang(&(*A));
			if (JumlahKosong(*A) == 1)
			{
				
			}
			else
			{
				MauKalah(&(*A));
			}
			
			if (JumlahKosong(*A) == 1)
			{
				
			}
			else
			{
				do
				{
					aa = rand() %3 + 1;
					bb = rand() %3 + 1;
				}
				while ((*A).kotak[aa][bb] != ' ');
				(*A).kotak[aa][bb] = 'O';
			}
			break;
		}
	}
}

void playtictactoe(BoardT3 *A, Queue *Q) {
	// Kamus Lokal
	char lanjut;
	int i, hold;
	address P;
	//Algoritma
	P = Head(*Q);
	srand(time(NULL));
	Kosongin(&(*A));
	printf("Level 1\n");
	Tampilkan_BoardT3(*A);
	
	i = 1;
	do
	{
		printf("%d\n",JumlahKosong(*A));
		PlayerJalan(&(*A));
		if (!(PlayerMenang(*A)))
		{
			KompJalan1(&(*A));
		}
		Tampilkan_BoardT3(*A);
		i = i + 1;
	}
	while ((i <= 4) && (!(PlayerMenang(*A)) && !(KompMenang(*A))));
	
	if ((i == 5) && (!(PlayerMenang(*A)) && !(KompMenang(*A))))
	{
		PlayerJalan(&(*A));
		if (PlayerMenang(*A))
		{
			Tampilkan_BoardT3(*A);
			printf("Anda menang\n");
			balance(P) *= 2;
		}
		else if (KompMenang(*A))
		{
			Tampilkan_BoardT3(*A);
			printf("Anda kalah\n");
			balance(P) /= 2;
		}
		else
		{
			Tampilkan_BoardT3(*A);
			printf("Seri\n");
		}
	}
	else
	{
		if (PlayerMenang(*A))
		{
			printf("Anda menang\n");
			balance(P) *= 2;
			
		}
		else if (KompMenang(*A))
		{
			printf("Anda kalah\n");
			balance(P) /= 2;
		}
	}
	
	if ( PlayerMenang(*A))
	{
		printf("Lanjut ke level 2?");
		scanf(" %c", &lanjut);
		
		if (lanjut == 'Y')
		{
			Kosongin(&(*A));
		i = 1;
		do
		{
			printf("%d\n",JumlahKosong(*A));
			PlayerJalan(&(*A));
			if (!(PlayerMenang(*A)))
			{
				KompJalan2((&(*A)), i);
			}
			Tampilkan_BoardT3(*A);
			i = i + 1;
		}
		while ((i <= 4) && (!(PlayerMenang(*A)) && !(KompMenang(*A))));
	
		if ((i == 5) && (!(PlayerMenang(*A)) && !(KompMenang(*A))))
		{
			PlayerJalan(&(*A));
			if (PlayerMenang(*A))
			{
				Tampilkan_BoardT3(*A);
				printf("Anda menang\n");
				balance(P) *= 2;
			}
			else if (KompMenang(*A))
			{
				Tampilkan_BoardT3(*A);
				printf("Anda kalah\n");
				balance(P) /= 2;
			}
			else
			{
				Tampilkan_BoardT3(*A);
				printf("Seri\n");
			}
		}
		else
		{
			if (PlayerMenang(*A))
			{
				printf("Anda menang\n");
				balance(P) *= 2;
			}
			else if (KompMenang(*A))
			{
				printf("Anda kalah\n");
				balance(P) /= 2;
			}
		}
	}
}
	
	if (PlayerMenang(*A))
	{
		printf("Lanjut ke level 3?");
		scanf(" %c", &lanjut);
		
		if (lanjut == 'Y')
		{
			Kosongin(&(*A));
		i = 1;
		do
		{
			// printf("%d\n",JumlahKosong(*A));
			PlayerJalan(&(*A));
			KompJalan((&(*A)),i);
			Tampilkan_BoardT3(*A);
			i = i + 1;
		}
		while ((i <= 4) && (!(PlayerMenang(*A)) && !(KompMenang(*A))));
	
		if ((i == 5) && (!(PlayerMenang(*A)) && !(KompMenang(*A))))
		{
			PlayerJalan(&(*A));
			if (PlayerMenang(*A))
			{
				Tampilkan_BoardT3(*A);
				printf("Anda menang\n");
				balance(P) *= 2;
			}
			else if (KompMenang(*A))
			{
				Tampilkan_BoardT3(*A);
				printf("Anda kalah\n");
				balance(P) /= 2;
			}
			else
			{
				Tampilkan_BoardT3(*A);
				printf("Seri\n");
			}
		}
		else
		{
			if (PlayerMenang(*A))
			{
				printf("Anda menang\n");
				balance(P) *= 2;
			}
			else if (KompMenang(*A))
			{
				printf("Anda kalah\n");
				balance(P) /= 2;
			}
		}
	}
}
	scanf ("%d", &hold);
}

