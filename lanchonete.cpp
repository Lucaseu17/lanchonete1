#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

struct estruturaDoEstoque
{
    int id;
    char nomProduto[100];
    float precoDeCusto;
    int quantidadeRestante;
} estoque[1000];

//
//void fazEstoque(int N, char produto[50], float precoDeC, int quantid){

void alteraEstoque(int ID, int uni)
{ //entra com o numero do pedido e com o numero de unidades
    int r = 0, id, quant, aux;
    char prod[50];
    float precoDeCusto;

    FILE *arquivo3;

    arquivo3 = fopen("Estoque.txt", "r");

    while (fscanf(arquivo5, "%d %s %f %d", &id, prod, &precoDeCusto, &quant))
    { // guarda os dados do arquivo na struct estoque

        estoque[id].id = id;
        strcpy(estoque[id].nomProduto, prod);
        estoque[id].precoDeCusto = precoDeCusto;
        estoque[id].quantidadeRestante = quant;
        r++;
    }

    fclose(arquivo3);

    aux = estoque[ID].quantidadeRestante; //altera a quantidade do produto com o ID do pedido feito
    estoque[ID].quantidadeRestante = aux - uni;

    FILE *arquivo3;

    arquivo3 = fopen("Estoque1.txt", "w");

    for (int t = 0; t < r; t++)
    { // copia a struct estoque em um novo arquivo com a alteracao
        fprintf(arquivo3, "%d", estoque[t].id);
        fprintf(arquivo3, "  ");
        fprintf(arquivo3, "%s", estoque[t].nomProduto);
        fprintf(arquivo3, "  R$");
        fprintf(arquivo3, "%.2f", estoque[t].precoDeCusto);
        fprintf(arquivo3, "  ");
        fprintf(arquivo3, "%d", estoque[t].quantidadeRestante);
        fprintf(arquivo3, "\n");
    }

    fclose(arquivo3);
    //        for(int u=1; u<i; u++){
    //            cout << setw(4)<<left<< estoque[j].id << "  " <<
    //                    setw(17)<<left<< estoque[j].nomProduto <<"  " <<
    //                    setw(3)<<left<< "  R$" << estoque[j].precoDeCusto <<"  "<<
    //                    setw(4)<< left << estoque[j].quantidadeRestante << endl;

    //    fprintf(arquivo3,"%d",estoque[r].id);
    //    fprintf(arquivo3,"  ");
    //    fprintf(arquivo3,"%s",estoque[r].nomProduto);
    //    fprintf(arquivo3,"  R$");
    //    fprintf(arquivo3,"%.2f",estoque[r].precoDeCusto);
    //    fprintf(arquivo3,"  ");
    //    fprintf(arquivo3,"%d",estoque[r].quantidadeRestante);
    //    fprintf(arquivo3,"\n");
}

//void alteraEstoque(int ID, int uni){
//    int aux;
//
//    aux = estoque[ID].quantidadeRestante
//    estoque[ID].quantidadeRestante = aux - uni;
//
//    FILE *arquivo3;
//
//        arquivo3 = fopen("estoque.txt", "w");
//
//    for (int t=0, t != NULL, t++){
//    fprintf(arquivo3,"%d",estoque[t].id);
//    fprintf(arquivo3,"  ");
//    fprintf(arquivo3,"%s",estoque[t].nomProduto);
//    fprintf(arquivo3,"  R$");
//    fprintf(arquivo3,"%.2f",estoque[t].precoDeCusto);
//    fprintf(arquivo3,"  ");
//    fprintf(arquivo3,"%d",estoque[t].quantidadeRestante);
//    fprintf(arquivo3,"\n");
//    }
//}

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
        fscanf(arquivo, "%d %s %f\n", &numPedLido, pedidoLido, &precoLido);
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

void mostrarEstoque()
{
    int id, quant;
    char prod[50];
    float precoDeCusto;

    FILE *arquivo3;

    arquivo3 = fopen("Estoque1.txt", "r");
    cout << setw(3) << left << "id"
         << "  " << setw(15) << left << "produto"
         << "  " << setw(15) << left << "preco de Custo"
         << "  " << setw(10) << left << "quantidade"
         << "\n"
         << endl;

    while (!feof(arquivo3))
    {
        fscanf(arquivo3, "%d %s %f %d", &id, &prod, &precoDeCusto, &quant);

        cout << setw(3) << left << id << "  " << setw(15) << left << prod << "  R$" << setw(15) << left << precoDeCusto << "  " << setw(10) << left << quant << endl;
    }
    fclose(arquivo3);
}

int main()
{
    char nomePed[50];
    float preco, faturamentTot = 0, precoTot;
    int pedido, sim = 1, i = 1, j, k = 1;
    int numCom, Unid[1000], unidade;

    while (sim != 0)
    {
        //        cout << "Digite o numero da comanda: "
        //        cin >> numCom;
        //
        cout << "Digite o numero do pedido: ";
        cin >> pedido;
        cout << "\n";

        if (ProcuraPedido(pedido, nomePed, preco))
        {
            cout << "PEDIDO: " << nomePed << "\n\n";
            cout << "Numero de Unidades: ";
            cin >> unidade;
            Unid[k] = unidade;
            k++;
            precoTot = preco * unidade;
            cout << "\n\n"
                 << "Preco: R$" << precoTot << "\n\n";

            alteraEstoque(pedido, unidade);
            //                cout << "estoque alterado"<<endl;
        }
        else
        {
            cout << "Pedido nao encontrado \n"
                 << endl;
        }

        produto[i].idProduto = pedido;
        strcpy(produto[i].nomeDoProduto, nomePed);
        produto[i].preco = precoTot;
        i++;
        faturamentTot += precoTot;

        cout << "Finalizar dia?   [1]Nao [0]Sim\n"
             << endl;
        cin >> sim;
        cout << "\n";
    }

    FILE *arquivo2;

    arquivo2 = fopen("faturamentoDiario.txt", "w");

    fprintf(arquivo2, "Lista de vendas diaria: \n");

    cout << "Lista de vendas diaria:"
         << "\n\n";

    //    time_t rawtime;
    //    struct tm * timeinfo;
    //
    //    time ( &rawtime );
    //    timeinfo = localtime ( &rawtime );
    //    printf ( "Data atual do sistema �: %s", asctime (timeinfo) );
    auto now = system_clock::now();
    time_t t = system_clock::to_time_t(now); // poderia ser auto t = ...

    for (j = 1; j < i; j++)
    {
        cout << setw(4) << left << put_time(localtime(&t), "%c") << "  " << setw(17) << left << produto[j].nomeDoProduto << setw(3) << left << Unid[j] << "uni"
             << "  " << setw(4) << left << "  R$" << produto[j].preco << endl;

        fprintf(arquivo2, "%d", produto[j].idProduto);
        fprintf(arquivo2, "  ");
        fprintf(arquivo2, "%s", produto[j].nomeDoProduto);
        fprintf(arquivo2, "  R$");
        fprintf(arquivo2, "%.2f", produto[j].preco);
        fprintf(arquivo2, "\n");
    }

    cout << "\n"
         << setw(48) << "faturamento do dia: "
         << "R$" << faturamentTot << "\n"
         << endl;

    fprintf(arquivo2, "faturamento do dia: R$");
    fprintf(arquivo2, "%.2f", faturamentTot);

    fclose(arquivo2);

    cout << "Mostrar estoque?     [1]Sim [0]Nao" << endl;
    cin >> sim;
    cout << "\n";

    if (sim == 1)
    {
        mostrarEstoque();
    }

    return 0;
}
