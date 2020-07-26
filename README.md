# Coin
### Criptomoeda

O objetivo deste projeto, em princípio, é ser semelhante a um criptomoeda. Consistindo em implementar, na Linguagem C padrão ANSI, o necessário para viabilizar as transações.

## Como Funciona na Bitcoin?

Endereço: Uma string com caracteres alfanuméricos usada como identificador para o envio de um pagamento em bitcoins (exemplo: 14rruWSPHSCCNzCGyCqreAVp1rfyCZKt9B). 

Carteira: Software comumente usado por usuários Bitcoin para criar e listar um ou mais endereços de recebimento sob o controle de uma ou mais chaves privadas pertencentes ao usuário, e criar, assinar e transmitir transações para a rede. Elas existem na forma de aplicativos web, desktop, mobile e em hardwares dedicados.

Transação Bitcoin: A transação nada mais é do que uma estrutura de dados que representa a transferência de um certo valor.

## Como Funciona na Coin?

O projeto é formado por 3 partes: uma lista de carteiras, uma fila de mineração e uma árvore de blocos. Nas carteiras é salvo a chave pública, a chave privada e o saldo (em Coins) de um usuário. Na fila de mineração, cada transação realizada pelo usuário é registrada em um bloco, onde ficam salvos: a chave pública do destinatário e do remetente, a hora cujo bloco foi criado e minerado e uma assinatura do bloco que foi minerado. Após minerado, cada bloco segue para a Blockchain, armazenando na árvore onde fica registrado os blocos, como se fosse um livro razão.

O ciclo de uma transação começa com a criação de uma carteira. É a partir dela que se é possível realizar transferências de coins. Assim, o remetente informa a chave pública do destinatário, que é sua identidade. Encontrado o dono da chave pública, o remetente informa o valor a ser transferido e a chave privada, que serve como senha para maior segurança. A transação é registrada em um bloco e entra numa fila de mineração. Após ser minerado, o bloco segue para a Blockchain, estruturada na árvore.

## Para compilar, na pasta Coin, digite no terminal:

```bash
gcc *.c -o coin
```
Em seguida,

```bash
./coin
```