#include <iostream>
#include "mpp.hpp"

MPP::MPP(int sizeX, int sizeY) {
    // INGRESE AQUÍ EL CÓDIGO DE LA FUNCIONALIDAD
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    
    Nodo * temp = new Nodo(-1, 0 ,0);
    temp->setRight(temp);
    temp->setDown(temp);
    
    Nodo * temp2 = new Nodo(-1, 0 ,0);
	temp->setRight(temp);
    temp->setDown(temp);
    
    headX = temp;
    headY = temp2;
}

void MPP::add(int dato, int posX, int posY) {
    // INGRESE AQUÍ EL CÓDIGO DE LA FUNCIONALIDAD
    if(posX > sizeX || posY > sizeY){
    	return;
	}else{
		Nodo * nodo = new Nodo(dato, posX, posY);//Creamos nuevo nodo
    
		Nodo * aux = headX;
		
		while(aux->getRight()->getPosX() > posX && aux->getRight()->getPosX() > 0){
			//siempre que la posicion en X del right sea mayor que 0 y mayor que posX
			if(aux->getRight()->getPosX() == posX){//Revisa si ya se inserto en esa posicion
				//si ya hay un dato
				return;//No insertas
			}
			
			aux = aux->getRight();//Anda a revisar el right
		}
		//Una vez que encontraste la posicion de insertar en X
		nodo->setRight(aux);
		aux->setRight(nodo);
		
		//Ahora insertas para el Y
		
		Nodo * aux2 = headY;
		//Lo mismo
		while(aux2->getDown()->getPosY() > posY && aux2->getDown()->getPosY() > 0 ){
			//Siempre que la posicion en Y del que esta Down sea mayor que 0 y mayor que la posY
			if(aux2->getDown()->getPosY() == posY){
				return;
			}
			aux2 = aux2->getDown();//Busca en el que esta abajo
		}
		
		nodo->setDown(aux2->getDown());
		aux2->setDown(nodo);
		std::cout<<"Dato "<<dato<<" insertado."<<std::endl;
	}
}

int MPP::get(int posX, int posY) {
    // INGRESE AQUÍ EL CÓDIGO DE LA FUNCIONALIDAD
    if(posX > sizeX || posY > sizeY){
    	return 0;
	}else{
		Nodo * tempX = headX;
	    while(tempX->getRight()->getPosX() > posX){//Hasta que la posX en X sea menor que el nodo mas chikito 
	    	if(tempX->getRight() == headX){//Si ya recorriste toda la lista no esta
				return 0; //Termina esto
			}else{//Si aun no es el final
				if(tempX->getRight()->getPosX() == posX ){//Si el siguiente es la posicion
					tempX = tempX->getRight();//Setea el siguiente como temp
					break;//Deten el ciclo
				}
				//Si el siguiente no es nada 
				tempX = tempX->getRight();
			}
		}
		if(tempX->getPosX() != posX){//Si por alguna razon no encontro la posicion entonces retorna 0;
			return 0;
		}else{//Si es la pos en X; busca la pos en Y.
			Nodo * tempY = headY;
			while(tempY->getDown()->getPosY() > posY && tempY->getDown() == headY){
				//Siempre que no hayas llegadoa una posicion menor de posY, y no hhallas recorrido toda la lista
				
			}
			
		}
		Nodo * tempY = headY;
		while(tempY->getDown()->getPosY() < posY){
			
		}
		//std::cout<<"Dato en nodoX: "<<tempX->getData()<<std::endl;
		//std::cout<<"Dato en nodoX: "<<tempX->getData()<<std::endl;
		if(tempX == tempY){
			//std::cout<<"Este es return del dato no se si esta bien :c "<<std::endl;
			return tempX->getData();
		}	
	}
}
