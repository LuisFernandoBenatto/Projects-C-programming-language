//************************************************************************************************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//************************************************************************************************************************************************************************************************************
typedef struct farmacia{
        int cod;
        char nome_remedio[100];
        int quant_estoque;
        double preco;
        char categoria[50];
        char fabricante[50];
        char generico[10];
        char status;
}Farmacia;
//************************************************************************************************************************************************************************************************************
int cadastrar(Farmacia f){
    FILE *arquivo = fopen("Farmacia.txt","a+b");
    if(arquivo == NULL){
        printf("Falha ao abrir o arquivo!\n");
        exit(1);
    }
    int result = fwrite(&f, sizeof(Farmacia), 1, arquivo);
    fclose(arquivo);
    return result;
}
//************************************************************************************************************************************************************************************************************
void buscar(int codigo){
    FILE *arquivo = fopen("Farmacia.txt","r+b");
    Farmacia f;

    int vamos_encontrar = 0;

    if(arquivo == NULL){
        printf("Falha ao abrir arquivo!!!\n");
        system("pause");
        system("cls");
        return;
    }
    while(fread(&f, sizeof(Farmacia), 1, arquivo)){
        if(f.cod == codigo){
            vamos_encontrar = 1;
            break;
        }
    }
    if(vamos_encontrar){
        if(f.status == '*'){
            printf("Esse registro ja foi apagado!!\n\n");
            system("pause");
            system("cls");
            return;
        }else{
            printf("***********************************\n");
            printf("* Codigo: %d\n* Nome do remedio: %s\n",f.cod,f.nome_remedio);
            printf("* Quantidade em estoque: %d\n* Preco: %.2f\n",f.quant_estoque,f.preco);
            printf("* Categoria: %s\n* Fabricante: %s\n* Generico: %s\n",f.categoria,f.fabricante,f.generico);
            printf("***********************************\n\n");
        }
    } else{
        printf("Codigo nao encontrado!!!\n\n");
    }
    system("pause");
    system("cls");
    fclose(arquivo);
}
//************************************************************************************************************************************************************************************************************
void listar(){
    FILE *arquivo = fopen("Farmacia.txt","r+b");
    Farmacia f;
    int encontrando_cadastros = 0;

    if(arquivo == NULL){
        printf("O arquivo esta vazio!!!\n");
        system("pause");
        system("cls");
        return;
    }
    system("cls");

    printf("Remedios cadastrados\n\n");

    while(fread(&f, sizeof(Farmacia), 1, arquivo)){
        if(f.status != '*'||f.cod != -100){
            printf("***********************************\n");
            printf("* Codigo: %d\n* Nome do remedio: %s\n",f.cod,f.nome_remedio);
            printf("* Quantidade em estoque: %d\n* Preco: %.2f\n",f.quant_estoque,f.preco);
            printf("* Categoria: %s\n* Fabricante: %s\n* Generico: %s\n",f.categoria,f.fabricante,f.generico);
        }
    }
    printf("\n\n");
    system("pause");
    system("cls");
    fclose(arquivo);
}
//************************************************************************************************************************************************************************************************************
int alterar(Farmacia f,int codigo){
    FILE *arquivo = fopen("Farmacia.txt","r+b");

    int vamos_encontrar = 0;

    if(arquivo == NULL){
        printf("Falha ao abrir arquivo!!!\n");
        system("pause");
        system("cls");
        return;
    }
    if(f.status == '*'){
        printf("Esse registro já foi apagado!!!\n\n");
        system("pause");
        system("cls");
        return;
    }
    while(fread(&f, sizeof(Farmacia), 1, arquivo)){
        if(f.cod == codigo){
            vamos_encontrar = 1;
            break;
        }
    }if(vamos_encontrar){
        printf("Dados atuais do cadastro\n");
        printf("***********************************\n");
        printf("* Codigo: %d\n* Nome do remedio: %s\n",f.cod,f.nome_remedio);
        printf("* Quantidade em estoque: %d\n* Preco: %.2f\n",f.quant_estoque,f.preco);
        printf("* Categoria: %s\n* Fabricante: %s\n* Generico: %s\n",f.categoria,f.fabricante,f.generico);
        f.status = '*';
        f.cod = -100;
        fseek(arquivo, -(long) sizeof(Farmacia), SEEK_CUR);
        fwrite(&f, sizeof(Farmacia), 1, arquivo);
        fflush(arquivo);
        fclose(arquivo);

    fopen("Farmacia.txt","a+b");

        if(f.status == '*'){
            printf("Novo cadastro\n\n");

            f.status = ' ';
            printf("Codigo: ");
            scanf("%d",&f.cod);

            fflush(stdin);
            printf("Nome do remedio: ");
            fgets(f.nome_remedio,100, stdin);
            f.nome_remedio[strlen(f.nome_remedio)-1] = 0;

            printf("Quantidade em estoque: ");
            scanf("%i",&f.quant_estoque);

            printf("Preco: ");
            scanf("%lf",&f.preco);

            fflush(stdin);
            printf("Fabricante: ");
            fgets(f.fabricante,50, stdin);
            f.fabricante[strlen(f.fabricante)-1] = 0;

            printf("Categoria: ");
            fgets(f.categoria,50, stdin);
            f.categoria[strlen(f.categoria)-1] = 0;

            printf("Generico (SIM) ou (NAO): ");
            scanf("%[^\n]s",f.generico);

            if(cadastrar(f)){
                printf("\nItem inserido com sucesso!!!\n\n");
                system("pause");
                system("cls");
            }
        }
    }else{
        printf("Codigo nao encontrado!!!\n\n");
        system("pause");
        system("cls");
    }

    fclose(arquivo);
}
//************************************************************************************************************************************************************************************************************
int deletar(Farmacia f,int codigo){
       FILE *arquivo = fopen("Farmacia.txt","r+b");

    int vamos_encontrar = 0;

    if(arquivo == NULL){
        printf("Falha ao abrir arquivo!!!\n");
        system("pause");
        system("cls");
        return;
    }
    if(f.status == '*'){
        printf("Esse registro já foi apagado!!!\n\n");
        system("pause");
        system("cls");
        return;
    }
    while(fread(&f, sizeof(Farmacia), 1, arquivo)){
        if(f.cod == codigo){
            vamos_encontrar = 1;
            break;
        }
    }if(vamos_encontrar){
        printf("Dados atuais do cadastro\n");
        printf("***********************************\n");
        printf("* Codigo: %d\n* Nome do remedio: %s\n",f.cod,f.nome_remedio);
        printf("* Quantidade em estoque: %d\n* Preco: %.2f\n",f.quant_estoque,f.preco);
        printf("* Categoria: %s\n* Fabricante: %s\n* Generico: %s\n",f.categoria,f.fabricante,f.generico);
        printf("***********************************\n\n");

        f.status = '*';
        f.cod = -100;

        printf("Registro apagado!!!\n");
        system("pause");
        system("cls");

    }else{
        printf("Codigo nao encontrado!!!\n\n");
        system("pause");
        system("cls");
    }
    fseek(arquivo, -(long) sizeof(Farmacia), SEEK_CUR);
    fwrite(&f, sizeof(Farmacia), 1, arquivo);
    fflush(arquivo);
    fclose(arquivo);
}
//************************************************************************************************************************************************************************************************************
void apagar_tudo(){
    FILE *arquivo = fopen("Farmacia.txt","w+b");

    if(arquivo) {
        fclose(arquivo);
        printf("\nBanco de dados Farmacia.txt foi excluido por inteiro!!!\n\n");
        remove("Farmacia.txt");
        system("pause");
        system("cls");
        return 1;
    }else{
        printf("\nNao existe nenhum Farmacia.txt\n\n");
        system("pause");
        system("cls");
    }
}
//************************************************************************************************************************************************************************************************************
int verificar_codigo(int codigo){
    FILE *arquivo = fopen("Farmacia.txt","r+b");
    Farmacia f;
    int codigo_ja_digitado = 0;

    while(fread(&f, sizeof(Farmacia), 1, arquivo) != NULL){
        if(codigo == f.cod){
        codigo_ja_digitado = 1;
        break;
        }
    }if(codigo_ja_digitado){
        printf("Codigo ja digitado!!!\n");
        return 1;
    }
}
//************************************************************************************************************************************************************************************************************
int main(){
    int op = -1;
    int codigo = 0;
    Farmacia f;
    do{
        printf("  ____                                          _         \n");
        printf(" |  _ \\   _ __    ___     __ _    __ _   _ __  (_)   __ _ \n");
        printf(" | | | | | '__|  / _ \\   / _` |  / _` | | '__| | |  / _` |\n");
        printf(" | | | | | |    | ( ) | | / | | | / | | | |    | | | / | |\n");
        printf(" | |_| | | |    | (_) | | \\_| | | \\_| | | |    | | | \\_| |\n");
        printf(" |____/  |_|     \\___/   \\__, |  \\__,_| |_|    |_|  \\__,_|\n");
        printf("                          |___/                            \n");
        printf("\t                 _         \n");
        printf("\t              __| |   ___  \n");
        printf("\t             / _` |  / _ \\\n");
        printf("\t            | / | | | ( ) |\n");
        printf("\t            | \\_| | | (_) |\n");
        printf("\t             \\__,_|  \\___/ \n");
        printf("  ____                                              \n");
        printf(" / ___|   __ _   _ __   _ __    __ _   _ __    __ _ \n");
        printf("| |      / _` | | '__| | '__|  / _` | | '__|  / _` |\n");
        printf("| |     | / | | | |    | |    | / | | | |    | / | |\n");
        printf("| |___  | \\_| | | |    | |    | \\_| | | |    | \\_| |\n");
        printf(" \\____|  \\__,_| |_|    |_|     \\__,_| |_|     \\__,_|\n\n\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Deletar\n");
        printf("5 - Listar todos\n");
        printf("99 - Apagar Tudo\n");
        printf("0 - Sair\n");
        printf("\nInforme um comando: ");
        scanf("%d",&op);
        printf("\n");

        switch(op){
            case 1:
                f.status = ' ';
                printf("Codigo: ");
                scanf("%d",&f.cod);

                while(verificar_codigo(f.cod) == 1){
                    printf("Informe outro codigo!!!\n\n");
                    printf("Codigo: ");
                    scanf("%d",&f.cod);
                }
                getchar();
                printf("Nome do remedio: ");
                fgets(f.nome_remedio,100, stdin);
                f.nome_remedio[strlen(f.nome_remedio)-1] = 0;

                printf("Quantidade em estoque: ");
                scanf("%i",&f.quant_estoque);

                printf("Preco: ");
                scanf("%lf",&f.preco);

                getchar();
                printf("Fabricante: ");
                fgets(f.fabricante,50, stdin);
                f.fabricante[strlen(f.fabricante)-1] = 0;

                printf("Categoria: ");
                fgets(f.categoria,50, stdin);
                f.categoria[strlen(f.categoria)-1] = 0;

                printf("Generico (SIM) ou (NAO): ");
                scanf("%[^\n]s",f.generico);

                if(cadastrar(f)){
                    printf("\nItem inserido com sucesso!!!\n\n");
                    system("pause");
                    system("cls");
                }
            break;
//************************************************************************************************************************************************************************************************************
            case 2:
                printf("\nDigite o Codigo: ");
                scanf("%d", &codigo);
                printf("\n");
                buscar(codigo);
            break;
//************************************************************************************************************************************************************************************************************
            case 3:
                printf("\nDigite o Codigo: ");
                scanf("%d", &codigo);
                printf("\n");
                alterar(f,codigo);
            break;
//************************************************************************************************************************************************************************************************************
            case 4:
                printf("\nDigite o Codigo: ");
                scanf("%d", &codigo);
                printf("\n");
                if(deletar(f,codigo)){
                    printf("Registro deletado com sucesso!!!\n\n");
                    system("pause");
                    system("cls");
                }
            break;
//************************************************************************************************************************************************************************************************************
            case 5:
                listar();
            break;
//************************************************************************************************************************************************************************************************************
            case 99:
                apagar_tudo();
            break;

            default:
                if(op == 0){
                    char imagem[9000];
                    FILE *arq = fopen("imagem final.txt","r+b");
                    while(fgets(imagem, 9000, arq) != NULL){
                        printf("%s",imagem);
                    }
                    fclose(arq);
                    printf("\nEncerramos por aqui, ate amanha!!!\n\n");
                }else{
                    printf("\nCodigo nao existente, digite outro!!!\n\n");
                }
                system("pause");
                system("cls");
//************************************************************************************************************************************************************************************************************
        }
    }while(op != 0);
}
