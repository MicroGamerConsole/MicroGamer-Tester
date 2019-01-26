#include <MicroGamer.h>
#include "MicroGamerTones.h"

MicroGamer mg;

MicroGamerTones audio(mg.audio.enabled);

void setup() {
  mg.boot();
  mg.clear();
}

enum step_kind {SCREEN, PRESS_X, PRESS_Y, PRESS_UP, 
  PRESS_DOWN, PRESS_RIGHT, PRESS_LEFT, SOUND,
  END};

enum step_kind step = SCREEN;

const uint16_t titleTones[] = {NOTE_B4,   150,
                               NOTE_REST, 150,
                               NOTE_B4,   150, 
                               NOTE_REST, 150,
                               NOTE_C5,   150, 
                               NOTE_REST, 150,
                               NOTE_B4,   150, 
                               NOTE_REST, 30,
                               NOTE_E5,   150, 
                               NOTE_REST, 150,
                               NOTE_B4,   150, 
                               NOTE_C5,   150, 
                               NOTE_B4,   150, 
                               NOTE_C5,   150, 


                               NOTE_A4,   150,
                               NOTE_REST, 150,
                               NOTE_A4,   150, 
                               NOTE_REST, 150,
                               NOTE_B4,   150, 
                               NOTE_REST, 150,
                               NOTE_A4,   150, 
                               NOTE_REST, 30,
                               NOTE_D4,   150, 
                               NOTE_REST, 150,
                               NOTE_A4,   150, 
                               NOTE_B4,   150, 
                               NOTE_A4,   150, 
                               NOTE_B4,   150, 
                               TONES_REPEAT};

void loop() {
  
  mg.clear();
  
  mg.setCursor(0, 0);

  switch (step) {
    case SCREEN:
      mg.fillScreen(WHITE);
      break;
    case PRESS_X:
      mg.println("Press X");
      break;
    case PRESS_Y:
      mg.println("Press Y");
      break;
    case PRESS_UP:
      mg.println("Press UP");
      break;
    case PRESS_DOWN:
      mg.println("Press DOWN");
      break;
    case PRESS_RIGHT:
      mg.println("Press RIGHT");
      break;
    case PRESS_LEFT:
      mg.println("Press LEFT");
      break;
    case END:
      mg.println("If you hear a sound");
      mg.println("The MicroGamer is OK");
      break;
  }

  mg.display();

  switch (step) {
   case SCREEN:
      while (mg.buttonsState() == 0) {
        void();
      }
       
     step = PRESS_X;
     break;
   case PRESS_X:
      while (!mg.pressed(X_BUTTON)) {
        void();
      }
       
     step = PRESS_Y;
     break;
    case PRESS_Y:
      while (!mg.pressed(Y_BUTTON)) {
        void();
      }
     step = PRESS_UP;
     break;
    case PRESS_UP:
      while (!mg.pressed(UP_BUTTON)) {
        void();
      }
      step = PRESS_DOWN;
      break;
    case PRESS_DOWN:
      while (!mg.pressed(DOWN_BUTTON)) {
        void();
      }
      step = PRESS_RIGHT;
      break;
    case PRESS_RIGHT:
      while (!mg.pressed(RIGHT_BUTTON)) {
        void();
      }
     step = PRESS_LEFT;
     break;
    case PRESS_LEFT:
      while (!mg.pressed(LEFT_BUTTON)) {
        void();
      }
      step = SOUND;
      break;
    case SOUND:
      audio.tones(titleTones);
      step = END;
      break;
    case END:
    while (1) {
      void();
    }
    break;
  }
}

