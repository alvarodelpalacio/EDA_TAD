/*
 * lista.c	Representación memoria contigua
 *
 *  Created on: 15/12/2014
 *      Author: M J Polo
 */

#include "lista.h"
// 
int anula(Lista *l)
{ l->ultimo = -1;
   return 0; 
}

int vacia(Lista *l)
{ if (l->ultimo ==-1) return 1;
  else return 0;
 }

int inserta(tipoElemento x,tipoPosicion p, Lista *l)
{ tipoPosicion q;

  if (l->ultimo>=MAX) return -1;
  else if (p > l->ultimo+1 || p<0) return -2;
       else
	 { for (q = l->ultimo;q >=p; q--) 
		l->elementos[q+1] = l->elementos[q];
           l->ultimo=l->ultimo+1;
	   l->elementos[p]=x;
           return 0;
      	 }
}
int suprime (tipoPosicion p, Lista *l)
{ 
tipoPosicion q;
if(p>=l->ultimo+1 || p<0){
  printf("la posicion no existe\n");
  }else{
    l->ultimo = l->ultimo-1;
    for(q=p;q<=l->ultimo;q++){
      l->elementos[q]=l->elementos[q+1];
    }
  }
}


tipoPosicion localiza(tipoElemento x, Lista *l)
{ 
tipoPosicion q;
    for(q=1;q<=l->ultimo;q++){
      if (l->elementos[q]== x)
      return q;
    }
    return l->ultimo+1;
}
tipoElemento recupera(tipoPosicion p, Lista *l)
{  
 if(p < 0  || p > MAX){
  return -3;
 }
  return l->elementos[p];
}

void imprime(Lista *l)
{ tipoPosicion q;

  for (q = primero(l);q <=l->ultimo; q++)
	printf("%d ",l->elementos[q]) ;
}

tipoPosicion primero(Lista *l)
{ if (!vacia(l)) return 0;
  else return fin(l);
}

tipoPosicion siguiente(tipoPosicion p, Lista *l)
{ if (p!=fin(l)) 
	return p+1;
  else 
  	return -1;
}

tipoPosicion anterior(tipoPosicion p, Lista *l)
{

}
tipoPosicion fin(Lista *l)
{ 
	return l->ultimo+1;
}


