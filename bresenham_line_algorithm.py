#Assumptions :
#Only for the octant in which segment goes down and to the right (x0 <= x1 and y0 <= y1) and horizontal projection (x1-x0) is longer than the vertical projection (y1-y0)  In this octant, for each column x between x0 and x1, there is exactly one row y (computed by the algorithm) containing a pixel of the line, while each row between y0 and y1 may contain multiple rasterized pixels.

#Given the start (x0, y0) and end (x1, y1) coordinates, draw a line using only setPixel function
x0, y0, x1, y1 = map(int, raw_input().split(' '))
def line(x0, y0, x1, y1):
    deltax = x1 - x0
    deltay = y1 - y0
    error = 0
    deltaerr = abs(float(deltay) / deltax)
    y = y0
    for x in range(x0, x1+1):
        print 'setPixel(', x, ',', y, ')' #Call setPixel(x, y)
        error = error + deltaerr
        while error >= 0.5:
            print 'setPixel(', x, ',', y, ')' #Call setPixel(x, y)
            sign = -1 if y1 - y0 < 0 else 1
            y = y + sign
            error = error - 1

line(x0, y0, x1, y1)
