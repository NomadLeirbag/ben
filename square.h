#ifndef SQUARE_H
#define SQUARE_H

#include "uniqueList.h"
#include "node.h"
class Grid;

/**
 * Class to hold data about one square in grid. Friends with Grid so that Grid can manage Square's pointers but no other code can
 */
class Square {
	friend class Grid;
	public:
		/**
		 * initializes the new square object with itx coordinates
		 *
		 * @param tempX this square's x coordinate
		 * @param tempY this square's y coordinate
		 */
		Square(int tempX, int tempY);
		/**
		 * this function should be called after this square has been scanned by a ping sensor to store the relevent information
		 *
		 * @param found was an object found here?
		 * @param position the Square that the ping sensor was at when it scanned this Square
		 */
		void scanned(bool found, Square* position);
		/**
		 * returns the probability of there being an object here
		 * @return the probability as a decimal from 0 to 1
		 */
		double probability();
		const int x, y;
		/**
		 * checks to see if two Squares are equal by comparing their x and y coordinates. a shallow comparison should be good enough since there should only ever be one of every Square, and that in the Grid. everything else should be pointers
		 *
		 * @param other the Square to compare to this one
		 * @return true if they are equal, false otherwise
		 */
		bool operator==(const Square& other);
		/**
		 * checks to see if two Squares are unequal by taking the opposite of operator==. a shallow comparison should be good enough since there should only ever be one of every Square, and that in the Grid. everything else should be pointers
		 *
		 * @param other the Square to compare to this one
		 * @return true if they aren't equal, false otherwise
		 */
		bool operator!=(const Square& other);
		/**
		 * compares two Square's to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Square to compare to this one
		 * @return true if Square invoked upon is smaller than `other`, false otherwise
		 */
		bool operator>(const Square& other);
		/**
		 * compares two Square's to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Square to compare to this one
		 * @return true if Square invoked upon is larger than `other`, false otherwise
		 */
		bool operator<(const Square& other);
		/**
		 * compares two Square's to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Square to compare to this one
		 * @return true if Square invoked upon is larger than or equal to `other`, false otherwise
		 */
		bool operator>=(const Square& other);
		/**
		 * compares two Square's to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Square to compare to this one
		 * @return true if Square invoked upon is smaller than or equal to `other`, false otherwise
		 */
		bool operator<=(const Square& other);
	private:
		int numTimesScanned, numTimesFound;
		UniqueList<Square*> scannedFrom;
		Square* adjacent[4];
	};

#endif