from math import exp
import numpy as np


def sigmoid(x):
    return 1/(1 + exp(-x))

class MyLogisticRegressor:

    def __init__(self) -> None:
        self.W = {}
        
    def train(self, input_set, output_set, learning_rate=0.001, noEpochs=100):
        X = [[1] + line for line in input_set]
        m = len(X[0])
        for value in set(output_set):
            self.W[value] = []
            for _ in range(m):
                self.W[value].append(np.random.random())

        for _ in range(noEpochs):
            errors = {}
            for value in set(output_set):
                errors[value] = []
                for _ in range(m):
                    errors[value].append(0.0)

            for input_line, output_line in zip(X, output_set):
                for key in self.W.keys():
                    prediction = sum(input_line[j] * self.W[key][j] for j in range(m))
                    error = 0
                    if(key == output_line):
                        error = 1 - prediction
                    else:
                        error = 0 - prediction
                    for j in range(m):
                        errors[key][j] += error * input_line[j]

            for j in range(m):
                for key in self.W.keys():
                    self.W[key][j] += learning_rate * errors[key][j] / len(input_set)

    def getKeyForInput(self,input_line):
        max_prob = 0
        k = None
        for key in self.W.keys():
            value = sigmoid(sum([w*v for w,v in zip(self.W[key],input_line)]))
            if value > max_prob:
                max_prob = value
                k = key
        return k

    def predict(self, input_set):
        X = [[1] + line for line in input_set]
        output_set = []
        for line in X:
            output_set.append(self.getKeyForInput(line))
        return output_set