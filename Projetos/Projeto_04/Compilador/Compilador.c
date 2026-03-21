#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyIO.h"

#define ARQUIVO_NOME "test.ula"
#define ARQUIVO_HEX "test.hex"

/**
 * @author Gabriel Nogueira
 * 
 * @param arquivo_fp
 * 
 * @reason  Funcao cria duas pilhas:
 *          Pilha A para ler os dados e armazená-los da maneira invertida ao processamento
 *          Pilha B para receber os dados da pilha A e armazená-los na ordem correta
 * 
 * @return pilhaB
 */
Pilha* lerLinhas(FILE* arquivo_fp)
{
    Pilha* pilhaA = criarPilha();
    Pilha* pilhaB = criarPilha();
    int indiceLinha = 1;
    bool continuar = true;
    char linha[MAX_STRING_SIZE];

    // Remove a linha "inicio"
    fgets(linha, sizeof(linha), arquivo_fp);

    while (fgets(linha, sizeof(linha), arquivo_fp) != NULL && continuar)
    {
        indiceLinha++;

        if (linhaValida(linha))
        {
            push(pilhaA, linha);
        }
        else
        {
            printErroLinha(linha, indiceLinha);
            continuar = false;
        }
    }

    // Transfere as linhas da pilha A para pilha B, armazenando na ordem correta
    while (!pilhaVazia(pilhaA))
    {
        char* elemento = pop(pilhaA);
        push(pilhaB, elemento);
        free(elemento);
    }

    free(pilhaA);
    return pilhaB;
}

/**
 * @author Gabriel Ferreira
 * 
 * @param pilhaResultado, ARQUIVO_HEX
 * 
 * @reason  Funcao que vai pegar a PilhaB trocar para os seus valores correspondende
 * e vai gerar um arquivo test.hex
 * 
 * @return pilhaB
 */

void gerarArquivoHex(Pilha* pilhaResultado)
{
    FILE* arquivoHex = fopen(ARQUIVO_HEX, "w");

    if (arquivoHex == NULL)
    {
        printf("Erro ao criar o arquivo %s\n", ARQUIVO_HEX);
    }
    
    else
    {
        while (!pilhaVazia(pilhaResultado))
        {
            char* linha = pop(pilhaResultado);
            char resultado = trocarMne(linha);
            fprintf(arquivoHex, "%c\n", resultado);
            free(linha);
        }
    }

    fclose(arquivoHex);
}

int main(void)
{
    FILE* arquivo_fp = fopen(ARQUIVO_NOME, "r");

    if (arquivo_fp != NULL)
    {
        Pilha* pilhaResultado = lerLinhas(arquivo_fp);
        fclose(arquivo_fp);

        //imprimirPilha(pilhaResultado);

        gerarArquivoHex(pilhaResultado);
        free(pilhaResultado);
    }
    else
    {
        printf("Erro ao abrir o arquivo %s\n", ARQUIVO_NOME);
        return 1;
    }

    return 0;
}

