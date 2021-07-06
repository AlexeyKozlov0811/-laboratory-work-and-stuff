from math import *
from random import *
import matplotlib.pyplot as plt
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from imit_mod6_ui import Ui_MainWindow

class MyWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)
        self.setWindowTitle("Траєкторія руху")

        self.pushButton.clicked.connect(self.count)

    def count(self):
        number = int(self.lineEdit.text())
        a = float(self.lineEdit_2.text())
        b = pi/4

        ksi = []
        X = []
        for i in range(number):
            ksi.append(random())
        ksi.sort()
        for i in range(number):
            X.append(asin(ksi[i]))

        P = sin(b) - sin(a)
        self.lineEdit_4.setText(str(P))

        self.tableWidget.setRowCount(number)
        for i in range(number):
            self.tableWidget.setItem(i, 0, QTableWidgetItem(str("%.8f" % ksi[i])))
        for i in range(number):
            self.tableWidget.setItem(i, 1, QTableWidgetItem(str("%.8f" % X[i])))

        self.mplWidget.canvas.axes.clear()
        self.mplWidget.canvas.axes.plot(X, ksi)

        self.mplWidget.canvas.draw()

        # plt.plot(X, ksi)
        # plt.show()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
