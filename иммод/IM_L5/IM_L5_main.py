from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from scipy.stats import binom
from matplotlib import pyplot as plt
from IM_L5_ui import Ui_MainWindow
import sys

class MyWindow(QMainWindow, Ui_MainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("l5")
        self.pushButton.clicked.connect(self.Compute)

    def Compute(self):
        times = self.spinBox.value()
        p = self.doubleSpinBox.value()
        Y = list(binom.rvs(1, p, size=times))
        self.tableWidget.setRowCount(times)
        for i in range(times):
            self.tableWidget.setItem(i, 0, QTableWidgetItem("{0:.1f}".format(Y[i])))
        self.tableWidget.resizeColumnsToContents()
        X = [0, 1]
        P = [Y.count(0)/times, Y.count(1)/times]
        fig1, ax1 = plt.subplots()
        ax1.plot(P, X)
        ax1.grid(True)
        plt.xlabel('P')
        plt.ylabel('X')
        plt.title("Многокутник розподілу випадкової величини Х")

        fig2, ax2 = plt.subplots()
        ax2.bar([0, 1, 2, 3], [0] + P + [1])
        ax2.grid(True)
        plt.xlabel('X')
        plt.ylabel('F(x)')
        plt.title("Функція розподілу F(x) дискретної випадкової величини Х")
        plt.show()
        print(P)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
