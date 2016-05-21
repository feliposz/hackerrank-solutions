import csv
import numpy as np
from numpy.linalg import pinv

xs = []
ys = []

with open('trainingdata.txt', mode='rt', newline='\n') as f:
    f_csv = csv.reader(f)
    for rx, ry in f_csv:
        fx, fy = float(rx), float(ry)
        # filter noise data
        if fy < 8.0:
            xs.append((1, fx))
            ys.append(fy)

X = np.array(xs)
y = np.array(ys)

# normal equation
theta = pinv(X.transpose().dot(X)).dot(X.transpose()).dot(y).tolist()

while True:
    try:
        s = input()
        x = float(s)
        h = theta[0] + theta[1] * x
        # limit maximum (as with noise data)
        h = h if h < 8.0 else 8.0
        print(h)
    except:
        break

