#!/usr/bin/env python3.5
import re
s = input()
r = re.findall(r'\d+', s)
r = [int(i) for i in r]
r.sort()
#print(r)
print(int(r[2])-int(r[0]))
