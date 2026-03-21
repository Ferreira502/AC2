// Função          Mnemonico    Código Hexa
// W=Y             CopiaB       0
// W=X             CopiaA       1
// W=X⊕Y          AxB          2
// W=X'⊕B'        nAxnB        3
// W=(X.Y)'        AeBn         4
// W=Y'            nB           5
// W=X'+Y'         naonB        6
// W=A'            nA           7
// W=X+Y'          AonB         8
// W=F             UmL          9
// W=0             ZeroL        A
// W=X.Y           AeB          B
// W=X'.Y          nAeB         C
// W=X.Y'          AenB         D
// W=X+Y           AoB          E
// W=X'.Y'         nAeBn        F

#include <stdio.h>
#include <string.h>
#define MAX 10

char trocarMne ( char palavra[] )
{
    char x;

    if ( palavra[1] == '=' )
    {
        /* 1 */  
        if ( palavra[2] == 'C' && palavra[7] == 'B' ) // CopiaB
        {
            x = '0';
        }

        /* 2 */
        if ( palavra[2] == 'C' && palavra[7] == 'A' ) // CopiaA
        {
            x = '1';
        }

        /* 4 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'x' && palavra[5] == 'n' && palavra[6] == 'B' ) // nAxnB
        {
            x = '3';
        }
         
        /* 7 */
        if ( palavra[2] == 'n' && palavra[3] == 'a' && palavra[4] == 'o' && palavra[5] == 'n' && palavra[6] == 'B' ) // naonB
        {
            x = '6';
        }

        /* 11 */
        if ( palavra[2] == 'Z' && palavra[3] == 'e' && palavra[4] == 'r' && palavra[5] == 'o' && palavra[6] == 'L'  ) // ZeroL
        {
            x = 'A';
        }

        /* 16 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'e' && palavra[5] == 'B' && palavra[6] == 'n'  ) // nAeBn
        {
            x = 'F';
        }

        /* 14 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'n' && palavra[5] == 'B' ) // AenB
        {
            x = 'D' ;
        }

        /* 5 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'B' && palavra[5] == 'n' ) // AeBn
        {
            x = '4';
        }

        /* 9 */
        if ( palavra[2] == 'A' && palavra[3] == 'o' && palavra[4] == 'n' && palavra[5] == 'B' ) // AonB
        {
            x = '8';
        }
    
        /* 13 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'e' && palavra[5] == 'B' ) // nAeB
        {
            x = 'C';
        }
        
        /* 3 */
        if ( palavra[2] == 'A' && palavra[3] == 'x' && palavra[4] == 'B' ) // AxB
        {
            x = '2';
        }    

        /* 6 */
        if ( palavra[2] == 'n' && palavra[3] == 'B' ) // nB
        {
            x = '5';
        }

        /* 8 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' ) // nA
        {
            x = '7';
        }

        /* 10 */
        if ( palavra[2] == 'U' && palavra[3] == 'm' && palavra[4] == 'L' ) // UmL
        {
            x = '9';
        }

        /* 12 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'B' ) // AeB
        {
            x = 'B';
        }
        
        /* 15 */
        if ( palavra[2] == 'A' && palavra[3] == 'o' && palavra[4] == 'B' ) // AoB
        {
            x = 'E';
        }

    }

    return x;
}

int main()
{
    char palavra[MAX] = "w=CopiaA;";
    char resultado;

    resultado = trocarMne(palavra);

    printf("%c", resultado);
}


/*
    A lógica está escrita diferente da ordem proposta na tabela do exercício
    ou seja, o número acima de cada if representa a posição na tabela original. 
    Como o compilador da linguagem C lê sequencialmente de cima para baixo, foi necessário reordenar, 
    pois as funções 7 e 16 possuem o mesmo início "nA".
*/