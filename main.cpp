#include <iostream>
#include <string>

int main() {
    //arreglos paralelos
    int codigo[100]={101,102,103,104,105};
    std::string nombre[100]={"Martillo","Destornillador","Llave inglesa","Llave ajustable","Pinzas"};
    int stock[100]={20,33,16,55,22};
    float precio[100]={15.50,20.75,50.00,26.50,79.99};
    //variable para menu
    int opcion;
    //variable para guardar el producto que se desea consultar
    int producto;
    
    std::cout<<"Sistema de Inventario de 'El Martillo'"<<std::endl;
   

    //bucle para repetir el menu
    do {
        std::cout<<"MENU"<<std::endl;
        std::cout<<"Que opcion desea realizar?"<<std::endl;
        std::cout<<"1.Consultar productos"<<std::endl;
        std::cout<<"2.Actualizar inventario"<<std::endl;
        std::cout<<"3.Generar reporte"<<std::endl;
        std::cout<<"4.Buscar producto mas caro"<<std::endl;
        std::cout<<"5.Salir"<<std::endl;
        std::cin>>opcion;

        //distintos casos dependiendo de la opcion escogida
        switch (opcion){
        case 1:
        //consultar productos
            std::cout<<"Ingresa el codigo del producto: "<<std::endl;
            std::cin>>producto;

            {
            //variable bandera
            bool existe = false;


            for (int i = 0; i < 5; i++){
                if (codigo[i]==producto){
                    std::cout<<"Codigo: "<<codigo[i]<<std::endl;
                    std::cout<<"Nombre: "<<nombre[i]<<std::endl;
                    std::cout<<"Stock: "<<stock[i]<<std::endl;
                    std::cout<<"Precio: "<<precio[i]<<std::endl;
                    //valor bandera cambia a true
                    existe=true;
                    break;
                } 
            }
            //si se ingresa un codigo que no existe, y el valor de 'existe' sigue siendo false
            //se imprime el mensaje que no se encontro
            if (!existe){
                std::cout<<"El producto no se encontro"<<std::endl;
            }
        }
        break;

        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
            return 0;
        break;
        default:
            std::cout<<"Opcion no valida"<<std::endl;
        }
    }while (true);
    
    return 0;
}