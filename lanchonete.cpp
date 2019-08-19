#include <bits/stdc++.h>
//PELEZINHO SEU VIADO

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
    float preco;
    int pedido, dia=1;
    struct listaDia{
        int numero;
        char pedido;
        float preco;
    };


    while(dia != 0){
    cout << "Digite o numero do pedido: "
         << endl;

    cin >> pedido;


    if (ProcuraPedido(pedido, nomePed, preco))
    {
        cout << "PEDIDO: " << nomePed << "\n";
        cout << "Preco: " << preco << "\n";
    }




    cout <<"Finalizar dia? [1]Nao [0]Sim"<<endl;
    cin >> dia;
    }

    cout << "Lista de vendas diaria:" << "\n";



    return 0;
}
