int pulsePin = A0;    // パルスセンサの入力ピンをA0にする
int LEDPin = 13;      // LEDのピンを13番にする
int pulseVal;         // パルスセンサの値を格納する変数 
int threshold = 525;  // 心拍のしきい値、pulseValがこれより大きいとき心拍したとする

void setup() {
  pinMode(LEDPin, OUTPUT); // LEDPinを出力に設定する
  Serial.begin(9600);      // シリアル通信の開始 
}

void loop() {
  pulseVal = analogRead(pulsePin); // パルスセンサの読み取り
  Serial.println(pulseVal);        // シリアルモニタに表示

  if(pulseVal >= threshold){       // もしパルスセンサの値(pulseVal)がしきい値(threshold)より大きければ
    digitalWrite(LEDPin, HIGH);    // LEDをつける
  }
  else{                            // でなければ
    digitalWrite(LEDPin, LOW);     // LEDを消す
  }
  
  delay(100);                      // 100ms待機
}
