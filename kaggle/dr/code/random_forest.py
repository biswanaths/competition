#!/usr/bin/env python

'''

Random forest implementation for the digit recognizer 
Inspired by the script released by Author Hideki Ikeda

@Author : Biswanath 
@Date   : 28th Aug, 2015

'''


import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
from sklearn.cross_validation import cross_val_score

'''
Write the ans, a one dimensional array to file
the format is 
header : ImageId,Label
follwed by rows, 
ImageId is serial number 
Label is the predicted value of the digit
'''
def write_ans(ans):
    with open('../data/ans.out','w') as f:
        f.write("ImageId,Label\n")
        f.writelines([ str(idx+1) + "," + str(val) + "\n"  for idx, val in enumerate(ans)])

def start_prediction():
    test = pd.read_csv('../data/test.csv')
    train = pd.read_csv('../data/train.csv')

    train_xs = train.values[:, 1:].astype(float)
    train_ys = train.values[:, 0]

    test_xs = test.values.astype(float)

    #just use forest with 100 tress for the prediction
    recognizer = RandomForestClassifier(100) 

    # training with the data
    recognizer.fit(train_xs, train_ys)

    ans = recognizer.predict(test_xs)

    return ans


def main():
    print "Digit Recognizer"
    
    print "Loading data" 

    data = pd.read_csv('../data/train.csv')

    X_tr = data.values[:, 1:].astype(float)
    Y_tr = data.values[:, 0]

    scores = list()
    scores_std = list()

    print "Start learning"
    n_trees = [ 10, 15, 20, 25, 30, 40, 50, 70, 100]
    
    for n_tree in n_trees: 
        print n_tree
        recognizer = RandomForestClassifier(n_tree)
        score = cross_val_score(recognizer, X_tr, Y_tr)
        scores.append( np.mean(score))
        scores_std.append( np.std(score))

    sc_array = np.array(scores)
    std_array = np.array(scores_std)
    print('Score: ', sc_array)
    print('Std  : ', std_array)

    plt.plot(n_trees, scores)
    plt.plot(n_trees, sc_array + std_array, 'b--')
    plt.plot(n_trees, sc_array - std_array, 'b--')
    plt.ylabel('CV Score')
    plt.xlabel('# of trees')
    plt.savefig('cv_trees.png')
    print 'Done'

if __name__ == '__main__':
    main()

