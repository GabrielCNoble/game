# game

Pra quem quiser baixar e modificar esse código, apenas um pedido: Divirta-se.

Todas as dependências estão neste repositório, e estão configuradas de forma relativa no projeto. Então ninguém
deve ter problemas na hora de compilar essa zona.

A arquitetura desse "jogo" não é uma obra de arte, e existem bugs gritantes nele. Um dos que mais chama atenção é na função get_player_input(), 
que provavelmente crasheará o jogo se o jogador não existir quando ela for chamada. De repente implementar suporte para múltiplos jogadores seja
uma boa. Ja ví jogos onde até quatro pessoas usam o mesmo teclado. Ficou meio bagunçado, mas funcionava. Quem tiver mais paciência pode usar a
parte de internet da SDL. Eu não tentei (ainda), mas deve ser de buenas.

Tentar iniciar o jogo sem criar uma câmera também dá problemas. Uma coisa que deve ser modificada é a função 
move_camera_to(), em camera.cpp, linha 57. Essa função está usando valores hard coded pra resolução da tela. Ela obviamente deve se adaptar a resolução
que se está usando.

Outras coisitas mais não foram implementadas...

Como detecção de colisão lateral com os blocos. Uma função dedicada a detecção de colisão poderia ser criada, 
deixando process_actors() livre pra implementar só a lógica dos atores. A velocidade da detecção de colisão poderia ser melhorada  se a função não checasse 
pares redundantes (como A vs B e B vs A). Um algorítmo melhor pra lidar com altas velocidades seria uma boa coisa. 

Eu comecei a implementar um sistema de som, mas percebi que isso fugia muito do escopo de programação gráfica, então isso fica pra quem tiver
paciência. Esse sistema está usando SDL_mixer.

Implementar suporte pra texturas é uma boa. SDL_image tem suporte pra texturas com canal alpha. Então da pra fazer umas coisas bem legais. O
workflow é bem simples (e eu não me lembro).

Pathfinding é algo legal de se implementar, e vai fazer com que os npcs pareçam mais inteligentes. Pra quem quiser implementar, procurem pelo
algoritmo A* (A-star ). Ele é relativamente simples. O problema é que ele usa grafos, mas eu imagino que C++ tenha suporte pra isso na biblioteca
padrão. Eu não sei.

Pra quem estava na aula (ou não), e conseguiu entender alguma coisa (ou não), faça bom uso, e qualquer dúvida, é so me mandar e-mail, ou whatsapp, 
ou telegram, ou carta, ou mensagem de fumaça, ou mensagem psíquica, etc etc.
