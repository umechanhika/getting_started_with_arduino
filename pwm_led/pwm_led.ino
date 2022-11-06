// ボタンを押すとLEDが点灯し
// ボタンから指を離した後も点灯し続ける。
// バウンシングを解消する簡単な方法を取り入れる。
// ボタンを押したままにすると明るさが変化する。

const int LED = 9; // LEDが接続されたピン
const int BUTTON = 7;

int val = 0;
int old_val = 0;
int state = 0;

int brightness = 128; // 明るさの値を保存する
unsigned long startTime = 0; // いつ押し始めたか？

void setup() {
  pinMode(LED, OUTPUT); // LEDのピンの出力に設定
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);

  // 変化があるかどうかチェック
  if (val == HIGH && old_val == LOW) {
    state = 1 - state;
    startTime = millis();
    delay(10);
  }

  // ボタンが押し続けられているかチェック
  if (val == HIGH && old_val == HIGH) {
    // 500ms以上押されているか？
    if (state == 1 && millis() - startTime > 500) {
      brightness++;
      delay(10);
      if (brightness > 255) {
        brightness = 0;
      }
    }
  }

  old_val = val;

  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
}
