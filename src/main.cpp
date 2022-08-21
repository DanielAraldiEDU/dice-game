#include <iostream>
#include <time.h>
#include <locale.h>

void calculateProbabilityOfSides(int repetitions, int repeat, int counter[]);
void handleDoor(int &door, int chosenDoor, int comparateDoor);
void setVictoryValue(int &value, int comparateDoor, int winningDoor);
void readsPlayMode(int &mode);
void readsTheNumberRepetitions(int &repetitions);
void throwTheDiceOnce(int repetitions);
void throwTheDiceThreeTimes(int repetitions);

#define REPEAT 10000
#define THREE_TIMES 3

using namespace std;

void calculateProbabilityOfSides(int repetitions, int repeat, int counter[])
{
  for (int i = 0; i < repeat; i++)
  {
    float percentage = (float(counter[i]) / repetitions) * 100;
    cout << (i + 1) << " = " << percentage << "%" << endl;
  }
}

void handleDoor(int &door, int chosenDoor, int comparateDoor)
{
  do
  {
    door = rand() % 3 + 1;
  } while (door == chosenDoor || door == comparateDoor);
}

void setVictoryValue(int &value, int comparateDoor, int winningDoor)
{
  if (comparateDoor == winningDoor)
  {
    value++;
  }
}

void readsPlayMode(int &mode)
{
  while (mode < 1 || mode > 2)
  {
    cout << "Selecione um modo de jogo: \n(1) Modo de jogo um - Trocar de porta\n(2) Modo de jogo dois - Continuar com a porta" << endl;
    cin >> mode;
    if (mode < 1 || mode > 2)
    {
      cout << "Modo de jogo selecionado é inválido. Tente novamente." << endl;
    }
  }
}

void readsTheNumberRepetitions(int &repetitions)
{
  while (repetitions <= 0)
  {
    cout << "Quantos lançamentos você deseja fazer?" << endl;
    cin >> repetitions;

    if (repetitions <= 0)
    {
      cout << "A quantidade de lançamentos deve ser maior que zero!" << endl;
    }
  }
}

void throwTheDiceOnce(int repetitions)
{
  int counter[20] = {0};

  for (int i = 0; i < repetitions; i++)
  {
    int randomNumber = rand() % 20 + 1;

    counter[randomNumber - 1] += 1;
  }

  calculateProbabilityOfSides(repetitions, 20, counter);
}

void throwTheDiceThreeTimes(int repetitions)
{
  int counter[60] = {0};

  for (int i = 0; i < repetitions; i++)
  {
    int randomNumber = 0;
    for (int j = 0; j < THREE_TIMES; j++)
    {
      randomNumber += (rand() % 20) + 1;
    }

    counter[randomNumber - 1] += 1;
  }

  calculateProbabilityOfSides(repetitions, 60, counter);
}

int main()
{
  srand(time(NULL));
  setlocale(LC_ALL, "Portuguese");

  int option, tradedDoor, revealedDoor, chosenDoor, winningDoor, repetitions = 0, victorieByTradedDoor = 0, victorieByChosenDoor = 0, playMode = 0;

  cout << "Selecione uma das opções:\n(1) - Rolar um dado de 20 lados\n(2) - Rolar três dados de 20 lados\n(3) - Jogo do Monty Hall" << endl;
  cin >> option;

  switch (option)
  {
  case 1:
  {
    readsTheNumberRepetitions(repetitions);
    throwTheDiceOnce(repetitions);
    break;
  }
  case 2:
  {
    readsTheNumberRepetitions(repetitions);
    throwTheDiceThreeTimes(repetitions);
    break;
  }
  case 3:
  {
    readsPlayMode(playMode);

    for (int i = 0; i < REPEAT; i++)
    {
      chosenDoor = rand() % 3 + 1;
      winningDoor = rand() % 3 + 1;

      handleDoor(revealedDoor, chosenDoor, winningDoor);
      handleDoor(tradedDoor, chosenDoor, revealedDoor);

      switch (playMode)
      {
      case 1:
      {
        setVictoryValue(victorieByTradedDoor, tradedDoor, winningDoor);
        break;
      }
      case 2:
      {
        setVictoryValue(victorieByChosenDoor, chosenDoor, winningDoor);
        break;
      }
      default:
      {
        cout << "Erro ao escolher o tipo de jogada!";
        return 0;
      }
      }
    }

    cout << "De 10000 jogos, o número de vitórias através do modo de jogo *continuar com a primeira porta* foi igual a " << victorieByChosenDoor << ", enquanto o número de vitórias por *trocar a primeira porta* foi igual a " << victorieByTradedDoor;
    break;
  }
  default:
  {
    cout << "Opção inválida!";
    break;
  }
  }

  return 0;
}