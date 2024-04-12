from math import exp
import numpy as np

def sigmoid(x):
    return 1/(1 + exp(-x))

class MyLogisticRegressor:

    def __init__(self) -> None:
        self.W = []
        self.dict = {}
        
    def train(self, input_set, output_set, learning_rate=0.001, noEpochs=100):
        count = 0
    
        for value in set(output_set):
            self.dict[value] = count
            count += 1
        
        X = [[1] + line for line in input_set]
        m = len(X[0])
        for i in range(m):
            self.W.append(np.random.random())

        for _ in range(noEpochs):
            errors = []
            for i in range(m):
                errors.append(0.0)

            for input_line, output_line in zip(X, output_set):

                prediction = sum(input_line[j] * self.W[j] for j in range(m))
                error = self.dict[output_line] - prediction

                for j in range(m):
                    errors[j] += error * input_line[j]

            for j in range(m):
                self.W[j] += learning_rate * errors[j] / len(input_set)

    def find_key_by_value(self,value):
        for key in self.dict.keys():
            if self.dict[key] == value:
                return key
        return None

    def predict(self, input_set):
        X = [[1] + line for line in input_set]
        output_set = []
        for line in X:
            value = sum([w*v for w,v in zip(self.W,line)])
            if value > 0.5:
                output_set.append(self.find_key_by_value(1))
            else:
                output_set.append(self.find_key_by_value(0))
                
        return output_set