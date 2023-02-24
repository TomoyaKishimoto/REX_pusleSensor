int pulsePin = A0;    // パルスセンサの入力ピンをA0にする
int pulseVal;         // パルスセンサの値を格納する変数 

void setup() {
  Serial.begin(9600);      // シリアル通信の開始 
}

void loop() {
  pulseVal = analogRead(pulsePin); // パルスセンサの読み取り
  Serial.println(pulseVal);        // シリアルモニタに表示
  delay(100);                      // 100ms待機
}
