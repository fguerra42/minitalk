# Projeto Minitalk

## Capítulo I
### Prefácio

O cis-3-Hexen-1-ol, também conhecido como (Z)-3-hexen-1-ol e álcool de folhas, é um líquido oleoso incolor com um intenso odor verde-grassy de grama e folhas recém-cortadas. É produzido em pequenas quantidades pela maioria das plantas e age como um atrativo para muitos insetos predadores. O cis-3-Hexen-1-ol é um composto aromático muito importante que é utilizado em sabores de frutas e vegetais e em perfumes. A produção anual é de cerca de 30 toneladas.

## Capítulo II
### Instruções Comuns

- Seu projeto deve ser escrito em C.
- Seu projeto deve estar em conformidade com a Norm. Se você tiver arquivos ou funções bônus, eles serão incluídos na verificação da norma e você receberá 0 se houver um erro de norma.
- Suas funções não devem encerrar inesperadamente (falha de segmentação, erro de barramento, double free, etc.), além de comportamentos indefinidos. Se isso acontecer, seu projeto será considerado não funcional e receberá 0 durante a avaliação.
- Toda memória alocada no heap deve ser devidamente liberada quando necessário. Vazamentos não serão tolerados.
- Se o assunto exigir, você deve enviar um Makefile que compile seus arquivos fonte para a saída requerida com as flags -Wall, -Wextra e -Werror, use cc, e seu Makefile não deve relinkar.
- Seu Makefile deve conter pelo menos as regras $(NAME), all, clean, fclean e re.
- Para entregar bônus para o seu projeto, você deve incluir uma regra bonus no seu Makefile, que adicionará todos os vários cabeçalhos, bibliotecas ou funções que são proibidos na parte principal do projeto. Os bônus devem estar em um arquivo separado _bonus.{c/h} se o assunto não especificar outra coisa. A avaliação da parte obrigatória e do bônus é feita separadamente.
- Se o seu projeto permitir o uso da sua libft, você deve copiar seus fontes e seu Makefile associado em uma pasta libft com seu Makefile associado. O Makefile do seu projeto deve compilar a biblioteca usando seu Makefile e, em seguida, compilar o projeto.
- Incentivamos você a criar programas de teste para o seu projeto, mesmo que este trabalho não precise ser enviado e não será avaliado. Isso lhe dará uma chance de testar seu trabalho e o trabalho dos seus colegas facilmente. Esses testes serão especialmente úteis durante a defesa. De fato, durante a defesa, você pode usar seus testes e/ou os testes do colega que está avaliando.

- Submeta seu trabalho ao repositório Git atribuído. Apenas o trabalho no repositório Git será avaliado. Se a Deepthought for designada para avaliar seu trabalho, isso será feito após suas avaliações de pares. Se ocorrer um erro em qualquer seção do seu trabalho durante a avaliação da Deepthought, a avaliação será interrompida.

## Capítulo III
### Instruções do Projeto

- Nomeie seus arquivos executáveis como `client` e `server`.
- Você deve entregar um Makefile que compile seus arquivos fonte. Ele não deve relinkar.
- Você pode usar sua libft.
- Você deve tratar erros de forma minuciosa. De forma alguma seu programa deve terminar inesperadamente (falha de segmentação, erro de barramento, double free, etc.).
- Seu programa não deve ter vazamentos de memória.
- Você pode ter uma variável global por programa (uma para o cliente e uma para o servidor), mas você terá que justificar seu uso.
- Para completar a parte obrigatória, você está autorizado a usar as seguintes funções:
  - `write`
  - `ft_printf` e qualquer equivalente QUE VOCÊ codificou
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`

## Capítulo IV
### Parte Obrigatória

Você deve criar um programa de comunicação na forma de um cliente e um servidor.

- O servidor deve ser iniciado primeiro. Após seu lançamento, ele deve imprimir seu PID.
- O cliente deve receber dois parâmetros:
  - O PID do servidor.
  - A string a ser enviada.
- O cliente deve enviar a string passada como parâmetro para o servidor.
- Uma vez que a string tenha sido recebida, o servidor deve imprimi-la.
- O servidor deve exibir a string rapidamente. Rapidamente significa que se você acha que está demorando muito, então provavelmente está demorando demais. 1 segundo para exibir 100 caracteres é tempo demais!
- Seu servidor deve ser capaz de receber strings de vários clientes em sequência sem precisar reiniciar.
- A comunicação entre seu cliente e servidor deve ser feita apenas usando sinais UNIX.
- Você só pode usar esses dois sinais: `SIGUSR1` e `SIGUSR2`.
