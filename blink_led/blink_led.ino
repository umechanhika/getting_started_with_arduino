const int LED = 13; // LEDはデジタルピン13に接続

void setup() {
  pinMode(LED, OUTPUT); // デジタルピンを出力に設定
}

void loop() {
  digitalWrite(LED, HIGH); // LEDを付ける
  delay(1000); // 1秒待つ
  digitalWrite(LED, LOW); // LEDを消す
  delay(1000); // 1秒待つ
}