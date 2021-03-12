//////////////
// showLED //
//////////////
// Show LED if a bumper is hit
void showLED() {
  if(pbRight == HIGH || pbLeft == HIGH) {
    digitalWrite(ledPin, HIGH); // LED on
  } else {
    digitalWrite(ledPin, LOW); // LED off
  }
}
