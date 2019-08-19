#include <bits/stdc++.h>

using namespace std;

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


//struct estruturaDaComanda
//{
//    int idPedido;
//    struct estruturaDoProduto;
//    float total;
//    /*
//    int dia, mes, ano;
//    */
//} comanda[1000];



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


void mostrarEstoque(){
    int id, quant;
    char prod[50];
    float precoDeCusto;

 FILE *arquivo;

    arquivo = fopen("Estoque.txt", "r");
    cout << "id" <<"  "<<"produto"<<"  "<<"preco"<<"  "<<"qntd"<<endl;
    while(!feof(arquivo)){
    fscanf(arquivo,"%d %s %f %d",&id, &prod, &precoDeCusto, &quant);

    cout << id <<"  "<< prod <<"  " << precoDeCusto <<"  " << quant<<endl;
    }
}


void alteraEstoque(int numProd, int quantidade){

 FILE *arquivo;

    arquivo = fopen("Cardapio.txt", "r");



}

int main()
{
    char nomePed[50];
    float preco, faturamentTot=0;
    int pedido, sim = 1, i=1, j;
    int numCom;



    while (sim != 0)
    {
//        cout << "Digite o numero da comanda: "
//        cin >> numCom;
//
        cout << "Digite o numero do pedido: "
             << endl;

        cin >> pedido;


        if (ProcuraPedido(pedido, nomePed, preco))
        {
            cout << "PEDIDO: " << nomePed << "\n";
            cout << "Preco: R$" << preco << "\n";
        }



        produto[i].idProduto = pedido;
        strcpy(produto[i].nomeDoProduto,nomePed);
        produto[i].preco = preco;
        i++;
        faturamentTot += preco;


        cout << "Finalizar dia? [1]Nao [0]Sim" << endl;
        cin >> sim;
    }

    FILE *arquivo2;

    arquivo2 = fopen("faturamentoDiario.txt", "w");

    fprintf(arquivo2,"Lista de vendas diaria: \n");

    cout << "Lista de vendas diaria:"
         << "\n";

    for(j=1; j<i; j++){
    cout << produto[j].idProduto << "  " <<produto[j].nomeDoProduto << "  R$" << produto[j].preco << endl;

    fprintf(arquivo2,"%d",produto[j].idProduto);
    fprintf(arquivo2,"  ");
    fprintf(arquivo2,"%s",produto[j].nomeDoProduto);
    fprintf(arquivo2,"  R$");
    fprintf(arquivo2,"%.2f",produto[j].preco);
    fprintf(arquivo2,"\n");
    }
    cout << "faturamento do dia: R$" << faturamentTot <<endl;

    fprintf(arquivo2,"faturamento do dia: R$");
    fprintf(arquivo2,"%.2f",faturamentTot);

    cout << "Mostrar estoque?     [1]Sim [0]Nao"<<endl;
    cin >> sim;

    if(sim == 1){
        mostrarEstoque();
    }


    return 0;
}
