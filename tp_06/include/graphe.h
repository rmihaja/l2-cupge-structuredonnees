#ifndef __GRAPHE_H__
#define __GRAPHE_H__

typedef struct s_sommet *Sommet;
typedef struct s_arc *Arc;
typedef struct s_graphe *Graphe;

Graphe initGraphe(void);
Arc initArc(char*, char*);

void ajouteArc(Arc, Graphe);
void supprimeArc(Arc, Graphe);

int existeSommet(Sommet, Graphe);
int existeArc(Arc, Graphe);



#endif