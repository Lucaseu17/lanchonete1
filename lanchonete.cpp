#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

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
    cout <<setw(3) << left << "id" <<  "  "<<
           setw(15)<< left << "produto"<< "  " <<
           setw(15)<< left << "preco de Custo" << "  " <<
           setw(10)<< left << "quantidade" << "\n" << endl;
    while(!feof(arquivo)){
    fscanf(arquivo,"%d %s %f %d",&id, &prod, &precoDeCusto, &quant);

    cout << setw(3)<< left << id << "  " <<
           setw(15)<< left << prod << "  R$" <<
           setw(15)<< left << precoDeCusto << "  " <<
           setw(10)<< left << quant << endl;
    }
}


void alteraEstoque(int numProd, int uni){
    int id, quant, q;
    char prod[50];
    float precoDeCusto;

 FILE *arquivo;

    arquivo = fopen("Estoque.txt", "a");

    {
        fscanf(arquivo,"%d %s %f %d",&id, &prod, &precoDeCusto, &quant);

            if(id==numProd){
                q = quant - uni;
                fprintf(arquivo,"%d",q);
            }
    }

}

int main()
{
    char nomePed[50];
    float preco, faturamentTot=0, precoTot;
    int pedido, sim = 1, i=1, j, k=1;
    int numCom, Unid[1000], unidade;



    while (sim != 0)
    {
//        cout << "Digite o numero da comanda: "
//        cin >> numCom;
//
        cout << "Digite o numero do pedido: ";
        cin >> pedido;
        cout <<"\n";

        if (ProcuraPedido(pedido, nomePed, preco))
        {
            cout << "PEDIDO: " << nomePed << "\n\n";
            cout << "Numero de Unidades: ";
            cin >> unidade;
            Unid[k] = unidade;
            k++;
            precoTot = preco*unidade;
            cout << "\n\n" << "Preco: R$" << precoTot << "\n\n";
//            if(pedido <= 5)
                alteraEstoque(pedido, unidade);
        }else{
            cout <<"Pedido nao encontrado \n" <<endl;
        }



        produto[i].idProduto = pedido;
        strcpy(produto[i].nomeDoProduto,nomePed);
        produto[i].preco = precoTot;
        i++;
        faturamentTot += precoTot;


        cout << "Finalizar dia?   [1]Nao [0]Sim\n" << endl;
        cin >> sim;
        cout <<"\n";
    }

    FILE *arquivo2;

    arquivo2 = fopen("faturamentoDiario.txt", "w");

    fprintf(arquivo2,"Lista de vendas diaria: \n");

    cout << "Lista de vendas diaria:"
         << "\n\n";

//    time_t rawtime;
//    struct tm * timeinfo;
//
//    time ( &rawtime );
//    timeinfo = localtime ( &rawtime );
//    printf ( "Data atual do sistema é: %s", asctime (timeinfo) );
    auto now = system_clock::now();
    time_t t = system_clock::to_time_t(now); // poderia ser auto t = ...


    for(j=1; j<i; j++){
    cout <<setw(4)<<left<< put_time(localtime(&t), "%c") << "  " <<
           setw(17)<<left<< produto[j].nomeDoProduto <<
           setw(3)<<left<< Unid[j]<< "uni" <<"  "<<
           setw(4) << left << "  R$" << produto[j].preco << endl;

    fprintf(arquivo2,"%d",produto[j].idProduto);
    fprintf(arquivo2,"  ");
    fprintf(arquivo2,"%s",produto[j].nomeDoProduto);
    fprintf(arquivo2,"  R$");
    fprintf(arquivo2,"%.2f",produto[j].preco);
    fprintf(arquivo2,"\n");
    }

    cout <<"\n"<<setw(48)<< "faturamento do dia: " << "R$" << faturamentTot << "\n" << endl;

    fprintf(arquivo2,"faturamento do dia: R$");
    fprintf(arquivo2,"%.2f",faturamentTot);

    cout << "Mostrar estoque?     [1]Sim [0]Nao" <<endl;
    cin >> sim;
    cout << "\n";

    if(sim == 1){
        mostrarEstoque();
    }


    return 0;
}
