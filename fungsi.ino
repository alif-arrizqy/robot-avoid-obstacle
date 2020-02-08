void fungsi() {
  int distanceR = 0;
  int distanceL =  0;
  delay(40);
  if (distance <= 15)
  {
    Serial.print("Depan : ");
    Serial.println(distance);
    diam();
    delay(100);
    mundur();
    delay(300);
    diam();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);
    Serial.print("kanan : ");
    Serial.println(distanceR);
    Serial.print("kiri : ");
    Serial.println(distanceL);
    if (distanceR > distanceL)
    {
      Serial.println("Masuk kanan");
      kanan();
      diam();
    } else if (distanceL > distanceR) {
      Serial.println("Masuk kiri");
      kiri();
      diam();
    }
  } else {
    maju();
  }
  distance = readPing();
}
