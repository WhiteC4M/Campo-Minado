#include<stdio.h>
#include<time.h>

int main(void)
{
	int i, j, l = 9, c = 9; 
	int bombas[l][c], bomba = 0, b_max = 10, cont = 0, pontos = 0;
	int contx, jogada = 0, vitoria = 0;
	int jogo[l][c], linha, coluna;
	int copia[l][c];
	
	fflush(stdin);

	
	srand(time(NULL));
	
	//bomba em posição aleatoria
	
			for(i = 0; i < l; i++)
			{
				for(j = 0; j < c; j++)
				{
					if(bomba != b_max)
					{
						bombas[i][j] = rand() % 6;
					}
					
					if(bombas[i][j] == 1)
					{
						bomba++;
					}
				}
				cont = 0;
			}
	
	
		//definir o valor da casa pelo numero de bombas perto
		
		for(i = 0; i < l; i++)
		{
			for(j = 0; j < c; j++)
			{
				jogo[i][j] = 0;
			}
		}
		

		for(i = 0; i < l; i++)
		{
			for(j = 0; j < c; j++)
			{
				
				if(bombas[i][j] == 1)
				{
					jogo[1+i][1+j] += 1;
					jogo[1+i][j] += 1;
					jogo[i][j] += 1;
					jogo[i-1][j] += 1;
					jogo[i][j-1] += 1;
					jogo[i][j+1] += 1;
					jogo[i+1][j-1] +=1;
					jogo[i-1][j+1] += 1;
					jogo[i-1][j-1] += 1;
				}
			}
		}
		
	//criar uma copia para servir de relação entre o tabuleiro original e o que ja foi jogado
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < l; j++)
		{
			copia[i][j] = jogo[i][j];
		}
	}
		
		
		
		//imprimir jogo	
	do
	{
		system("cls");
		printf("Pontos: %d", pontos);
		printf("\n\n\n");
		printf(" 0   1   2   3   4   5   6   7   8\n\n");
		
		for(i = 0; i < l; i++)
		{
			if(i >= 1)
			{
				printf("------------------------------------\n");
			}
			
			for(j = 0; j < c; j++)
			{
				if(copia[i][j] == jogo[i][j])
				{
						printf(" . ");
				}
				else if(copia[i][j] != jogo[i][j])
				{	
					printf(" %d ", jogo[i][j]);
				}
				printf("|");
			}
		 
		 printf("\t%d", i);
		 printf("\n");
		}
		
		//jogar
			printf("Digite a casa que quer jogar: ");
			scanf("%d %d", &linha, &coluna);
			copia[linha][coluna] = 10;
			
			//checar casas ao lado da casa jogada
			if(jogo[linha][coluna] == 0)
			{
					copia[1+linha][1+coluna] += 1;
					copia[1+linha][coluna] += 1;
					copia[linha][coluna] += 1;
					copia[linha-1][coluna] += 1;
					copia[linha][coluna-1] += 1;
					copia[linha][coluna+1] += 1;
					copia[linha+1][coluna-1] +=1;
					copia[linha-1][coluna+1] += 1;
					copia[linha-1][coluna-1] += 1;	
			}
			
			//definir que caso acerte uma bomba, o jogo acaba
			if(bombas[linha][coluna] == 1)
			{
				vitoria = -1;
			}
			
			if(vitoria == -1)
			{
				system("cls");
				printf("Voce atingiu uma bomba e perdeu");
			}
			
			//definir os pontos de acordo com o numero de casas a mostra
			pontos = 0;
			for(i = 0; i < l; i++)
			{
				for(j = 0; j < c; j++)
				{
					if(copia[i][j] != jogo[i][j])
					{
						pontos++;
					}
				}
			}
			
			//definir a vitória
			if(pontos == (81 - bomba))
			{
				system("cls");
				printf("VOCÊ GANHOU!");
				vitoria = 1;
			}
			
	}while(vitoria == 0);	

		
		
}
	
	
