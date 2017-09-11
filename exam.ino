// Author: Batuto
// GitHub: github.com/batuto
// This code was designed using an Arduino Uno as reference, but may work in other devices,
// take this in mind when porting to another device.


int i, j, y, z;  // Variables defined for iteration
int list[][7] = {{0,1,2,3,4,5,5},  // 0
                 {2,3,3,3,3,3,3},  // 1
                 {0,1,3,4,6,6,6},  // 2
                 {1,2,3,4,6,6,6},  // 3
                 {2,3,5,6,6,6,6},  // 4
                 {1,2,4,5,6,6,6},  // 5
                 {0,1,2,4,5,6,6},  // 6
                 {2,3,4,4,4,4,4},  // 7
                 {0,1,2,3,4,5,6},  // 8
                 {2,3,4,5,6,6,6},  // 9
                 {0,2,3,4,5,6,6},  // A
                 {0,1,2,5,6,6,6},  // B
                 {0,1,4,5,5,5,5},  // C
                 {0,1,2,3,6,6,6},  // D
                 {0,1,4,5,6,6,6},  // E
                 {0,4,5,6,6,6,6}};  // F
/*
The previous matrix is defined to use a
 seven display numerating each segment
 in the next manner:
     4
 ========
||      ||
||5     ||3
||      ||
6========
||      ||
||0     ||2
||      ||
 ========
    1
*/


void setup(){
  for(i = 0; i < 14; i++){  // Set up the PORTD as OUTPUT
    pinMode(i, OUTPUT);    // The port D is conformed by the
  }                        // first 14 pins
    pinMode(14, INPUT);    // The pin number 14 is setted as input
}

void reset(){
  y = 0;
  z = 0;
  i = 0;
  j = 0;
for(i = 0; i < 14; i++)
  digitalWrite(i, LOW);
 asm volatile ("  jmp 0");
}

void exam(){
  for(y = 0; y < 16; y++){  // This is to iterate
          for(z = 0; z < 7; z++)
            digitalWrite(list[y][z] + 7, HIGH);
    for(i = 0; i < 16; i++){
      for(j = 0; j < 7; j++)
        digitalWrite(list[i][j], HIGH);
        if(digitalRead(14) == 1){
        reset();
        break;  // Maybe this break is unnecesary.
      }
      delay(300);
      for(j = 0; j < 7; j++)
        digitalWrite(j, LOW);
    }
    for(z = 0; z < 7; z++)
        digitalWrite(list[y][z] + 7, LOW);
  }
}

void loop(){

exam();
}
