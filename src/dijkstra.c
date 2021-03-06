/*
  Módulo que contém o algoritmo de Dijkstra.

  Criação: 16/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX
#include "grafos_matriz.h"

#define INF INT_MAX
void dijkstra (Grafo G, int v, int *dis){

        // vetor responsável para indicar se o vértice 'i' já foi visitado ou não
        char vis[G.N];
        // seta todos como não visitado
        for (int i=0; i < G.N; i++)
            vis[i]=0;

        // Vetor de distâncias
        //int dis[G.N]; // Agora passado por parâmetro
        // seta todos como infinito
        for (int i=0; i < G.N; i++)
            dis[i]=INF;

        dis[v] = 0; // Seta a raiz como distância 0

        while (1){
                int i;
                int n = -1;

                // Vasculha todos os vértices do grafo para descobrir o próxio a analisar
                for (i = 0; i < G.N; i++)
                        if (!vis[i] && (n < 0 || dis[i] < dis[n])) // Se o vértice não foi visitado
                                n = i;

                if (n < 0) // Condição de saída
                        break;

                vis[n] = 1; // Marca o vértice atual como visitado

                for (i = 0; i < G.N; i++)
                        if (G.matrizAdj.matriz[n][i] && dis[i] > dis[n] + G.matrizAdj.matriz[n][i])
                                dis[i] = dis[n] + G.matrizAdj.matriz[n][i];
        }

       // return dis;

}


void dijkstra_all (Grafo G){
    int *dis = (int *) malloc(G.N * (sizeof(int)));

    for (int v=0; v < G.N; v++){

        dijkstra(G,v,dis);

        for (int i=0;i<G.N;i++){
            G.matrizAdj.matriz[v][i] = dis[i];

        }

    }


    free(dis);


}
