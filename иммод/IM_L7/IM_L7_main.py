from math import *
import random
from matplotlib import pyplot as plt
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from IM_L7_ui import Ui_MainWindow
import sys


class MyWindow(QMainWindow, Ui_MainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("l7")
        self.pushButton.clicked.connect(self.Compute)

    def Compute(self):
        Q = self.doubleSpinBox.value()
        U = self.doubleSpinBox_2.value()
        R = self.doubleSpinBox_3.value()
        N = self.spinBox.value()
        t = [0]
        q = []
        for i in range(1, N):
            t.append(t[i - 1] + random.random())

        for i in range(N):
            q.append(U * Q * (1 - pow(e, (-t[i] / (Q * R)))))

        ct = self.doubleSpinBox_4.value()
        qt = U * Q * (1 - pow(e, (-ct / (Q * R))))
        self.lineEdit.setText("{0:.4f}".format(qt))

        plt.plot(t, q)
        plt.show()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
