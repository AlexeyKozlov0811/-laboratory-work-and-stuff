from random import *
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
from IM_SR2_ui import Ui_MainWindow
import numpy as np
import json

def digits_recursive(n, digits=None):
    if digits is None:
        digits = []
    return digits_recursive(n // 10, [n % 10] + digits) if n else digits or [0]

def discrete_variate(Seed):
    discrete_values = digits_recursive(Seed)
    basic_p = 1/len(discrete_values)
    p_dict = {}
    for i in discrete_values:
        if i in p_dict:
            p_dict[i] += 1
        else:
            p_dict[i] = 1
    prev_p = 0
    for key in p_dict:
        prev_p += p_dict[key]*basic_p
        p_dict[key] = prev_p
    rv = random()
    interval_i = 0
    for key in p_dict:
        if rv <= p_dict[key]:
            rv = key
            break
        else:
            interval_i += 1
    return rv

def arbitrary_distribution(Seed):
    discrete_values = sorted(list(set(digits_recursive(Seed))))
    basic_p = 1 / (2*len(discrete_values))
    p_dict = {}
    for i in discrete_values:
        if i in p_dict:
            p_dict[i] += 1
        else:
            p_dict[i] = 1
    prev_p = 0
    shift = 0
    for key in p_dict:
        prev_p += p_dict[key] * basic_p + shift*2*basic_p
        p_dict[key] = prev_p
        shift += 1
    rv = uniform(0, 2)
    interval_i = 0
    for key in p_dict:
        if rv <= p_dict[key]:
            rv = key
            break
        else:
            interval_i += 1
    return rv


class MyWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)
        self.setWindowTitle("IM_SR2")
        self.pushButton.clicked.connect(self.create_file)
        self.pushButton_2.clicked.connect(self.view_file)
        self.pushButton_3.clicked.connect(self.view_params_file)
        self.pushButton_4.clicked.connect(self.pirson_test)

    def create_file(self):
        N = self.spinBox.value()
        Zach = self.spinBox_2.value()
        Last_two = Zach % 100
        betas = {
            0: 2,
            1: 3
        }
        beta = betas[Last_two % 2]
        variates = {
            0: [expovariate(1/Last_two) for _ in range(N)],
            1: [gammavariate(Last_two, beta) for _ in range(N)],
            2: [normalvariate(Last_two, Last_two*0.2) for _ in range(N)],
            3: [uniform(Last_two/2, Last_two*4) for _ in range(N)],
            4: [discrete_variate(Zach) for _ in range(N)],
            5: [arbitrary_distribution(Zach) for _ in range(N)],
        }
        X = variates[self.comboBox.currentIndex()]
        X = sorted(X)
        self.mplWidget.canvas.axes.clear()
        self.mplWidget.canvas.axes.hist(X)
        self.mplWidget.canvas.draw()

        filename = self.lineEdit.text()
        with open(filename, 'w') as fw:
            json.dump(X, fw)

    def view_file(self):
        filename = self.lineEdit.text()
        with open(filename, 'r') as fr:
            X = json.load(fr)
        if len(X) == len(set(X)):
            self.textBrowser.setText("Неперервна величина")
        else:
            self.textBrowser.setText("Дискретна величина")

    def view_params_file(self):
        filename = self.lineEdit.text()
        with open(filename, 'r') as fr:
            X = json.load(fr)
        self.textBrowser.setText("")
        for x in X:
            self.textBrowser.append(str(x))
        self.mplWidget.canvas.axes.clear()
        self.mplWidget.canvas.axes.hist(X)
        self.mplWidget.canvas.draw()

    def pirson_test(self):
        filename = self.lineEdit.text()
        with open(filename, 'r') as fr:
            X = json.load(fr)

        freq, bins = np.histogram(X)
        theoretical_frequency = len(X)/len(bins)
        critical_distribution_points = {1: 0.05, 2: 3.8, 3: 6.0, 4: 7.8, 5: 9.5, 6: 11.1, 7: 12.6, 8: 14.1,
                                        9: 15.5, 10: 16.9, 11: 19.7, 12: 21.0, 13: 22.4, 14: 23.7, 15: 25.0,
                                        16: 26.3, 17: 27.6, 18: 28.9, 19: 30.1, 20: 31.4, 21: 32.7, 22: 33.9,
                                        23: 35.2, 24: 36.4, 25: 37.7, 26: 38.9, 27: 40.1, 28: 41.3, 29: 42.6,
                                        30: 43.8}
        xi2 = 0
        for i in range(len(bins) - 1):
            xi2 += (freq[i] - theoretical_frequency) ** 2 / theoretical_frequency
        self.textBrowser.setText("Хі-квадрат = " + str(xi2))
        degree_of_freedom = (len(bins) - 1) - 1
        critical_point = critical_distribution_points.get(degree_of_freedom)
        self.textBrowser.append("\nКритичне значення = " + str(critical_point))

        if xi2 < critical_point:
            self.textBrowser.append("\nГіпотезу про рівномірний розподіл можна прийняти")
        else:
            self.textBrowser.append("\nГіпотезу про рівномірний розподіл НЕ можна прийняти")


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
