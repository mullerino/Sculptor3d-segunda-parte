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

    sx->writeOFF((char*)"perrypart02.off"); // criação do arquivo .off

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    delete sx;
}
