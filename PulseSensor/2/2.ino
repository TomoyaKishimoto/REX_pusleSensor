int pulsePin = A0;    // パルスセンサの入力ピンをA0にする
int LEDPin = 13;      // LEDのピンを13番にする
int pulseVal;         // パルスセンサの値を格納する変数 
int threshold = 525;  // 心拍のしきい値、pulseValがこれより大きいとき心拍したとする
long time;
long previousTime; //todo
long timeDiff;
long bpm;

void setup() {
  pinMode(LEDPin, OUTPUT); // LEDPinを出力に設定する
  Serial.begin(9600);      // シリアル通信の開始
  previousTime = millis(); // todo
}

void loop() {
  pulseVal = analogRead(pulsePin);   // パルスセンサの読み取り
  //Serial.println(pulseVal);        // シリアルモニタに表示
  
  if(pulseVal >= threshold){         // もしパルスセンサの値(pulseVal)がしきい値(threshold)より大きければ
    digitalWrite(LEDPin, HIGH);      // LEDをつける
    time = millis();                 // 現在の時間を計測
    timeDiff = time - previousTime;  // 前回の心拍からの経過時間を計算する
    bpm = (60000) / timeDiff;        // bpmの計算
    Serial.println("BPM");           // シリアルモニタに表示
    //Serial.println(timeDiff);
    Serial.println(bpm);
    previousTime = time;             // previousTimeの更新
  }
  else{                              // でなければ
    digitalWrite(LEDPin, LOW);       // LEDを消す
  }
  delay(100);
}
