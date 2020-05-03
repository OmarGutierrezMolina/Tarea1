/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: omarg
 *
 * Created on 2 de mayo de 2020, 21:34
 */

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void lectura();


int main()
{
  lectura();
  return 0;
}

void lectura(){
	
	ifstream file;
	ofstream ponderado;
  ponderado.open("ponderado.csv");
  string line;
  string rut;
  string puntero;
  int contadorpuntos = 0;
  int suma = 0;
  float pond = 0;
  //abrir archivo
  file.open("archivo.csv", ios::in);
  if(file.fail()){
  	cout<<"Archivo no encontrado"<<"\n";
  	exit(1);
  }
  //cout<<"Procesando \n";
  while(!file.eof()){ //condicion de final del archivo
  	getline(file,line);
  	for(int i=0;i<line.length();i++){
  		puntero = puntero + line[i];
  		if(line[i]==';'){
  			contadorpuntos++;
  			if(contadorpuntos==1){
  				rut=puntero.substr(0,puntero.length()-1);
  				//cout<<"Contador 1";
  				puntero = "";
			}
			else if (contadorpuntos==2){
				std::istringstream(puntero.substr(0,puntero.length()-1))>>suma;
				pond = pond + suma;
				//cout<<"Contador 2";
				puntero = "";
			}
			else if (contadorpuntos==3){
				std::istringstream(puntero.substr(0,puntero.length()-1))>>suma;
				pond = pond + suma;
				//cout<<"Contador 3";
				puntero = "";
			}
			else if (contadorpuntos==4){
				std::istringstream(puntero.substr(0,puntero.length()-1))>>suma;
				pond = pond + suma;
				//cout<<"Contador 4";
				puntero = "";
			}
			else if (contadorpuntos==5){
				std::istringstream(puntero.substr(0,puntero.length()-1))>>suma;
				pond = pond + suma;
				//cout<<"Contador 5";
				puntero="";
			}
			
	    }
	    //cout<<"Falta el ultimo digito";
	    if (i==line.length()-1){
	    		//cout<<"hola";
				std::istringstream(puntero.substr(0,puntero.length()-1))>>suma;
				pond = (pond + suma)/5;
				contadorpuntos=0;
				puntero = "";
				ponderado<<rut<<";"<<pond<<"\n";
				//cout<<rut<<";"<<pond<<"\n";
				rut="";
				suma=0;
				pond=0;	
				
		}
		
	}
  	
  }
  //cout<<"Terimando";
  ponderado.close();
  file.close();
}
