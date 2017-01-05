# game

Pra quem quiser baixar e modificar esse c�digo, apenas um pedido: Divirta-se.

Todas as depend�ncias est�o neste reposit�rio, e est�o configuradas de forma relativa no projeto. Ent�o ningu�m
deve ter problemas na hora de compilar essa zona.

A arquitetura desse "jogo" n�o � uma obra de arte, e existem bugs gritantes nele. Um dos que mais chama aten��o � na fun��o get_player_input(), 
que provavelmente crashear� o jogo se o jogador n�o existir quando ela for chamada. De repente implementar suporte para m�ltiplos jogadores seja
uma boa. Ja v� jogos onde at� quatro pessoas usam o mesmo teclado. Ficou meio bagun�ado, mas funcionava. Quem tiver mais paci�ncia pode usar a
parte de internet da SDL. Eu n�o tentei (ainda), mas deve ser de buenas.

Tentar iniciar o jogo sem criar uma c�mera tamb�m d� problemas. Uma coisa que deve ser modificada � a fun��o 
move_camera_to(), em camera.cpp, linha 57. Essa fun��o est� usando valores hard coded pra resolu��o da tela. Ela obviamente deve se adaptar a resolu��o
que se est� usando.

Outras coisitas mais n�o foram implementadas...

Como detec��o de colis�o lateral com os blocos. Uma fun��o dedicada a detec��o de colis�o poderia ser criada, 
deixando process_actors() livre pra implementar s� a l�gica dos atores. A velocidade da detec��o de colis�o poderia ser melhorada  se a fun��o n�o checasse 
pares redundantes (como A vs B e B vs A). Um algor�tmo melhor pra lidar com altas velocidades seria uma boa coisa. 

Eu comecei a implementar um sistema de som, mas percebi que isso fugia muito do escopo de programa��o gr�fica, ent�o isso fica pra quem tiver
paci�ncia. Esse sistema est� usando SDL_mixer.

Implementar suporte pra texturas � uma boa. SDL_image tem suporte pra texturas com canal alpha. Ent�o da pra fazer umas coisas bem legais. O
workflow � bem simples (e eu n�o me lembro).

Pathfinding � algo legal de se implementar, e vai fazer com que os npcs pare�am mais inteligentes. Pra quem quiser implementar, procurem pelo
algoritmo A* (A-star ). Ele � relativamente simples. O problema � que ele usa grafos, mas eu imagino que C++ tenha suporte pra isso na biblioteca
padr�o. Eu n�o sei.

Pra quem estava na aula (ou n�o), e conseguiu entender alguma coisa (ou n�o), fa�a bom uso, e qualquer d�vida, � so me mandar e-mail, ou whatsapp, 
ou telegram, ou carta, ou mensagem de fuma�a, ou mensagem ps�quica, etc etc.
