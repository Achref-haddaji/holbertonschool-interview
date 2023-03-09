#include "menger.h"

/**
 * menger - function that draws 2D menger square.
 *
 * @level: is the level of the Menger Sponge to draw
 *
 * Description: This function generates a Menger Sponge fractal
 *              based on the input level.
 */
void menger(int level)
{
	int i, j, n, row_idx, col_idx, symbol;

	n = pow(3, level); /* calculate size of the Menger Sponge */
	for (i = 0; i < n; i++) /* iterate over rows */
	{
		for (j = 0; j < n; j++) /* iterate over columns */
		{
			symbol = '#'; /* set the default symbol to # */
			row_idx = i; /* initialize row index */
			col_idx = j; /* initialize column index */
			while (row_idx || col_idx) /* iterate until row or column index is zero */
			{
				if (row_idx % 3 == 1 && col_idx % 3 == 1) /* set symbol to space */
					symbol = ' ';
				row_idx /= 3; /* divide row index by 3 */
				col_idx /= 3; /* divide column index by 3 */
			}
			putchar(symbol); /* print the symbol */
		}
		putchar('\n'); /* print new line after each row */
	}
}
