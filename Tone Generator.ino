int speakerPin = 8;

int length = 15; 
char notes[] = "ccggaagffeeddc"; 
float beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };

int tempo = 250;

void playTone(int dtone, int duration) {
  for (long i = 0; i < duration * 1000L; i += dtone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(dtone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(dtone);
  }
}

void playNote(char note, int duration) {
   /*
    * timeHigh = 1 / (2 * Frequency)
    * note   frequency   timeHigh (micro second)
    * c       261 Hz      1915
    * d       294 Hz      1700
    * e       329 Hz      1519
    * f       349 Hz      1432
    * g       392 Hz      1275
    * a       440 Hz      1136
    * b       493 Hz      1014
    * C       523 Hz      956
    * D       587 Hz      851 
    * E       659 Hz      758
     */
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }
}
