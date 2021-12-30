#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 14
#define LINHA 5
#define COLUNA 9
#define LIMITE_3 1
#define LIMITE_4 13



struct lista{
	int chave;
	struct lista *prox, *ant;
};

typedef struct lista ELEMENTO;
typedef ELEMENTO *ELEMENTOptr;



int main(void){
 int matr[TAMANHO][TAMANHO] = {{0,0,1,2,3,0,4,5,6,0,7,8,9},{0},{1},{2},{3},{0},{4},{5},{6},{0},{7},{8},{9}};
 int linha, coluna, linha_ant, coluna_ant, numero, dificuldade, verificador;
 int verifica_coluna, verifica_linha, verifica_quadro,linha_inicial,coluna_inicial;
 
 void imprime_matriz(int matr[][TAMANHO]);
 int valida_dados(int dados);
 bool imprime(ELEMENTOptr l);
 void inicializa(ELEMENTOptr l);
 bool insere(ELEMENTOptr l, int numero);
 ELEMENTOptr busca(ELEMENTOptr l, int chave);
 bool remover(ELEMENTOptr l, int chave);
 int disponiveis(ELEMENTOptr l, ELEMENTOptr lista_ordenada, int num_inicial);
 void inserir_matriz(ELEMENTOptr l, int i);

 
 srand(time(NULL));

   
 printf("Escolha um nivel de dificuldade para o jogo digitando o numero relacionado ao nivel: \n 1 para muito facil\n 2 para facil\n 3  para normal\n 4 para dificil\n 5 para muito dificil \n");
 scanf("%d", &dificuldade);
 printf("\n");

 
 while(dificuldade < 1 || dificuldade > 5){
 	printf("Escolha um nivel de dificuldade valido: ");
 	scanf("%d", &dificuldade);
 }

 
 if(dificuldade == 1){
 	dificuldade = 64;
 } else if (dificuldade == 2){
 	dificuldade = 32;	
 } else if  (dificuldade == 3){
 	dificuldade = 16;
 } else {
 	dificuldade = 8;
 }

   
 int a = 0;
 while(a < TAMANHO){
 	int i = 0;
	while(i < TAMANHO){
		if(i == LINHA || i == COLUNA || i == LIMITE_3 || i == LIMITE_4){
			matr[a][i] = 37;
		}
		if (a == LINHA || a == COLUNA || a == LIMITE_3 || a == LIMITE_4){
			matr[a][i] = 73;
		}
		i = i + 1;
   }
   a = a + 1;
 }

 
 int valor = 0;
 while(valor < dificuldade){
  	verifica_linha = 1;
 	verifica_coluna = 1;
 	verifica_quadro = 1;
  	while((verifica_linha != 0) || (verifica_coluna != 0) || (verifica_quadro != 0)){
  		linha = 2 + rand() % 10;
		coluna = 2 + rand() % 10;
		if ((linha >= 5 && linha <= 7) || (linha >= 9)){ 
     		linha = linha + 1;
   		}
   		if ((coluna >= 5 && coluna <= 7) || (coluna >= 9)){
     		coluna = coluna + 1;
   		}
		while(matr[linha][coluna] != 0){
			linha = 2 + rand() % 10;
			coluna = 2 + rand() % 10;
			if ((linha >= 5 && linha <= 7) || (linha >= 9)){
				linha = linha + 1;
				}
			if ((coluna >= 5 && coluna <= 7) || (coluna >= 9)){
				coluna = coluna + 1;
				}
    	}
		numero = 1 + rand() % 9;
		int linhas = 2, colunas = 2;
		verifica_coluna = 0;
   		verifica_linha = 0;
   		verifica_quadro = 0;
    	while(colunas < TAMANHO){
			if(matr[linha][colunas] == numero){
				verifica_coluna = verifica_coluna + 1;
			}
			colunas = colunas + 1;
		}
		while(linhas < TAMANHO){
			if(matr[linhas][coluna] == numero){
				verifica_linha = verifica_linha + 1;
			}
			linhas = linhas + 1;
   		}
   		linha_inicial = 0;
   		coluna_inicial = 0;
		if(linha >= 2 && linha <= 4){
   			linha_inicial = 2;
   			if(coluna >= 2 && coluna <= 4){
   				coluna_inicial = 2;
			} else if (coluna >= 6 && coluna <= 8){
				coluna_inicial = 6;
			} else if (coluna >= 10){
				coluna_inicial = 10;
			}
		} else if(linha >= 6 && linha <= 8){
			linha_inicial = 6;
			if(coluna >= 2 && coluna <= 4){
				coluna_inicial = 2;
			} else if(coluna >= 6 && coluna <= 8){
				coluna_inicial = 6;
			} else if (coluna >= 10){
				coluna_inicial = 10;
			}		
		} else if(linha >= 10){
			linha_inicial = 10;
			if (coluna >= 2 && coluna <= 4){
				coluna_inicial = 2;
			}
			else if (coluna >= 6 && coluna <= 8){
				coluna_inicial = 6;
			}
			else if (coluna >= 10){
				coluna_inicial = 10;
			}
		}
		int coluna_inicial1 = coluna_inicial;
		int linha1 = linha_inicial + 3;
		int coluna1 = coluna_inicial + 3;
   		while(linha_inicial < linha1){
   			coluna_inicial = coluna_inicial1;
   			while(coluna_inicial < coluna1){
   				if(matr[linha_inicial][coluna_inicial] == numero){
   					verifica_quadro = verifica_quadro + 1;
			   	}
				coluna_inicial = coluna_inicial + 1;
		    }
			linha_inicial = linha_inicial + 1;
	   	}
	}
   	matr[linha][coluna] = numero;
   	valor = valor + 1;
 }
 
 
 int quantidade_zeros = 0;
 a = 2;
 int c = 2;
 while(a < 13){
 	c = 2;
 	while(c < 13){
 		if (matr[a][c] == 0){
 			quantidade_zeros = quantidade_zeros + 1;
 		}
 		c = c + 1;
 	}
 	a = a + 1;
 }
 
 
 imprime_matriz(matr);
 
 
 while (quantidade_zeros != 0){
	ELEMENTO L;
   	ELEMENTO Pos;
   	inicializa(&L);
   	inicializa(&Pos);
   	printf("\nInforme, abaixo, a linha e a coluna onde voce deseja colocar um numero:\n");
     
   	printf("Linha: ");
   	scanf("%i", &linha);
   	while(linha < 1 || linha > 9){
   		printf("Linha invalida. Escolha outra linha: ");
   		scanf("%d", &linha);
   	}
   	linha = valida_dados(linha);  
   	
   	printf("Coluna: ");
   	scanf("%d", &coluna);
   	while(coluna < 1 || coluna > 9){
   		printf("Coluna invalida. Escolha outra coluna: ");
   		scanf("%d", &coluna);
   	}
   	coluna = valida_dados(coluna);
         
   	while(matr[linha][coluna] != 0){
   		printf("\n\nPosicao invalida. Informe outra posicao para colocar um numero.\n\n\n");
   		printf("linha: ");
   		scanf("%d", &linha);
   		while(linha < 1 || linha > 9){
   			printf("Linha invalida. Escolha outra linha: ");
   			scanf("%d", &linha);
   		}
   		linha = valida_dados(linha);
   		printf("coluna: ");
		scanf("%d", &coluna);
		while(coluna < 1 || coluna > 9){
   			printf("Coluna invalida. Escolha outra coluna: ");
   			scanf("%d", &coluna);
    	}
   		coluna = valida_dados(coluna);
    }
        
   	int linhas = 2, colunas = 2;
   	verifica_coluna = 0;
   	verifica_linha = 0;
   	verifica_quadro = 0;
    while(colunas < TAMANHO){
		inserir_matriz(&L,matr[linha][colunas]);
		colunas = colunas + 1;
	}
	while(linhas < TAMANHO){
		inserir_matriz(&L,matr[linhas][coluna]);
		linhas = linhas + 1;
	}
   	linha_inicial = 0;
   	coluna_inicial = 0;
	if(linha >= 2 && linha <= 4){
   		linha_inicial = 2;
   		if(coluna >= 2 && coluna <= 4){
   			coluna_inicial = 2;
		} else if (coluna >= 6 && coluna <= 8){
			coluna_inicial = 6;
		} else if (coluna >= 10){
			coluna_inicial = 10;
		}
	} else if(linha >= 6 && linha <= 8){
		linha_inicial = 6;
		if(coluna >= 2 && coluna <= 4){
			coluna_inicial = 2;
		} else if(coluna >= 6 && coluna <= 8){
			coluna_inicial = 6;
		} else if (coluna >= 10){
			coluna_inicial = 10;
		}		
	} else if(linha >= 10){
		linha_inicial = 10;
		if (coluna >= 2 && coluna <= 4){
			coluna_inicial = 2;
		}
		else if (coluna >= 6 && coluna <= 8){
			coluna_inicial = 6;
		}
		else if (coluna >= 10){
			coluna_inicial = 10;
		}
	}
	int coluna_inicial1 = coluna_inicial;
	int linha1 = linha_inicial + 3;
	int coluna1 = coluna_inicial + 3;
   	while(linha_inicial < linha1){
   		coluna_inicial = coluna_inicial1;
   		while(coluna_inicial < coluna1){
			inserir_matriz(&L,matr[linha_inicial][coluna_inicial]);
			coluna_inicial = coluna_inicial + 1;
		}
		linha_inicial = linha_inicial + 1;
	}
	
	printf("\n");
	disponiveis(&L,&Pos,1);
	printf("Os numeros que podem ser colocados nesta posicao sao:  ");
	imprime(&Pos);
	printf("\n");
	
	printf("\nEscolha um dos numeros acima: ");
	scanf("%d", &numero);
	ELEMENTOptr busca_numero = busca(&Pos,numero);
	while(busca_numero == NULL){
		printf("\nNumero invalido. Informe um dos numeros disponiveis: ");
		scanf("%d", &numero);
		busca_numero = busca(&Pos,numero);
	}
	
	remover(&Pos,numero);
	printf("\n\n\n");
	printf("Lista atualizada:  ");
	imprime(&Pos);
	printf("\n\n\n");
		
	matr[linha][coluna] = numero;
	quantidade_zeros = quantidade_zeros - 1;
	printf("\n");
	imprime_matriz(matr);
	printf("\n");
	
}


printf("Parabens! Voce completou o jogo!");

 
return 0;
}



void imprime_matriz(int matr[][TAMANHO]){
	int a = 0;
	while(a < TAMANHO){
	int i = 0;
    while(i < TAMANHO){
       if(matr[a][i] == 0){
         printf("  ");     
      } else if(matr[a][i] == 37){
         printf("|");     
       } else if(matr[a][i] == 73){
         printf("- ");     
       } else{
         printf("%d ", matr[a][i]);
         
       }
       i = i + 1;
     }
	 a = a + 1;
	printf("\n");
 	}
}

int valida_dados(int dados){
	if (dados >= 7){
   	dados = dados + 3;
   } else if (dados >= 4){
   	dados = dados + 2;
   } else {
   	dados = dados + 1;
   }
   return dados;
}

bool imprime(ELEMENTOptr l){
	if(l == NULL) return 1;
	if(l->ant == NULL && l->prox == NULL) printf("NAO HA NUMEROS");
	if(l->ant != NULL) printf("%i ", l->chave);
	l = l->prox;
	imprime(l);
}

void inicializa(ELEMENTOptr l){
	l->ant = NULL;
	l->prox = NULL;
	l->chave  = NULL;
}

ELEMENTOptr busca(ELEMENTOptr l, int chave){
	if (l == NULL) return NULL;
	if (l->chave == chave) return l;
	l = l->prox;
	busca(l,chave);
}

bool insere(ELEMENTOptr l, int numero){
	ELEMENTOptr busca1 = busca(l,numero);
	if (busca1 != NULL) return 1;
	if (l->prox == NULL){
		ELEMENTOptr end = (ELEMENTOptr) malloc(sizeof(ELEMENTO));
		l->prox = end;
		end->ant = l;
		end->chave = numero;
		end->prox = NULL;
		return 1;
	}
	l = l->prox;
	insere(l,numero);
}

bool remover(ELEMENTOptr l, int chave){
	if (l == NULL) return 0;
	ELEMENTOptr elemento_busca = busca(l,chave);
	if (elemento_busca == NULL) return 0;
	elemento_busca->ant->prox = elemento_busca->prox;
	if (elemento_busca->prox != NULL) elemento_busca->prox->ant = elemento_busca->ant; 
	free(elemento_busca);
	return 1;
}

int disponiveis(ELEMENTOptr l, ELEMENTOptr lista_ordenada, int num_inicial){
	if(num_inicial == 10) return 1;
	ELEMENTOptr busca1 = busca(l,num_inicial);
	if(busca1 == NULL) insere(lista_ordenada,num_inicial);
	num_inicial++;
	disponiveis(l,lista_ordenada,num_inicial);
}

void inserir_matriz(ELEMENTOptr l, int i){
	if (i != 0 && i != 37 && i != 73){
		insere(l,i);
	}
}
