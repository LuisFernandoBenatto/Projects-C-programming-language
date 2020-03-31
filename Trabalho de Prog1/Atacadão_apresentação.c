#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char lojas[10][20];
char nm_produto[15][20];
float precos[10][15];
int quantia[10][15];
int estoque[10];
int produtos[15];
int precosxquantia[10][15];
int qtd_maior_estoque;
int qtd_menor_estoque;

void le_loja();
void le_produto();
void le_preco();
void le_quantia();
void questao_a(); // unidades em cada loja
void questao_b(); // unidades de cada produto
void questao_c(); // preco do protudo com mais unidades
void questao_d(); // preco do protudo com menos unidades
void questao_e(); // custo de cada loja


int main(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("**********************************************************************\n");
    printf("****************************   ATACADAO   ****************************\n");
    printf("**********************************************************************\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

	le_produto();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	le_loja();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	le_preco();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	le_quantia();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	questao_a();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	questao_b();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	questao_c();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	questao_d();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	questao_e();

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("*******                                                        *******\n");
    printf("*******                                                        *******\n");
    printf("**********************************************************************\n");

	system("pause");
	return 0;

}

void le_loja(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    printf("*******    Nome das 10 lojas:                                  *******\n");
	printf("******* (20 caracteres no maximo)                              *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l,c;
	for(l=0;l<10;l++){
		fgets(lojas[l], 20, stdin);
	}
	for(l=0;l<10;l++){
		for(c=0;c<20;c++){
			if(lojas[l][c]=='\n'){
				lojas[l][c]='\0';
			}
		}
	}
}

void le_produto(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    printf("*******   Nome dos 15 produtos:                                *******\n");
    printf("******* (20 caracteres no maximo)                              *******\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("*******                                                        *******\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

	int l,c;
	for(l=0;l<15;l++){
		fgets(nm_produto[l], 20, stdin);
	}
	for(l=0;l<15;l++){
		for(c=0;c<20;c++){
			if(nm_produto[l][c]=='\n'){
				nm_produto[l][c]='\0';
			}
		}
	}
}

void le_preco(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("******* Preco dos produtos:                                    *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c;
	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			scanf("%f", &precos[l][c]);
		}
	}
}

void le_quantia(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("******* Quantia em estoque:                                    *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c;
	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			scanf("%d", &quantia[l][c]);
		}
	}
}

void questao_a(){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("******* ESTOQUES:                                              *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c, qtd=0;
	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			qtd += quantia[l][c];
		}
		estoque[l] = qtd ;
		qtd = 0;
	}
	for(l=0;l<10;l++){
		printf("%s: %d unidades;\n", lojas[l], estoque[l]);
	}
}

void questao_b(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    printf("******* UNIDADES DE CADA PRODUTO:                              *******\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("*******                                                        *******\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c, qtd=0;
	for(c=0;c<15;c++){
		for(l=0;l<10;l++){
			qtd += quantia[l][c];
		}
		printf("%s: %d unidades;\n", nm_produto[c], qtd);
		qtd = 0;
	}
}

void questao_c(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("******* MAIOR ESTOQUE:                                         *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l_maior_estoque, c_maior_estoque;
	int l, c, maior=0, cont=0;
	float preco;

	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			if(quantia[l][c]>maior){
				l_maior_estoque = l;
				c_maior_estoque = c;
				maior = quantia[l][c];
			}
		}
	}

	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			if(quantia[l][c]==maior){
				cont++;
			}
		}
	}

	qtd_maior_estoque = maior;
	preco = precos[l_maior_estoque][c_maior_estoque];

	if(cont>1){
		printf("%d estoques possuem a mesma quantia de produtos, %d unidades!\n", cont, maior);
		for(l=0;l<10;l++){
			for(c=0;c<15;c++){
				if(quantia[l][c]==maior){
					printf("%s - Produto: %s; Preco: %.2f;\n", lojas[l], nm_produto[c], precos[l][c]);
				}
		}
	}
	} else {
		printf("%s - Produto: %s; Unidades: %d; Preco: %.2f;\n",
			lojas[l_maior_estoque], nm_produto[c_maior_estoque], maior, preco);
	}
}

void questao_d(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("******* MENOR ESTOQUE:                                         *******\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("*******                                                        *******\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c, maior=0, indice_menor=0, menor=0;
	for(l=0; l<10; l++){
		if(estoque[l]>maior){
			maior = estoque[l];
		}
	}
	menor = maior;
	for(l=0; l<10; l++){
		if(estoque[l]<maior && estoque[l]<menor){
			menor = estoque[l];
			indice_menor = l;
		}
	}
	printf("%s: %d unidades;\n", lojas[indice_menor], menor);
}

void questao_e(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    printf("******* CUSTO DAS LOJAS:                                       *******\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("*******                                                        *******\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

	int l, c;
	float custo=0;
	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			precosxquantia[l][c] = precos[l][c] * quantia[l][c];
		}
	}
	for(l=0;l<10;l++){
		for(c=0;c<15;c++){
			custo += precosxquantia[l][c];
		}
		printf("%s: R$ %.2f de custo;\n", lojas[l], custo);
		custo = 0;
	}
}
