#define USE_ARDUINO_INTERRUPTS true    // BPMの計算用の設定、おまじない
#include <PulseSensorPlayground.h>     // パルスセンサーのライブラリをインクルードする

int pulsePin = A0;    // パルスセンサの入力ピンをA0にする
int LEDPin = 13;      // LEDのピンを13番にする
int pulseVal;         // パルスセンサの値を格納する変数 
int threshold = 525;  // 心拍のしきい値、pulseValがこれより大きいとき心拍したとする

PulseSensorPlayground pulseSensor; // パルスセンサーの変数を用意 (パルスセンサーのインスタンス生成)
int myBPM;            // BPM(心拍数)を格納する変数

void setup() {
  pinMode(LEDPin, OUTPUT); // LEDPinを出力に設定する
  Serial.begin(9600); // シリアル通信の開始

  pulseSensor.analogInput(pulsePin);   // パルスセンサの入力ピンを設定
  pulseSensor.blinkOnPulse(LEDPin);    // LEDのピンを設定
  pulseSensor.setThreshold(threshold); // 心拍のしきい値を設定
  pulseSensor.begin();                 // 計測開始
}

void loop() {
  myBPM = pulseSensor.getBeatsPerMinute();  // PulseSensorPlaygroundライブラリ内のgetBeatsPerMinute()関数を呼び出し、BPMを計算しmyBPMに格納.
  if (pulseSensor.sawStartOfBeat()) {       // もし心拍が起きたならば
    Serial.print("BPM: ");                  // シリアルモニタに "BPM: " を表示
    Serial.println(myBPM);                  // シリアルモニタにmyBPMの中身を表示
  }

  delay(20);
}
