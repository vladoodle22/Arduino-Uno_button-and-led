// Цифровой вход 2 присоединен к кнопке. Объявим переменную для этого пина:
int pushButton = 2;
int led = 4;
int laststate = 0;
int clikCount = 0;
// Настройка, выполняемая один раз при запуске программы:
void setup() {
  // Инициализируем последовательную передачу данных со скоростью 9600 бит в секунду:
  Serial.begin(9600);
  // Назначим пин 2 входом:
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}
// Основной цикл программы, выполняется повторно:
void loop() {
  // Читаем значение на входном пине:
  int buttonState = digitalRead(pushButton);
  // Выводим значение на монитор последовательного порта:
  if (buttonState != laststate) {
    Serial.print(buttonState?"кнопка нажата: ":"кнопка отжата\n");
    if (buttonState == 1) {
      clikCount++;
      Serial.println(clikCount);
      }
    digitalWrite(led, buttonState?HIGH:LOW);
    laststate = buttonState;
    // Задержка для стабильного считывания:
    delay(50);
    }
}  
