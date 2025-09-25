#include <iostream>
#include <string>
//funcion para consultar un producto
void consultarProducto(const int arr[],std::string arr2[],int arr3[],float arr4[], int tamano){
    int producto;
    std::cout<<"Ingresa el codigo del producto: ";
    std::cout<<std::endl;
    std::cin>>producto;

    //variable bandera
    bool existe = false;

    for (int i = 0; i < tamano; i++){
        //hasta que el codigo ingresado coincida con alguno dentro del array, se imprime la info
        if (arr[i]==producto){
            std::cout<<"--PRODUCTO CONSULTADO--"<<std::endl;
            std::cout<<"Codigo: "<<arr[i]<<std::endl;
            std::cout<<"Nombre: "<<arr2[i]<<std::endl;
            std::cout<<"Stock: "<<arr3[i]<<std::endl;
            std::cout<<"Precio: $"<<arr4[i]<<std::endl;
            std::cout<<std::endl;
            //valor bandera cambia a true
            existe=true;
            break;
        } 
    }
    //si se ingresa un codigo que no existe, y el valor de 'existe' sigue siendo false
    //se imprime el mensaje que el producto no se encontro
    if (!existe){
        std::cout<<"El producto no se encontro"<<std::endl;
    }
}
//funcion para actualizar el stock, se puede agregar o disminuir
void actualizarStock(const std::string arr[],int arr2[],int arr3[],int tamano){
    int escogido;
    //-1 para que no interfiera con el indice [0]
    int encontrado=-1;
    int operacion;
    int nuevoStock;
    int cantidad;

    std::cout<<"Ingresa el codigo del producto para actualizar"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cin>>escogido;
    //busca el codigo del producto en su array, si lo encuentra entonces le asigna el indice a la variable encontrado
    for (int i = 0; i < tamano; i++){
        if (arr3[i] == escogido){
            encontrado=i;
            break;
        }
    }
    
    if (encontrado!=-1){
        std::cout<<"Producto: "<<arr[encontrado]<<std::endl;
        std::cout<<"Stock actual: "<<arr2[encontrado]<<std::endl;
        std::cout<<std::endl;

        std::cout<<"1)Agregar, 2)Disminuir"<<std::endl;
        std::cin>>operacion;
        std::cout<<std::endl;

        switch (operacion){
        //sumar stock
        case 1:
        std::cout<<"Ingrese la cantidad a agregar"<<std::endl;
        std::cin>>cantidad;
        nuevoStock=arr2[encontrado]+cantidad;
        arr2[encontrado]=nuevoStock;

        std::cout<<"--STOCK ACTUALIZADO--"<<std::endl;
        std::cout<<"Producto: "<<arr[encontrado]<<std::endl;
        std::cout<<"Stock: "<<arr2[encontrado]<<std::endl;
        break;
        //restar stock
        case 2:
        std::cout<<"Ingrese la cantidad a disminuir"<<std::endl;
        std::cin>>cantidad;
        nuevoStock=arr2[encontrado]-cantidad;
        //si la cantidad da negativa, se queda en 0
        if(nuevoStock<0){
            nuevoStock=0;
            arr2[encontrado]=nuevoStock;
            std::cout<<"El stock ya esta en 0"<<std::endl;
        }else{
            arr2[encontrado]=nuevoStock;
        }

        std::cout<<"--STOCK ACTUALIZADO--"<<std::endl;
        std::cout<<"Producto: "<<arr[encontrado]<<std::endl;
        std::cout<<"Stock: "<<arr2[encontrado]<<std::endl;
        break;
        default:
        std::cout<<"Opcion no valida"<<std::endl;
        std::cout<<std::endl;
        break;
        }
    } else{
        std::cout<<"El codigo no existe"<<std::endl;
        std::cout<<std::endl;
    }
}
//funcion para generar el reporte del inventario
void generarReporte(const int arr[],std::string arr2[],int arr3[],float arr4[], int tamano){
    int elementosLlenos=5;
    std::cout<<"--REPORTE DE INVENTARIO--"<<std::endl;
    std::cout<<" --Codigo-- |    --Nombre--    | --Stock-- | --Precio--"<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    for (int i = 0; i < elementosLlenos; i++)
    {
        std::cout<<"     "<<arr[i]<<"     "<<arr2[i]<< std::left <<"               "<<arr3[i]<< std::left<<"      | $"<<arr4[i]<< std::left<<std::endl;
        std::cout<<std::endl;
    }
}
//funcion para encontrar al producto mas caro
void precioMayor(const float arr[],std::string arr2[], int tamano){
    int mayorProducto;
    int mayor = arr[0];
    for (int i = 0; i < tamano; i++){
            if (arr[i]>mayor){
                mayor=arr[i];
                mayorProducto=i;
            }
        }
    std::cout<<"--PRODUCTO MAS CARO--"<<std::endl;
    std::cout<<"El producto mas caro es: "<<arr2[mayorProducto] << ", con un precio de: $"<<arr[mayorProducto]<<std::endl;
    std::cout<<std::endl;
}

int main() {
    //arreglos paralelos
    int codigo[100]={101,102,103,104,105};
    std::string nombre[100]={"Martillo","Destornillador","Llave inglesa","Llave ajustable","Pinzas"};
    int stock[100]={20,33,16,55,22};
    float precio[100]={15.50f,20.75f,50.00f,26.50f,79.99f};
   
    int opcion;
    //variable del tamaño de arreglos
    int tamano=sizeof(codigo)/sizeof(codigo[0]);

    std::cout<<std::endl;
    std::cout<<"Sistema de Inventario de 'El Martillo'"<<std::endl;
    std::cout<<std::endl;
   
    //bucle para repetir el menu
    do {
        std::cout<<"--MENU--"<<std::endl;
        std::cout<<"Que opcion desea realizar?"<<std::endl;
        std::cout<<"1.Consultar productos"<<std::endl;
        std::cout<<"2.Actualizar inventario"<<std::endl;
        std::cout<<"3.Generar reporte"<<std::endl;
        std::cout<<"4.Buscar producto mas caro"<<std::endl;
        std::cout<<"5.Salir"<<std::endl;
        std::cout<<std::endl;
        std::cin>>opcion;

        if (std::cin.fail()){
            std::cout<<"Opcion no valida. Elija un numero del 1 al 5"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        //distintos casos dependiendo de la opcion escogida
        switch (opcion){
        case 1:
        //consultar productos
            consultarProducto(codigo,nombre,stock,precio,tamano);
        break;
        //actualizar producto
        case 2:
            actualizarStock(nombre,stock,codigo,tamano);
        break;
        //generar reporte
        case 3:
            generarReporte(codigo,nombre,stock,precio,tamano);
        break;
        //producto con mayor precio
        case 4:
            precioMayor(precio, nombre, tamano);
        break;
        //salir
        case 5:
            std::cout<<"Gracias por usar nuestro sistema de inventario. Saliendo."<<std::endl;
            return 0;
        break;
        default:
            std::cout<<"Opcion no valida. Elija un numero del 1 al 5"<<std::endl;
        }
    }while (true);
    
    return 0;
}