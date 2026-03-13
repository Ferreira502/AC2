import java.io.File;
import java.util.Scanner;

// Area de demonstração
// B9C

public class Compilador
{
    public static void main(String[] args)
    {
        int linha_Indice = 0;
        ExpressaoHex processador = new ExpressaoHex();
        String entrada = "";
        String condicacao_Parada = "fim.";
        char X = '\0';
        char Y = '\0';
        char OP_CODE = '\0';
        String W = "";  // Ou saida_em_Hexadecimal (para o arquivo .hex)
        
        try
        {
            Scanner leitor_arquivo = new Scanner ( new File ("testeula.ula") ); // Criar na MyIO uma funcao para ler do arquivo
            entrada = leitor_arquivo.nextLine();
            
            if(MyIO.verificarFrase(entrada, linha_Indice))
            {
                while(entrada != condicacao_Parada)
                {

                    entrada = leitor_arquivo.nextLine();
                }
                linha_Indice = linha_Indice + 1;
            }
            else
            {
                
            }


        }

        catch (java.io.FileNotFoundException e)
        {
            System.out.println("Arquivo nao encontrado: " + e.getMessage());
        }
    }
}