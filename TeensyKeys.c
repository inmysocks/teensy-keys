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

	pinMode(L1, INPUT_PULLUP);
	pinMode(L2, INPUT_PULLUP);
	pinMode(L3, INPUT_PULLUP);
	pinMode(L4, INPUT_PULLUP);
	pinMode(L5, INPUT_PULLUP);
	pinMode(L6, INPUT_PULLUP);
	pinMode(L7, INPUT_PULLUP);
	pinMode(L8, INPUT_PULLUP);
	pinMode(R1, INPUT_PULLUP);
	pinMode(R2, INPUT_PULLUP);
	pinMode(R3, INPUT_PULLUP);
	pinMode(R4, INPUT_PULLUP);
	pinMode(R5, INPUT_PULLUP);
	pinMode(R6, INPUT_PULLUP);
	pinMode(R7, INPUT_PULLUP);
	pinMode(R8, INPUT_PULLUP);
	delay(10);  // Allow the pullups to be set without
				// worrying about catching it halfway.

	// Assign buttons to the Bounce items.
	// Only doing the left side for now until we test it.
	LB1.attach(L1); // Attach pin to Bounce.
	LB1.interval(5); // Sets debounce to 5ms.
	LB2.attach(L2);
	LB2.interval(5);
	LB3.attach(L3); 
	LB3.interval(5);
	LB4.attach(L4); 
	LB4.interval(5); 
	LB5.attach(L5); 
	LB5.interval(5); 
	LB6.attach(L6);
	LB6.interval(5); 
	LB7.attach(L7); 
	LB7.interval(5);
	LB8.attach(L8); 
	LB8.interval(5); 
}

// Look to www.pjrc.com/teensy/td_keyboard.html
// for ways to implement the keyboard functions. We 
// need to figure out which way we want to do it, since
// there are many options.

// E.g. We probably want to use the "Bounce" library,
// which takes care of debouncing for us very easily.

void loop() {
	
	updateKeys();
	readKeys();

	// Doing it simply for now, just using Keyboard.print
	// In future we likely want to modify the packets 
	// manually.
	Keyboard.print(getKey());
}


// Only left keys for now until we test.
void updateKeys() {

	LB1.update();
	LB2.update();
	LB3.update();
	LB4.update();
	LB5.update();
	LB6.update();
	LB7.update();
	LB8.update();
}

// Only left for now until we test.
void readKeys() {

	leftButtons[0] = LB1.read();
	leftButtons[1] = LB2.read();
	leftButtons[2] = LB3.read();
	leftButtons[3] = LB4.read();
	leftButtons[4] = LB5.read();
	leftButtons[5] = LB6.read();
	leftButtons[6] = LB7.read();
	leftButtons[7] = LB8.read();

	// shift them correctly
	for (int i = 1; i < 7; i++) {
		leftButtons[i] = leftButtons[i] << i;
	}
}

}


/*
 * Read the keys, then shift them each over to their respective
 * places. We can then sum the array to arrive at a unique key 
 * identifier.
 * See TeesnyKeys.h for more information.
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

*/

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