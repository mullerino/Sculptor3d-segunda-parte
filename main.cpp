#include <iostream>
#include <fstream>
#include <string>
#include "Voxel.h"
#include "scultor.h"
#include "interpretador.h"
#include <vector>
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
using namespace std;

int main()
{
    Scultor *sx;
    Interpretador anl;
    vector<FiguraGeometrica*> fig;

    fig = anl.anl("perry.02.txt"); // o container fig recebe o container que armazenou todos os processos que serão realizados

    sx = new Scultor(anl.getdimx(),anl.getdimy(),anl.getdimz());   // alocação de memória, recebendo as dimensões do desenho

    // cada processo recebe o método draw relacionado ao tipo de classe [putbox,putsphere...]
    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*sx);
    }

    sx->writeOFF((char*)"manoqt.off"); // criação do arquivo .off

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    delete sx;
}
    /*
   // Esfera e elipisoide
    Scultor EE(60,60,60);
    EE.setColor(1,0.54,0,1);
    EE.putSphere(40,40,40,10);

    EE.setColor(1,0.54,0,1);
    EE.putEllipsoid(20,20,20,15,10,7);
    EE.writeOFF((char*)"Esfera_Elipisóide.off");

    // Escultura final
    Scultor perry(50,50,50);

    // corpo
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(13,33,3,13,3,18);

    // cabeça
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(33,39,6,16,2,19);

    // bico
    perry.setColor(1,0.54,0,1);
    perry.putBox(39,44,8,10,4,17);

    // rabo
    perry.setColor(1,0.54,0,1);
    perry.putBox(0,13,10,13,7,14);

    //perna_1 frente
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(30,33,2,3,4,7);

    //pe_1 frente
    perry.setColor(1,0.54,0,1);
    perry.putBox(30,35,0,2,4,7);

   //perna_2 frente
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(30,33,2,3,14,17);

    //pe_2 frente
    perry.setColor(1,0.54,0,1);
    perry.putBox(30,35,0,2,14,17);

    //perna_3 tras
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(14,17,2,3,4,7);

    //pe_3 tras
    perry.setColor(1,0.54,0,1);
    perry.putBox(14,19,0,2,4,7);

    //perna_4 tras
    perry.setColor(0,0.5,0.5,1);
    perry.putBox(14,17,2,3,14,17);

    //pe_4 tras
    perry.setColor(1,0.54,0,1);
    perry.putBox(14,19,0,2,14,17);

    //chapeu base
    perry.setColor(0.54,0.27,0.1,1);
    perry.putBox(30,42,16,18,0,21);

    //chapeu preto
    perry.setColor(0,0,0,1);
    perry.putBox(33,39,18,20,3,18);

    //chapeu acima
    perry.setColor(0.54,0.27,0.1,1);
    perry.putBox(33,39,20,22,3,18);

    // olho direito completo
    perry.cutBox(37,39,10,13,2,6);
    perry.setColor(1,1,1,1);
    perry.putBox(37,39,10,13,2,6);
    perry.cutBox(38,39,10,12,2,4);
    perry.setColor(0,0,0,1);
    perry.putBox(38,39,10,12,2,4);

    // olho esquerdo completo
    perry.cutBox(37,39,10,13,15,19);
    perry.setColor(1,1,1,1);
    perry.putBox(37,39,10,13,15,19);
    perry.cutBox(38,39,10,12,17,19);
    perry.setColor(0,0,0,1);
    perry.putBox(38,39,10,12,17,19);

    //bico rosto
    perry.cutBox(38,39,10,12,6,15);
    perry.setColor(1,0.54,0,1);
    perry.putBox(38,39,10,12,6,15);

    perry.writeOFF((char*)"testeperryOornitorrinco.off");
    */

