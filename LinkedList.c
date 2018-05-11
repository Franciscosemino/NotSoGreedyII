/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

linklist AddNode(linklist ll,u32 newvalue){
	if(ll==NULL){
		node newnode=calloc(1,sizeof(struct _Node_t));
		ll=newnode;
		ll->value=newvalue;
		ll->next=NULL;
		return ll;
	}
	node newnode=calloc(1,sizeof(struct _Node_t));
	newnode->value=newvalue;
	newnode->next=ll;
	ll=newnode;
	return ll;
}
linklist FindAndRemove(linklist ll,u32 valuetoremove){
	if(ll->value==valuetoremove){
		node front = ll;
		ll=front->next;
		front->next=NULL;
		free(front);
		front = NULL;
		return ll;
	}
	node cursor=ll;
	node anterior;
	while(cursor!=NULL){
		if(cursor->value==valuetoremove){
			break;
		}
		anterior = cursor;
		cursor = cursor->next;
	}
	if(cursor!=NULL){
		anterior->next=cursor->next;
		free(cursor);
		cursor=NULL;
	}
	return ll;
}
u32 CountLL(linklist ll){
	u32 count =0;
	linklist cursor=ll;
	while(cursor!=NULL){
		count++;
		cursor=cursor->next;
	}
	return count;
}
linklist DestroyfirstElemnt(linklist ll){
	if(ll->next==NULL){
		free(ll);
		ll=NULL;
		return NULL;
	}
	linklist aux =NULL;
	aux = ll->next;
	ll->next=NULL;
	free(ll);
	ll=NULL;
	return aux;
}
