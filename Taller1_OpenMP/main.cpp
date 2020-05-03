#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <omp.h>

using namespace std;


int main(){
    std::string pyc(";");
    std::string rut;
    int prom;
    std::string salida;
    std::ofstream archivoSalida("promedios.csv");//Se crea archivo para guardar promedios
    std::ifstream archivoEntrada("puntajes.csv");//Se abre archivo para crear promedios
#pragma omp parallel 
    {
#pragma omp if
        if (archivoEntrada){
            std::string linea;
#pragma omp while

            while (getline(archivoEntrada,linea)){
                int inicio=0;
                int puntj;
                std::string rut;
                int suma=0;
                size_t pos = 0; //variable de tipo size_t tipo integral sin signo
                string token;
#pragma omp while
                while ((pos = linea.find(pyc)) != std::string::npos) { //npos es el valor máximo para size_t
                    token = linea.substr(0, pos); //Guarda primer valor del string hasta encontrar el puntoycoma
#pragma omp if
                    if (inicio==0){
                        rut=token;
                    }
#pragma omp if
                    if (inicio!=0){
                        std::istringstream(token)>>puntj;
                        suma = suma + puntj;
                        }
                    inicio+=1;
                    linea.erase(0, pos + pyc.length()); //Borra ese valor encontrado
                }
                std::istringstream(linea)>>puntj;
                suma = suma + puntj;
                int promedio = (suma / 6);
                salida= rut + pyc + std:: to_string(promedio);
#pragma omp critical
                archivoSalida << salida << std::endl; 
            }
        }
    }
    archivoEntrada.close();
    archivoSalida.close();
    return EXIT_SUCCESS;
}