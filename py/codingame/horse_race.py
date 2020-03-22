import random
import pprint

strengths = []
for i in range(10):
    pi = random.randint(30, 100)
    strengths.append(pi)

strengths.sort

smallest_difference = strengths[1] - strengths[0] if len(strengths) > 1 else 0
pprint.pprint(strengths)

for i, s in enumerate(strengths):
    if i > 0:
        current_difference = s - strengths[i-1]
        if current_difference < smallest_difference:
            smallest_difference = current_difference

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)

print(smallest_difference)