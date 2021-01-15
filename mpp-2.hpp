#ifndef MPP_H
#define MPP_H

class Nodo {
    private:
        int valor, posX, posY;
        Nodo* right; Nodo* down;
    public:
        Nodo (int valor, int posX, int posY) { 
            this->valor = valor; this->posX = posX; this->posY = posY;
            this->valor = valor; this->right = this->down = this; 
        }
        
        void setData (int dato) { this->valor = dato; }
        void setPosX (int pos)  { this->posX = pos; }
        void setPosY (int pos)  { this->posY = pos; }

        int getData () { return this->valor; }
        int getPosX () { return this->posX; }
        int getPosY () { return this->posY; }

        void  setRight (Nodo* nodo) { this->right = nodo; }
        Nodo* getRight ()           { return this->right; }

        void  setDown (Nodo* nodo) { this->down = nodo; }
        Nodo* getDown ()           { return this->down; }    
};

class MPP {
    private: 
        // Solo para usarse con implementación estática
        int** matriz; int sizeX; int sizeY;

        // Solo para usarse con implementación dinámica
        Nodo* headX; Nodo* headY;

        public:
            MPP(int sizeX, int sizeY);

            void add(int dato, int posX, int posY);

            int get(int posX, int posY);
};

#endif /* MPP_H */