import 'dart:ffi';
import 'dart:io';

import 'dart:math';



void main(){

  ///EN CASO DE NO TENER UN ARCHIVO CON PUNTAJES: PARA CREAR PUNTAJES DESCOMENTAR LA FUNCION crearPuntajes y Posteriormente volverla a comentar
  ///PARA PONDERAR PUNTAJES DESCOMENTAR LA FUNCION ponderarPuntajes
  File puntajes = new File("puntajes.csv");
  //crearPuntajes(puntajes);
  
  ponderarPuntajes(puntajes);
  
}

void crearPuntajes(File puntajes){
  print("Creando puntajes... este proceso podria tardar varios minutos");
  Random random = new Random();
  for (var i = 14000000; i <=15000000; i++) {
    int NEM = 475 + random.nextInt(276);
    int RKN = 475 + random.nextInt(276);
    int MAT = 475 + random.nextInt(276);
    int LEN = 475 + random.nextInt(276);
    int CIE = 475 + random.nextInt(276);
    puntajes.writeAsStringSync("${i};${NEM};${RKN};${MAT};${LEN};${CIE}\r\n", mode:APPEND);
  }
  print("Puntajes creados!!");
}

void ponderarPuntajes(File puntajes){
  puntajes.readAsLines().then(ponderar);
}

void ponderar(List<String> lines){
  Stopwatch stopwatch = new Stopwatch()..start();
  File ponderado = new File("ponderado.csv");
  String puntero ="";
  String rut;
  int contadorPuntos = 0;
  int suma=0;
  double pond;
  print("Procesando Puntajes");
  for(var line in lines){
    for(var i=0;i<line.length;i++){
      puntero = puntero + line[i];
      if(line[i]==";"){
        contadorPuntos++;
        if(contadorPuntos==1){
          rut=puntero.substring(0,puntero.length-1);
          puntero="";
        }
        if(contadorPuntos==2){
          suma = suma + int.parse(puntero.substring(0,puntero.length-1));
          puntero="";
        }
        if(contadorPuntos==3){
          suma = suma + int.parse(puntero.substring(0,puntero.length-1));
          puntero="";
        }
        if(contadorPuntos==4){
          suma = suma + int.parse(puntero.substring(0,puntero.length-1));
          puntero="";
        }
        if(contadorPuntos==5){
          suma = suma + int.parse(puntero.substring(0,puntero.length-1));
          puntero="";
        }
        
      }
      if(i==line.length-1){
        suma = suma + int.parse(puntero.substring(0,puntero.length-1));
        pond=suma/5;
        contadorPuntos=0;
        puntero="";
        ponderado.writeAsStringSync("${rut};${pond}\r\n", mode:APPEND);
        suma=0;
        pond=0;
      }
    }
  }
  print("Puntajes ponderados, proceso finalizado");
  print('Proceso terminado en: ${stopwatch.elapsed} segundos');
}