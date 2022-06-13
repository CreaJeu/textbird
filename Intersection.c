
//#include <stdlib.h>
#include "Intersection.h"

//region codes
const int INSIDE = 0x0000;
const int LEFT = 0x0001;
const int RIGHT = 0x0010;
const int BOTTOM = 0x0100;
const int TOP = 0x1000;

//for Cohen-Sutherland seg_box intersection  (from geeksforgeeks website)
// Function to compute region code for a point(x, y)
int computeRegionCode(float x, float y,
					float minX, float minY, float maxX, float maxY)
{
	// initialized as being inside
	int code = INSIDE;
	if(x < minX) // to the left of rectangle
		code |= LEFT;
	else if(x > maxX) // to the right of rectangle
		code |= RIGHT;
	if(y < minY) // below the rectangle
		code |= BOTTOM;
	else if(y > maxY) // above the rectangle
		code |= TOP;
	return code;
}

// Implementing Cohen-Sutherland algorithm (from geeksforgeeks website)
// Clipping a line from P1 =(x2, y2) to P2 =(x2, y2)
int intersectSegBox(float x1, float y1, float x2, float y2,
					float minX, float minY, float maxX, float maxY)
{
	// Compute region codes for P1, P2
	int code1 = computeRegionCode(x1, y1, minX, minY, maxX, maxY);
	int code2 = computeRegionCode(x2, y2, minX, minY, maxX, maxY);
	// Initialize line as outside the rectangular window
	//int accept = 0;//bool
	while(1)
	{
		if((code1 == 0) &&(code2 == 0))
		{
			// If both endpoints lie within rectangle
			return 1;
		}
		else if(code1 & code2)
		{
			// If both endpoints are outside rectangle,
			// in same region
			return 0;
		}
		else
		{
			// Some segment of line lies within the
			// rectangle
			int code_out;
			float x, y;
			// At least one endpoint is outside the
			// rectangle, pick it.
			if(code1 != 0)
				code_out = code1;
			else
				code_out = code2;
			// Find intersection point;
			// using formulas y = y1 + slope *(x - x1),
			// x = x1 +(1 / slope) *(y - y1)
			if(code_out & TOP)
			{
				// point is above the clip rectangle
				x = x1 +(x2 - x1) *(maxY - y1) /(y2 - y1);
				y = maxY;
			}
			else if(code_out & BOTTOM)
			{
				// point is below the rectangle
				x = x1 +(x2 - x1) *(minY - y1) /(y2 - y1);
				y = minY;
			}
			else if(code_out & RIGHT)
			{
				// point is to the right of rectangle
				y = y1 +(y2 - y1) *(maxX - x1) /(x2 - x1);
				x = maxX;
			}
			else if(code_out & LEFT)
			{
				// point is to the left of rectangle
				y = y1 +(y2 - y1) *(minX - x1) /(x2 - x1);
				x = minX;
			}
			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if(code_out == code1)
			{
				x1 = x;
				y1 = y;
				code1 = computeRegionCode(x1, y1, minX, minY, maxX, maxY);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = computeRegionCode(x2, y2, minX, minY, maxX, maxY);
			}
		}
	}
	return 0;
}

