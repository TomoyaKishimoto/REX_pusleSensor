int pulsePin = A0;    // パルスセンサーの入力ピンをA0にする
int LEDPin = 13;      // LEDのピンを13番にする
int pulseVal;         // パルスセンサーの値を格納する変数 
int threshold = 550;  // 心拍のしきい値、pulseValがこれより大きいとき心拍したとする

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulseVal = analogRead(pulsePin);
  Serial.println(pulseVal);

  if(pulseVal >= threshold){
    digitalWrite(LEDPin, HIGH);
  }
  else{
    digitalWrite(LEDPin, LOW);
  }
}
