#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool ProcuraPedido(int numPed, string nomePed, float &preco){
    string pedidoLido;
    int numPedLido;
    float precoLido;

    FILE *arquivo;

    arquivo = fopen("Cardapio.txt","r");

    while(!feof(arquivo)){
        fscanf(arquivo,"%d %s %f\n", &numPedLido, pedidoLido, &precoLido);
        if(numPedLido==numPed){
            strcpy(pedidoLido, nomePed);
            preco = precoLido;
            return true;
        }
    }

    fclose(arquivo);
    return false;
}


int main(){
    string nomePed;
    float preco;
    int pedido;

    cout<<"Digite o numero do pedido: "<<"\n"<<endl;
    cin>>pedido;

    if(ProcuraPedido(pedido,nomePed,preco)){
        cout<<"PEDIDO: "<<nomePed<<"\n";
        cout<<"Preco: "<<preco<<"\n";
    }

    return 0;
}
