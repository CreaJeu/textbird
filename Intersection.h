#ifndef INTERSECTION_H
#define INTERSECTION_H

//public methods

//Cohen-Sutherland intersection between a segment and a box (boolean return)
int intersectSegBox(float x1, float y1, float x2, float y2,
					float minX, float minY, float maxX, float maxY);


#endif // INTERSECTION_H

