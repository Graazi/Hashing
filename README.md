# Hashing

Atividade Assíncronade Estruturas de Dados II-Hashing

Questão única: Crie um programa para implementar em arquivoo cadastro de produtos de uma loja. Cada registro do  arquivo  de produtosdeve  armazenar  os  seguintes  dados: código(chave  primária), descrição, preçoe quantidade  em  estoque. O  acesso  aos  registros  do  arquivo  será  feito  através de  uma  tabela  de  hashing que  será implementada  utilizando-se  um  arquivo  seqüencial  cujos  registros  terão  os  seguintes campos: códigodo produto, posiçãodo produtocom aquele código no arquivo de produtos, o statusdo registro (0 –livre, 1 –em uso) e  um campopróximoque será utilizado para implementar o encadeamento interno. O programa deverá ter as seguintes funcionalidades:

(1)Função de hashing. Recebe como parâmetro de entrada ocódigodo produto. O algoritmo de hashing a ser utilizado  é  o  “método  da permutaçãopara  chaves  alfanuméricas”.  A  função  irá  retornar  o  valor calculado.

(2)Função de busca. Procura por umdeterminadocódigo. Recebe como parâmetro de entrada o código do produto.    Aplica  a  função  de  hashing ao  código.  Vai  na  tabela  de  hashing  e  procura o  códigona  lista indicada  pelo  resultadodafunção  de  hashing.Caso  encontre o  códigona  tabela  de  hashing,  retorna  a posição do produtocom aquele código no arquivo de produtos. Caso não encontre, retorna -1.Estasetratade  uma  função  auxiliar  e  deverá  ser  utilizada  pelos  demais  procedimentos  que  necessitem  de  uma busca.

(3)Procedimento  cadastrarum  novo produto.  Solicita o  código  do  produtoa  ser  cadastrado. Como  não podem existir dois produtoscom o mesmo código, faz uma busca na tabela de hashing para verificar se aquele código já consta no cadastro.Caso o códigonão exista, procede com o cadastramento do produto; se existir, informa que o cadastramento não pode ser efetuado, pois o códigojá existe. O cadastramento de um novo produtoconsiste na inclusão do registro no arquivode produtoseda entrada correspondente na tabela de hashing;

(4)Procedimento  exibiros  dados  (descrição,  preço  e  quantidade  em  estoque)  de  um produto.  Solicita o código  do  produtoa  ser  pesquisado. Faz  uma  busca  na  tabela  de  hashing para  verificar  se  aquele  código consta  no  cadastro.  Em  caso  afirmativo, acessa  o  arquivo de produtosna  posição  indicada pela  tabela  de hashinge  procede  com  a  exibição dos  dados  do produto; caso  contrário, informa  que o  códigofornecidonão existe no cadastro;

(5)Procedimento alteraros dados (preço e/ouquantidade  em estoque) de  um produto. Solicita o código do produtoa  ser alterado. Faz  uma  busca  na  tabela  de  hashing para  verificar  se  aquele  código consta  no cadastro.Caso não conste, informa que o códigofornecidonão existe no cadastro;caso encontre, acessa o arquivo de produtosna  posição  indicada pela  tabela  de hashinge  procede  com  a  exibição dos  dados  do produto,  pergunta ao  usuário  qual  dado  ele  deseja  alterare  procede  com  a  alteração(lembre-se  que  os dados devem ser alterados no arquivo);

(6)Procedimento listar  arquivo. Exibe placa, modelo, marca, cor e donode todos os carroscadastrados. Os registros serão exibidos na ordem em que estão gravados no arquivo.

OBSERVAÇÕES:

(1)A chave primária do arquivode carrosé o campo “placa” que é do tipo string;

(2)A  função  de  hashing  a  ser  utilizada  é  a  que  implementa  o método  da permutação  parachaves alfanuméricasvisto em sala;

(3)Para resolver as colisões, utilizar encadeamento interno. 

(4)O Nutilizado deverá ser 101(número primo não próximo de uma potência de 2).

(5)No início da execução do programa, o arquivo da tabela de hashing deve ser criado e inicializado com 101(cento e um) registros, um para cada classe que será criada pela função de hashing. Esses 101registros irão compor a zona  de endereços  basee devem ser inicializados com “zero” no campo statuse -1 no campo próximo.

(6)O programador é livre para definir quaisquer outras funções que considere necessárias.
