#include <bits/stdc++.h>

struct estruturaDoProduto
{
    char nomeDoProduto[50];
    int idProduto;
    float preco;
    /*
    int qtdEstoque;
    float precoDeCusto;
    */
} produto[1000];

struct estruturaDoPedido
{
    int idPedido;
    int produtosPedidos[100];
    float total;
    /*
    int dia, mes, ano;
    */
} pedido[1000];

using namespace std;

bool ProcuraPedido(int numPed, char nomePed[50], float &preco)
{
    char pedidoLido[50];
    int numPedLido;
    float precoLido;


    FILE *arquivo;

    arquivo = fopen("Cardapio.txt", "r");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %s %f\n", &numPedLido, &pedidoLido, &precoLido);
        if (numPedLido == numPed)
        {
            strcpy(nomePed, pedidoLido);
            //nomePed = pedidoLido ;
            preco = precoLido;
            fclose(arquivo);
            return true;
        }
    }

    fclose(arquivo);
    return false;
}

//void faturamentoDiario()

int main()
{
    char nomePed[50];
    float preco, faturamentTot=0;
    int pedido, dia = 1, i=1, j;

    while (dia != 0)
    {
        cout << "Digite o numero do pedido: "
             << endl;

        cin >> pedido;

        if (ProcuraPedido(pedido, nomePed, preco))
        {
            cout << "PEDIDO: " << nomePed << "\n";
            cout << "Preco: " << preco << "\n";
        }

        produto[i].idProduto = pedido;
        strcpy(produto[i].nomeDoProduto,nomePed);
        produto[i].preco = preco;
        i++;
        faturamentTot += preco;
        cout << "Finalizar dia? [1]Nao [0]Sim" << endl;
        cin >> dia;
    }




    cout << "Lista de vendas diaria:"
         << "\n";
    for(j=1; j<i; j++){
    cout << produto[j].idProduto << "  " <<produto[j].nomeDoProduto << "  " << produto[j].preco << endl;
    }
    cout << "faturamento do dia: " << faturamentTot <<endl;
    return 0;
}
