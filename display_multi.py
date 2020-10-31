import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as plticker

LIMIT = 5000
def clean(line):
    """
    get a list of values from line
    """
    words = line.split()
    pid = int(words[0])
    queue = int(words[1])
    time = int(words[2])
    return [pid, queue, time]

def get_points():
    points = []
    filename = "output.txt"
    with open(filename) as f:
      content = f.readlines()
    for line in content:
        if line[:6] == "graph:":
            points.append(clean(line[6:]))
        elif line[:8] == "$ graph:":
            points.append(clean(line[8:]))
    return points



def separate(points):
    process_tuples = {}
    for point in points:
        pid = point[0]
        queue = point[1]
        time = point[2]
        if pid not in process_tuples:
            process_tuples[pid] = []
        process_tuples[pid].append((time, queue))
    return process_tuples
points = get_points()
process_tuples = separate(points)
left = 10**4
right = 0
for key in process_tuples.keys():
    plt.plot(*zip(*process_tuples[key]), '-o')
    left = min(left, min(process_tuples[key][0]))
    right = max(right, max(process_tuples[key][0]))
plt.axis((0, LIMIT, 0, 5))
plt.legend()
plt.xticks(np.arange(left, LIMIT, 500.0))
plt.ylabel('Queue')
plt.xlabel('Time')
plt.show()
