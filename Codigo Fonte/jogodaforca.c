#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

//Thiago da Silva Ferreira
void desenhaforca(int erros){
	switch(erros){
	case 6:
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***"    );
	printf("\n|    * X * "  );
	printf("\n|     ***"    );
	printf("\n|     /|\\ "  );
	printf("\n|    / | \\ " );
	printf("\n|      |"     );
	printf("\n|     / \\"   );
  	printf("\n|    /   \\"  ); 
	printf("\n|");
	printf("\n|");
	break;	
	case 5:	
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***"    );
	printf("\n|    *   * "  );
	printf("\n|     ***"    );
	printf("\n|     /|\\ "  );
	printf("\n|    / | \\ " );
	printf("\n|      |"     );
	printf("\n|     / "     );
  	printf("\n|    /   "    ); 
	printf("\n|");
	printf("\n|");
	break;	
	case 4:
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***"    );
	printf("\n|    *   * "  );
	printf("\n|     ***"    );
	printf("\n|     /|\\ "  );
	printf("\n|    / | \\ " );
	printf("\n|      |"     );
	printf("\n|      "      );
  	printf("\n|          "  ); 
	printf("\n|");
	printf("\n|");
	break;	
	case 3:
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***"    );
	printf("\n|    *   * "  );
	printf("\n|     ***"    );
	printf("\n|     /| "  );
	printf("\n|    / |  " );
	printf("\n|      |"     );
	printf("\n|    "   );
  	printf("\n|    "  ); 
	printf("\n|");
	printf("\n|");
	break;	
	case 2:	
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***"    );
	printf("\n|    *   * "  );
	printf("\n|     ***"    );
	printf("\n|      | "  );
	printf("\n|      |  " );
	printf("\n|      |"     );
	printf("\n|    "   );
  	printf("\n|    "  ); 
	printf("\n|");
	printf("\n|");
	break;	
	case 1:
    system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/    ***  "  );
	printf("\n|    *   * "  );
	printf("\n|     ***  "  );
	printf("\n|");
	printf("\n|");
	printf("\n|");
	printf("\n|");
  	printf("\n|"); 
	printf("\n|");
	printf("\n|");
	break;
	case 0:
	system("cls");
	printf("\n _____________");
	printf("\n| /    | "    );
	printf("\n|/");
	printf("\n|");
	printf("\n|");
	printf("\n|");
	printf("\n|");
	printf("\n|");
	printf("\n|");
  	printf("\n|"); 
	printf("\n|");
	printf("\n|");
	}
}
void abertura (){
	printf("*************************************\n");
	printf("******BEM VINDO AO JOGO DA FORCA*****\n");
	printf("*************************************\n");
}
void menu(int *opcao){
	printf("Escolha o modo de jogo:\n[1]-Jogador vs Jogador\n[2]-Jogador vs computador\n");
	scanf("%d",opcao);
	while(*opcao!=1 && *opcao!=2){
		printf("Digite um modo de jogo valido!\n[1]-Jogador vs Jogador\n[2]-Jogador vs computador\n");
		scanf("%d",opcao);
	}
}
void menu_jogadorvscomputador(int *duelo){//para escolha de modo jogador vc computador
	printf("Escolha o duelo entre:\n[1]-Computador escolhe a palavra\n[2]-Jogador escolhe a palavra\n");
	scanf("%d", duelo);
	while(*duelo!=1 && *duelo!=2){
		printf("Digite um duelo de jogo valido:");
		scanf("%d",duelo);
	}
}
void nomejogador(char jogador[15]){
	printf("Digite o nome do jogador:\n");
	scanf("%s",jogador);
}
int nivel(){
	int nivel, letras;//defindo o nivel e a quantidades de letras por nivel
	printf("Escolha a dificuldade:\n[1]-FACIL\n[2]-MEDIO\n[3]-DIFICIL\n");
		do{	
		scanf("%d", &nivel);
			switch(nivel){
			case 1:
				letras=4;
				break;
			case 2:
				letras=6;
				break;
			case 3:
				letras=8;
				break;
			default:
				letras=0;
				printf("Opcao invalida\nDigite novamente\n");
				break;		
			}
		}while(letras==0);	
	return letras;
}
void esconderpalavra(char pescondida[],int tam){
	for(int i=0; i<tam; i++){
			pescondida[i]='_';
		}
}
void mostrarpalavra(char pescondida[], int tam){
	for(int i=0; i<tam; i++){
		printf(" %c ", pescondida[i]);
	}
}
char maiusculaletra(char letra){
	letra=toupper(letra);
	return letra;
}
void maiusculapalavra(char palavra[]){
	int n=strlen(palavra);
	for(int i=0; i<n; i++){
		palavra[i]=toupper(palavra[i]);
	}
}
char digiteletra(){
	char chute;
	printf("\nDigite uma letra:");
			scanf(" %c", &chute);
			fflush(stdin);
			chute = maiusculaletra(chute);
	return chute;
}
char verificachute(char chute,char chutes[]){
	int n=strlen(chutes);
	for(int i=0; i<n; i++)
		while(chute==chutes[i]){
			printf("Letra ja utilizada ,digite outra letra:");
			scanf(" %c", &chute);
			chute = maiusculaletra(chute);
			chute = verificachute(chute,chutes);
		}
	return chute;
}
void tabela(int corretas, int erros, int tentativas,int erros_tentativas,char chutes[]){
	printf("\n\nTENTATIVAS FEITAS = %d\n", tentativas);
	printf("TENTATIVAS RESTANTES = %d\n", erros_tentativas-erros);
	printf("CORRETAS = %d\n",corretas);
	printf("ERROS = %d\n", erros);
	printf("LETRAS JA USADAS : ");
	for(int i=0; i<6; i++)
		printf("%c ",chutes[i]);
	printf("\n");
}

int main(void) {
setlocale(LC_ALL,"");	
	abertura();
	int opcao=0;
	menu(&opcao);
	if(opcao==1){
		char jogador1[15];
		nomejogador(jogador1);
		maiusculapalavra(jogador1);	
		int letras = nivel();
		char psecreta[letras];
		printf("Digite a palavra secreta com %d letras:",letras);
		scanf("%s",psecreta);
		fflush(stdin);
		maiusculapalavra(psecreta);
		int tam = strlen(psecreta);
		while(tam!=letras){
			printf("Palavra invalida! Digite a palavra secreta com %d letras:", letras);
			scanf("%s", psecreta);
			tam = strlen(psecreta);
			maiusculapalavra(psecreta);
		}
		char pescondida[letras];
		esconderpalavra(pescondida,tam);
		system("cls");
		char jogador2[15];
		nomejogador(jogador2);
		maiusculapalavra(jogador2);
		int fim=0;
		int corretas=0, erros=0, tentativas=0,erros_tentativas=6,contchute=0;
		char chute, chutes[]={"         "};
		do{
			desenhaforca(erros);
			mostrarpalavra(pescondida, tam);
			tabela(corretas,erros,tentativas,erros_tentativas,chutes);
			chute = digiteletra();
			chute = verificachute(chute,chutes);
			int encontrei =0;
			for(int i=0; i<tam; i++)
				if(chute==psecreta[i]){
					pescondida[i]=chute;
					corretas++;
					encontrei=1;
				}
			if(encontrei==0)
				erros++;
			chutes[contchute]=chute;
			contchute++;
			tentativas++;
			if(erros==erros_tentativas || corretas==tam)
				fim=1;
		}while(fim==0);
		if(corretas==tam){
			desenhaforca(erros);
			printf("\nPARABENS %s, VOCÊ ACERTOU A PALAVRA SECRETA -> %s <-",jogador2, psecreta);
		}
		else if(erros==erros_tentativas){
			desenhaforca(erros);
			printf("QUE PENA %s, VOCÊ PERDEU A PALAVRA ERA -> %s <-",jogador2, psecreta);
		}
	}
	else if(opcao==2){
		int modo=0;
		printf("MODO DE JOGO:\n[1]-COMPUTADOR ESCOLHE A PALAVRA\n[2]-JOGADOR ESCOLHE A PALAVRA\n");
		scanf("%d", &modo);
		while(modo != 1 && modo != 2){
			printf("Modo invalido! Digite um modo de jogo valido\n");
			printf("MODO DE JOGO:\n[1]-COMPUTADOR ESCOLHE A PALAVRA\n[2]-JOGADOR ESCOLHE A PALAVRA\n");
			scanf("%d", &modo);
		}
		int letras = nivel();
		char psecreta[letras];
		srand(time(NULL));
		int tam=0;
		if(modo==1){
			char palavras3[5][8] = {"EQUIDADE","TELEFONE","BISCOITO","CARAMELO","PATINETE"};
			char palavras2[5][6]={"BANANA","ESCADA","LIVROS","ESCOLA","ARMADO"};
			char palavras1[5][4]={"CASA","DADO","FACA","PICO","BOLA"};		
			int n=rand()%5;
			if(letras==4){
				for(int i=0;i<letras; i++)
					psecreta[i]=palavras1[n][i];
			}
			else if(letras==6){
				for (int i=0;i<letras;i++)
					psecreta[i]=palavras2[n][i];
			}
			else if(letras==8){
				for (int i=0;i<letras;i++)
					psecreta[i]=palavras3[n][i];
			}
			tam=strlen(psecreta);
		}
		else if(modo==2){
			printf("Digite a palavra secreta com %d letras:",letras);
			scanf("%s", psecreta);
			fflush(stdin);
			tam = strlen(psecreta);
			maiusculapalavra(psecreta);
			while(tam!=letras){
				printf("Palavra invalida! Digite a palavra secreta com %d letras:", letras);
				scanf("%s", psecreta);
				tam = strlen(psecreta);
				maiusculapalavra(psecreta);
			}
		}
		char pescondida[letras];
		esconderpalavra(pescondida,tam);
		system("cls");
		int fim=0;
		int corretas=0, erros=0, tentativas=0,erros_tentativas=6,contchute=0;
		char chute, chutes[]={"         "};
			do{
				desenhaforca(erros);
				mostrarpalavra(pescondida, letras);
				tabela(corretas,erros,tentativas,erros_tentativas,chutes);
				if(modo==1){
					chute = digiteletra();
					chute = verificachute(chute,chutes);
				}
				else if(modo==2){
					char vetorchute[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
					chute= vetorchute[rand()%26];
						printf("\nO CHUTE DA MAQUINA É >> %c <<\n\n", chute);
						system("pause");
					for(int i=0;i<tam; i++)
						while(chute==chutes[i]){
							printf("\nLetra > %c < ja utilizada\nVou escolher outra letra:", chute);
							chute=vetorchute[rand()%26];
							printf("\nO CHUTE DA MAQUINA É >> %c <<\n\n", chute);
							system("pause");
						}
				}
					int encontrei =0;
					for(int i=0; i<tam; i++)
						if(chute==psecreta[i]){
							pescondida[i]=chute;
							corretas++;
							encontrei=1;
						}
					if(encontrei==0)
						erros++;
					chutes[contchute]=chute;
					contchute++;
					tentativas++;
					if(erros==erros_tentativas || corretas==letras)
						fim=1;
			}while(fim==0);
			if(modo==1){
				if(corretas==letras){
					desenhaforca(erros);
					printf("\nPARABENS, VOCÊ ACERTOU A PALAVRA SECRETA -> ");
					for(int i=0;i<letras;i++)
						printf("%c",psecreta[i]);
					printf(" <-");
				}
				else if(erros==erros_tentativas){
					desenhaforca(erros);
					printf("QUE PENA, VOCÊ PERDEU A PALAVRA ERA -> ");
					for(int i=0;i<letras;i++)
						printf("%c",psecreta[i]);
					printf(" <-");
				}
			}
			else if(modo==2){
				if(corretas==tam){
					desenhaforca(erros);
					printf("O COMPUTADOR ACERTOU A PALAVRA -> %s <-\n", psecreta);	
				}
				else if(erros==erros_tentativas){
					desenhaforca(erros);
					printf("O COMPUTADOR NAO ACERTOU A PALAVRA -> %s <-", psecreta);
					}
				}
			}
	return 0;
}
