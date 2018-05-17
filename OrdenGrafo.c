/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"


int cmpfunc (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = (vertice_1->nombre)-(vertice_2->nombre);
	return resultado;
}

void OrdenNatural(Grafo G) {
    qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunc);
}

int cmpfuncgrado (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = ( vertice_2->grado )-(vertice_1->grado);
	return resultado;
}
void OrdenWelshPowell(Grafo G){
	qsort(G->orden,G->nro_vertices,sizeof(PVertice), cmpfuncgrado);
}

int cmpfunccolor (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = (vertice_2->color )-(vertice_1->color);
	return resultado;
}

int cmpfunccantcolor (const void * a, const void * b) {
  PVertice vertice_1 = *(PVertice*)a;
  PVertice vertice_2 = *(PVertice*)b;
  int resultado = (vertice_1->cant_de_colores)-(vertice_2->cant_de_colores);
  return resultado;
}

int cmpfuncaleat(const void * a, const void * b){
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
	vertice_1->aleatorio = mi_rand(vertice_1->color)-(vertice_1->x_aleatorio);
	vertice_2->aleatorio = mi_rand(vertice_2->color)-(vertice_2->x_aleatorio);
	int resultado = (vertice_1->aleatorio>vertice_2->aleatorio);
	return resultado;

}
void ReordenManteniendoBloqueColores(Grafo G,u32 x) {
    if (x == 0) {
        qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccolor);
    } else if (x == 1) {
      for (u32 i = 0; i<G->nro_vertices; i++) {
        G->orden[i]->cant_de_colores = NumeroDeVerticesDeColor(G, G->orden[i]->color);
      }
      qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccolor);
      qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccantcolor);
    } else if (x > 1) {
			for(u32 i = 0; i < G->nro_vertices; i++){
				G->vertices[i].x_aleatorio= x;
			}
			qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfuncaleat);
    }
}
