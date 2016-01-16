/*
 * Program1.c
 *
 * Programming assignment 1 for C for Java Fall 2012
 * Reads in a value for the number of desired rings
 * and a desired core size, and outputs them as
 * ASCII art.
 *
 * Written by Alicia Mitchell - September 11, 2012
 *
 */

#include <stdio.h>

/* Prototypes */
void genTop(int ringCount, int coreSize, int lineIndex);
void genMid(int ringCount, int coreSize);
void genBot(int ringCount, int coreSize, int remainDash);

int main(){

	char firstRun = 'y';
	int numOfRings, coreSize, numOfMids;
	int index = 1;

	/* Continue to loop through until 0 0 is entered */
	while( numOfRings != 0){

		/* Will only print the directions once, the first time the user inputs values. */
		if(firstRun == 'y'){
			printf("Please enter the desired number of rings followed by the core size separated by a space. Enter 0 0 to quit. ");
			scanf("%d %d", &numOfRings, &coreSize);
			firstRun = 'n';
		}
		else{
			scanf("%d %d", &numOfRings, &coreSize);
		}

		/* Have the user re-enter the numbers if they are negative */
		while (numOfRings < 0 || coreSize < 0){
			printf("Positive numbers only. Please re-enter your numbers. ");
			scanf("%d %d", &numOfRings, &coreSize);
		}
		
		numOfMids = coreSize;

		printf("\n");
		printf("Rings: %d\n", numOfRings);
		printf("Core Size: %d\n", coreSize);
		printf("\n");

		/* Loop to calculate the needed amount of rows */
		while (index <= ((numOfRings * 2) + coreSize)){

            if(index > numOfRings){

                /* Check if it's the middle*/
                if (numOfMids > 0){

                    /*genMid(numOfRings, coreSize, index);*/
                    genMid(numOfRings, coreSize);
                    numOfMids--;
                }

                /*It's the bottom if it's nowhere else*/
                else{

                    int botDashes = numOfRings;
                    for (botDashes = numOfRings; botDashes > 0; botDashes--){
                        genBot(numOfRings, coreSize, botDashes);
                        index++;
                    }
                }
            }
			else{

			    genTop(numOfRings, coreSize, index);
			}
			index++;
		}
		index = 1;
		printf("\n");
	}
	return (0);
}

/* function genTop
    Used for calculating/drawing the top part of the rings.
    Params:
        ringCount - The input ring size.
        coreSize - The input core size.
        lineIndex - The line which you are currently printing out to the screen.
    Return: void
*/
void genTop(int ringCount, int coreSize, int lineIndex){

    int numOfSpaces = ringCount - lineIndex;
	int numOfDashes = ringCount - numOfSpaces;
	int leftDash, middleDash, rightDash;

	for(numOfSpaces = ringCount - lineIndex; numOfSpaces > 0; numOfSpaces--){

		printf(" ");
	}

    /* Print left dashes on left side */
    leftDash = numOfDashes;
	while(leftDash > 0){

		printf("/");
		leftDash--;
	}

	/* Print middle of ring */
	middleDash = coreSize;
    while(middleDash > 0){

        printf("-");
        middleDash--;
    }

    /* Print right dashes on right side */
    rightDash = numOfDashes;
    while(rightDash > 0){

        printf("\\");
        rightDash--;
    }

	printf("\n");
}

/* function genMid
    Used for calculating/drawing the middle part of the rings.
    Params:
        ringCount - The input ring size.
        coreSize - The input core size.
    Return: void
*/
void genMid(int ringCount, int coreSize){

    int leftDash, middleDash, rightDash;
		
	/* Print left dashes on left side */	
	leftDash = ringCount;
	while(leftDash > 0){

		printf("|");
		leftDash--;
	}

	/* Print middle of ring */
	middleDash = coreSize;
    while(middleDash > 0){

        printf(" ");
        middleDash--;
    }

    /* Print right dashes on right side */
    rightDash = ringCount;
    while(rightDash > 0){

        printf("|");
        rightDash--;
    }

    printf("\n");
}

/* function genBot
    Used for calculating/drawing the bottom part of the rings.
    Params:
        ringCount - The input ring size.
        coreSize - The input core size.
        remainDash - The number of dashes remaining. Used to calculate the number of spaces to
                    print and how many dashes to print on each line
    Return: void
*/
void genBot(int ringCount, int coreSize, int remainDash){

    int numOfDashes = remainDash;
    int numOfSpaces = ringCount - numOfDashes;
	int leftDash, middleDash, rightDash;

	for(numOfSpaces = ringCount - numOfDashes; numOfSpaces > 0; numOfSpaces--){

		printf(" ");
	}

    /* Print left dashes on left side */
    leftDash = numOfDashes;
	while(leftDash > 0){

		printf("\\");
		leftDash--;
	}

	/* Print middle of ring */
	middleDash = coreSize;
    while(middleDash > 0){

        printf("-");
        middleDash--;
    }

    /* Print right dashes on right side */
    rightDash = numOfDashes;
    while(rightDash > 0){

        printf("/");
        rightDash--;
    }

	printf("\n");
}
