// Цифровой вход 2 присоединен к кнопке. Объявим переменную для этого пина:
int pushButton = 2;
int led = 4;
int lastledstate = 0;
int clikCount = 0;
int LastButtonState = 0;
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

    
    if (buttonState == 1 && LastButtonState == 0) {
      clikCount++;
      digitalWrite(led, lastledstate = !lastledstate);
      Serial.println(String(lastledstate?"led on: ":"led off: ") + "	clicks:" + clikCount);
      delay(50);
      }
    
    
    // Задержка для стабильного считывания:
    LastButtonState = buttonState;
    
}  
