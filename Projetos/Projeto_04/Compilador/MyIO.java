
import java.util.Scanner;

public class MyIO {

    public Scanner sc;

    /**
     * @author Gabriel Nogueira
     * @reason Remove a palavra "Início" do arquivo_de_teste.ula
     * @param null
     * @return null
     */
    public void removerInicio() {
        sc.nextLine();
    }

    /**
     * @author Gabriel Nogueira
     * @reason Lê a linha do arquivo_de_teste.ula e armazena em uma string
     * @param null
     * @return null
     */
    public String lerLinha() {
        //this.entrada = sc.nextLine();
        return "";
    }

    /**
     * @author Gabriel Nogueira
     * @reason Verificar se a frase contém ';' ou se está vazia
     * @param entrada (entrada em String), i (indice da linha no arquivo .ula)
     * @return validez
     */
    public static boolean verificarFrase(String entrada, int i) {
        Boolean validez = false;
        if (!entrada.isEmpty()) {
            if (entrada.length() == ';') {
                validez = true;
                return validez;
            } else {
                System.out.println("ERRO na linha " + i + " : Ausência de ';'");
            }
        } else {
            System.out.println("ERRO na linha " + i + " : Linha vazia");
        }

        return validez;
    }


    /**
     * @author Gabriel Ferreira
     * @reason Lê a String de entrada 
     * @param entrada (entrada em String)
     * @return
     */
    public static char contLinha(String entrada)
    {

    }

    /**
     * @author Gabriel Ferreira
     * @reason Lê a frase e fazer atribuição de X e Y de acordo com a leitura do arquivo
     * @param entrada (entrada em String)
     * @return
     */
    public static void atribuirValor(String entrada) 
    {

    }

}
