#include <Adafruit_NeoMatrix.h>

#define WIDTH 8
#define HEIGHT 8
#define PIN 3

//initialize instance of Neomatrix object
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(WIDTH, HEIGHT, PIN,
                            NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

//colors array
const uint16_t colors[] = {
  matrix.Color(255, 0, 0),  //red
  matrix.Color(0, 255, 0),  //green
  matrix.Color(0, 0, 255)   //blue
};

//length of frame
int refresh_delay = 400;

int x = 0;
int y = 0;

//analog pins for sensor
int x_pin = A1;
int y_pin = A0;


void setup() {
  matrix.begin();
  Serial.begin(9600);
}

void loop() {
  //read pins
  int vert = analogRead(y_pin);
  int horiz = analogRead(x_pin);

  //update position
  if (vert < 400) {
    y++;
  } else if (vert > 600) {
    y--;
  } else if (horiz < 400) {
    x++;
  } else if (horiz > 600) {
    x--;
  }

  //update display
  matrix.fillScreen(0);
  matrix.drawPixel(x, y, colors[0]);
  matrix.show();

  //show data
  Serial.print("(");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(") x: ");
  Serial.print(horiz);
  Serial.print(" y: ");
  Serial.println(vert);
  delay(refresh_delay);
}
