  #include <TimerOne.h> 
  #include "data\Reading_Sensor.cpp"
  #include "data\Segment_Display.cpp"

  int SEC = 10; // количество секунд
  unsigned long timer;

  int dat1 = 0; //резуоттаты первого участника
  int dat2 = 0; //результаты второго учтастника

  const unsigned long interrupt = 100000; //промежуток прерыввния. НЕ БОЛЬШЕ ОДНОЙ СЕКУНДЫ (1000000)!
  

  void setup()
  {
    Serial.begin(9600);
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dp, OUTPUT);
    
    timer = millis();

    Timer1.initialize(interrupt);
    Timer1.attachInterrupt(TestTimer);
  }

void loop()
{
 if (millis() - timer > 1000 && SEC >= 0) {
      timer = millis();
      SEC = SEC - 1;
 }

  if(SEC >= 0)
  {
    Display(2, SEC / 10);
    Display(3, SEC % 10);
  }else{
    winner();
  }
}

void TestTimer()
{
  if(SEC >= 0)
    sendData();
}

void sendData() {
  dat1 = analogRead(A0);
  delay(1);
  dat2 = analogRead(A1);

  AddValue(dat1, dat2);
  //MyPrint(dat1, dat2); //для вывода отладочной информации
}

void winner()
{
  if(get_mean1(SEC, interrupt) > get_mean2(SEC, interrupt))
  {
    Display(1, 1, true);
    Display(2, 1, true);
    Display(3, 1, true);
    Display(4, 1, true);
  }else if(get_mean1(SEC, interrupt) < get_mean2(SEC, interrupt))
  {
    Display(1, 2, true);
    Display(2, 2, true);
    Display(3, 2, true);
    Display(4, 2, true);
  }else{
    Display(1, 11, true);
    Display(2, 11, true);
    Display(3, 11, true);
    Display(4, 11, true);
  }
  
}
