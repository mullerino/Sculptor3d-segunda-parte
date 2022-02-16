# Sculptor3d - Segunda parte

O projeto deve ser capaz de tratar classes abstratas para manipulação de figuras geométricas simples, realizando operações de desenho em uma matriz de pontos.

Para isso, a estrutura criada para a classe Sculptor deverá ser repensada e uma nova classe chamada FiguraGeometrica entrará como participante do processo de desenho.

Não serão criados objetos dessa nova classe, mas ela agora será a base para várias outras classes concretas, que proverão funcionalidades semelhantes àquelas providas pela classe Sculptor do projeto anterior.

# Instruções de uso e compilação

Inicialmente, o usuário deve criar um arquivo .txt que vai conter os processos necessários para criar seu desenho 3d, 

Ex:
dim 30 30 20 

putvoxel 3 4 5 1.0 1.0 0.0 0.5

...

O nome do arquivo que contém esses processos deve ser fornecido no código main na linha 25. 

Além disso, o usário deve fornecer o nome do arquivo .off que será gerado na linha 34.

Após a compilação, o arquivo com o nome escolhido será gerado, ele deve ser executado no software Meshlab, caso você utilize linux use o Geomview.

