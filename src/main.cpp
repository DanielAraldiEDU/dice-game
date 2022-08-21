#include <iostream>
#include <time.h>

void calculateProbabilityOfSides(int repetitions, int repeat, int counter[]);
void readsTheNumberRepetitions(int &repetitions);
void throwTheDiceOnce(int repetitions);
void throwTheDiceThreeTimes(int repetitions);

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

  int option, repetitions = 0;

  cout << "Selecione uma das opções:\n(1) - Rolar um dado de 20 lados\n(2) - Rolar três dados de 20 lados" << endl;
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
  default:
  {
    cout << "Opção inválida!";
    break;
  }
  }

  return 0;
}