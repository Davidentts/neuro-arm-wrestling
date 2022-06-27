unsigned long sum_Usr1 = 0;
unsigned long sum_Usr2 = 0;

void MyPrint(unsigned long user1, unsigned long user2)
{
  Serial.print(user1);
  Serial.print(" ");
  Serial.print(user2);
  Serial.print(" ");
  Serial.print("\n");
}

void AddValue(int user1, int user2)
{
  sum_Usr1 += user1;
  sum_Usr2 += user2;
}

int get_mean1(int num_of_sec = 10, unsigned long interrupt = 100000, bool inclusive = true)
{
  if(inclusive)
    num_of_sec++;
  interrupt = 1000000 / interrupt;
  return sum_Usr1 / (interrupt * num_of_sec + 1);
}

int get_mean2(int num_of_sec = 10, unsigned long interrupt = 100000, bool inclusive = true)
{
  if(inclusive)
    num_of_sec++;
  interrupt = 1000000 / interrupt;
  return sum_Usr2 / (interrupt * num_of_sec + 1);
}