import random
from math import *
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from IM_L6_ui import Ui_MainWindow
import sys
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
# 11 220 321 231
class MyWindow(QMainWindow, Ui_MainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("l6")
        self.pushButton.clicked.connect(self.Compute)
        self.canvas = Canvas(self, width=3.21, height=2.31)
        self.canvas.move(11, 220)
        N = self.spinBox.value()
        eps = []
        x = []

        for i in range(N):
            eps.append(random.random())
            x.append(sqrt(eps[i]))
        eps.sort()
        x.sort()
        print(eps)
        print(x)
        self.canvas.axes.plot(x, eps)
        self.canvas.axes.grid(True)

    def Compute(self):
        a = self.doubleSpinBox.value()
        b = self.doubleSpinBox_2.value()
        self.lineEdit.setText("{0:.4f}".format(abs(sqrt(a)-sqrt(b))))


class Canvas(FigureCanvas):
    def __init__(self, parent=None, width=5, height=5, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        FigureCanvas.__init__(self, fig)
        self.setParent(parent)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
