import random

for ndx in range(0,2):
	print 1000
	pnts = {}
	for idx in range(0,1000):
		while True:
			nx = random.randint(1,99)
			ny = random.randint(1,99)
			if ((nx,ny)) not in pnts:
				penalty = random.randint(1,100)
				pnts[(nx,ny)] = penalty
				print nx, ny, penalty
				break

print 0
