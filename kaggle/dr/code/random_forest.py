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

if __name__ == '__main__':
    main()

