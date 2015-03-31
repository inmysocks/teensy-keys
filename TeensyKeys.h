// TeensyKeys
// Intended for use with a Teensy LC

// Our current testbed for keys has the following layout:
//	|1|2|3|	      |3|2|1|
//  |4|5|6|	      |6|5|4|
//      |7|8|   |8|7|
//

// The Teensy LC has 27 general IO pins for us to use, so there is
// no need for a I/O expander.


// In our previous iteration of this file we used the notation
// (left/middle/right) + (forward/middle/backward)
// since we had a slightly different layout. Now the notation could
// look like the following
// ([r]ing/[m]iddle/[i]ndex) + ([f]orward/[b]ack) 
// for the main digits, and ([t]humb) + ([l]eft/[r]ight)


// These will need to change depending on the specific pins used.
// Unlike on the EEKv3 there is a direct mapping of buttons to the
// microcontroller (no I/O expander). This simplifies some things.

// Defining left key buttons pins.
#define L1 2 	// Started at pin 2 because pin 0 and 1 are serial.
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 9

// Defining right key buttons pins.
#define R1 23	// Shouldn't have any conflicts. Mirrors left pins. 
#define R2 22
#define R3 21
#define R4 20
#define R5 19
#define R6 18
#define R7 17
#define R8 16

// Define pins for optional USB LEDs (two per side)
// Caps lock, num lock, scroll lock standard.
// We can also use these for debugging.
#define LLED1 10
#define LLED2 11
#define RLED1 15
#define RLED1 14

// Read the pins into an array, e.g. leftButtonsPressed
// with size 8. Shift each input left based on its position.
// leftButtonsPressed[0] is shifted by 0, leftButtonsPressed[1]
// is shifted by 1, and so on. Then by summing the array we can
// uniquely identify the different combinations of keys.

// For this, the array inputs follows the buttons layout displayed
// above. Key 1 = array[0], and so on.

// Thus if only key 1 on the left hand is pressed the unique number 
// to identify it is 1. If only key 2 is pressed, the number is 2.
// If only key 3 is pressed the number is 4. The numbers quickly rise
// by powers of 2.
// This also works with combinations. If key 1 and 3 are pressed then
// the id is 5.

//  8  7  6  5  4 3 2 1
// 128 64 32 16 8 4 2 1 // Add the numbers in this row to determine
						// the id for a combo.

// For the right hand we are shifting by 9 or more.
// 	8  		  7  	 6  	 5  	 4 		 3 		 2 	 1
// 32768	16284	8192	4096	2048	1024	512 256
// Since the majority of this is bitwise math it should be rather efficient.

#define nokey 0

// Left hand "natural" positions.
#define lrf 1
#define lmf 2
#define lif 4
#define lrb 8
#define lmb 16
#define lib 32
#define ltl 64
#define ltr 128

// Right hand "natural" positions.
#define rrf 256
#define rmf 512
#define rif 1024
#define rrb 2048
#define rmb 4096
#define rib 8192
#define rtl 16284
#define rtr 32768

// Begin letter combinations
// In order of frequency (roughly)
// Left hand has most of the vowels (like dvorak)
// and right hand has the common consonants (like dvorak)
// Why like dvorak? Because a.) its a nice idea, and 
// b.) right handed people can type it, so its probably ok
// for them too.
// Roles:
// Left hand: vowels, punctuation, uncommon consonants
// Right hand: common consonants, uncommon punctuation
// Both hands: numbers, uncommon punctuation
#define key_e lif
#define key_t rmf
#define key_a lrf
#define key_o lmf
#define key_i lib
#define key_n rrf
#define key_s rif
#define key_r rib
#define key_h rmb
#define key_l rrb
#define key_d lmb
#define key_c lif + lmf
#define key_u lrb
#define key_m
#define key_f
#define key_g
#define key_p
#define key_y
#define key_w
#define key_b
#define key_v
#define key_k
#define key_x
#define key_j
#define key_q
#define key_z

// Character frequencies
// SPC e t a o i n s r h l d c u m f g p y w ENT
// b , . v k - " _ ' x ) ( ; 0 j 1 q = 2 : z / *
// ! ? $ 3 5 > { } 4 9 [ ] 8 6 7 \ + | & < % @ #
// ^ ` ~

// Letter frequencies
// e t a o i n s r h l d c u m f g p y w b v k x j q z

// Punctuation frequencies
// , . - " _ ' ) ( ; = : / * ! ? $ > { } [ ] \ + | & < % @ # ^ ` ~