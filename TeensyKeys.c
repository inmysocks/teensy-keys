// Teensy LC Keys
// Very very rough, none tested on hardware nor complete
// in any sense of the word.

// Contains key definitions and other key info.
#include "TeensyKeys.h"
// Convenient debounce library.
#include "Bounce2.h"

// Array of our inputs, currently 8x per hand.
int leftButtons[8];
int rightButtons[8];

// Declare our Bounce objects.
Bounce LB1;
Bounce LB2;
Bounce LB3;
Bounce LB4;
Bounce LB5;
Bounce LB6;
Bounce LB7;
Bounce LB8;
Bounce RB1;
Bounce RB2;
Bounce RB3;
Bounce RB4;
Bounce RB5;
Bounce RB6;
Bounce RB7;
Bounce RB8;



void setup() {

	// Initialize our arrays to 0.
	for (int i = 0; i < 8; i++) {
		leftButtons[i] = 0;
		rightButtons[i] = 0;
	}

	// Activate pullups.
	// In the form pinMode(pin, INPUT_PULLUP)

}

// Look to www.pjrc.com/teensy/td_keyboard.html
// for ways to implement the keyboard functions. We 
// need to figure out which way we want to do it, since
// there are many options.

// E.g. We probably want to use the "Bounce" library,
// which takes care of debouncing for us very easily.

void loop() {
	

	
}

/*
 * Read the keys, then shift them each over to their respective
 * places. We can then sum the array to arrive at a unique key 
 * identifier.
 * See eekkeysv2.h for more information.
 */

 // TODO: Update this to use the Bounce Library!
void readKeys() {

	leftButtons[0] = digitalRead(L1);
	leftButtons[1] = digitalRead(L2);
	leftButtons[2] = digitalRead(L3);
	leftButtons[3] = digitalRead(L4);
	leftButtons[4] = digitalRead(L5);
	leftButtons[5] = digitalRead(L6);
	leftButtons[6] = digitalRead(L7);
	leftButtons[7] = digitalRead(L8);

	rightButtons[0] = digitalRead(R1);
	rightButtons[1] = digitalRead(R2);
	rightButtons[2] = digitalRead(R3);
	rightButtons[3] = digitalRead(R4);
	rightButtons[4] = digitalRead(R5);
	rightButtons[5] = digitalRead(R6);
	rightButtons[6] = digitalRead(R7);
	rightButtons[7] = digitalRead(R8);

	// shift them correctly
	for (int i = 1; i < 7; i++) {
		leftButtons[i] = leftButtons[i] << i;
		// Right side we shift to the next 8 bits.
		rightButtons[i] rightButtons[i] << i + 7; 
	}
}

int getKey() {
	// Sum arrays to get unique identifier.
	int leftPresses;
	int rightPresses;
	for (int i = 0; i < 7; i++) {
		leftPresses += leftButtons[i];
		rightPresses += rightButtons[i];
	}

	int keysPressed = leftPresses + rightPresses;

	switch (keysPressed) {

		case key_e:
			return 'e';
			break;
		case key_t:
			return 't';
			break;
		case key_a:
			return 'a';
			break;
		case key_o:
			return 'o';
			break;
		case key_i:
			return 'i';
			break;
		case key_n:
			return 'n';
			break;
		case key_s:
			return 's';
			break;
		case key_r:
			return 'r';
			break;

		default: break;

	}

}