# matricea de confuzie
class Clasificator:

    def metrici(computedValues, groundTruth, good, bad):
        TP = 0
        TN = 0
        FP = 0
        FN = 0
        for computed_value, groundTruth_value in zip(computedValues, groundTruth):
            if computed_value == good:
                if groundTruth_value == good:
                    TP += 1
                else:
                    FP += 1
            elif computed_value == bad:
                if groundTruth_value == good:
                    FN += 1
                else:
                    TN += 1
        return TP, TN, FP, FN
    
    def accuracy(TP,TN,FP,FN):
        if TP+TN+FP+FN == 0:
            return 0
        return (TP + TN) / (TP+TN+FP+FN)

    def precision(TP,TN,FP,FN):
        if TP + FP == 0:
            return 0
        return TP/(TP + FP)

    def recall(TP,TN,FP,FN):
        if TP+FN == 0:
            return 0
        return TP/(TP+FN)
        
