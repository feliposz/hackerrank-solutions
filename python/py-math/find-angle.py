# Enter your code here. Read input from STDIN. Print output to STDOUT
# -*- coding: iso-8859-15 -*-

import math

ab = input()
bc = input()
print str(int(round(math.degrees(math.atan2(ab, bc))))) + "°"

