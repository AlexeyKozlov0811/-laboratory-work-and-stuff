from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from math import *

from matplotlib import pyplot as plt
from numpy import *
from IM_L4_ui import Ui_MainWindow
import sys

class body:
    x0 = 0
    y0 = 0
    alpha = 0
    a = 0
    v0 = 0
    x_t = 0
    y_t = 0
    t_t = 0
    x1 = 0
    y1 = 0
    ymax = 0
    S = 0
    t = 0
    ts = []
    xs = []
    ys = []

    def move_to_target(self):
        G = 9.8
        self.a = atan2(self.y_t + 0.5 * G * self.t_t ** 2, self.x_t)
        self.alpha = self.a * 180 / pi
        self.v0 = self.x_t / cos(self.a) * self.t_t
        self.t = (self.v0 * sin(self.a) + sqrt(self.v0 ** 2 * (sin(self.a) ** 2) + 2 * G * self.y0)) / G
        self.x1 = self.x0 + self.v0 * cos(self.a) * self.t
        self.ymax = self.y0 + self.v0 * sin(self.a) * (self.t / 2) - 0.5 * G * (self.t / 2) ** 2
        self.ts = arange(0, self.t, 0.1)
        self.xs = self.x0 + self.v0 * cos(self.a) * self.ts
        self.ys = self.y0 + self.v0 * sin(self.a) * self.ts - 0.5 * G * self.ts ** 2
        self.S = abs(self.x1 - self.x0)

    def move_in_target_econom(self):
        G = 9.8
        self.a = atan2(self.y_t + 0.5 * G, self.x_t)
        self.alpha = self.a * 180 / pi
        self.v0 = self.x_t / cos(self.a)
        self.t = (self.v0 * sin(self.a) + sqrt(self.v0 ** 2 * (sin(self.a) ** 2) + 2 * G * self.y0)) / G
        self.x1 = self.x0 + self.v0 * cos(self.a) * self.t
        self.ymax = self.y0 + self.v0 * sin(self.a) * (self.t / 2) - 0.5 * G * (self.t / 2) ** 2
        self.ts = arange(0, self.t, 0.1)
        self.xs = self.x0 + self.v0 * cos(self.a) * self.ts
        self.ys = self.y0 + self.v0 * sin(self.a) * self.ts - 0.5 * G * self.ts ** 2
        self.S = abs(self.x1 - self.x0)

class MyWindow(QMainWindow, Ui_MainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("l4")
        self.radioButton.setChecked(True)
        self.pushButton.clicked.connect(self.Compute_all)

    def fill_table(self, bodys):
        for idx in range(3):
            self.tableWidget.setItem(idx, 0, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].x0)))))
            self.tableWidget.setItem(idx, 1, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].y0)))))
            self.tableWidget.setItem(idx, 2, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].v0)))))
            self.tableWidget.setItem(idx, 3, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].alpha)))))
            self.tableWidget.setItem(idx, 4, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].x_t)))))
            self.tableWidget.setItem(idx, 5, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].y_t)))))
            self.tableWidget.setItem(idx, 6, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].t_t)))))
            self.tableWidget.setItem(idx, 7, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].x1)))))
            self.tableWidget.setItem(idx, 8, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].y1)))))
            self.tableWidget.setItem(idx, 9, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].ymax)))))
            self.tableWidget.setItem(idx, 10, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].S)))))
            self.tableWidget.setItem(idx, 11, QTableWidgetItem(str(float("{0:.2f}".format(bodys[idx].t)))))

    def Compute_all(self):
        bodys = [body(), body(), body()]

        if self.radioButton.isChecked():
            bodys[0].x_t = float(self.doubleSpinBox.text().replace(',', '.'))
            bodys[1].x_t = float(self.doubleSpinBox_4.text().replace(',', '.'))
            bodys[2].x_t = float(self.doubleSpinBox_7.text().replace(',', '.'))

            bodys[0].y_t = float(self.doubleSpinBox_2.text().replace(',', '.'))
            bodys[1].y_t = float(self.doubleSpinBox_5.text().replace(',', '.'))
            bodys[2].y_t = float(self.doubleSpinBox_8.text().replace(',', '.'))

            bodys[0].t_t = float(self.doubleSpinBox_3.text().replace(',', '.'))
            bodys[1].t_t = float(self.doubleSpinBox_6.text().replace(',', '.'))
            bodys[2].t_t = float(self.doubleSpinBox_9.text().replace(',', '.'))
            for current_body in bodys:
                current_body.move_to_target()
            self.fill_table(bodys)

            fig, ax = plt.subplots()
            ax.plot(bodys[0].xs, bodys[0].ys, label='y1(x1)')
            ax.plot(bodys[0].x_t, bodys[0].y_t, 'bo', label='x1_t:y1_t')
            ax.plot(bodys[1].xs, bodys[1].ys, 'r', label='y2(x2)')
            ax.plot(bodys[1].x_t, bodys[1].y_t, 'ro', label='x2_t:y2_t')
            ax.plot(bodys[2].xs, bodys[2].ys, 'g', label='y3(x3)')
            ax.plot(bodys[2].x_t, bodys[2].y_t, 'go', label='x3_t:y3_t')
            leg = ax.legend()
            plt.show()

        if self.radioButton_2.isChecked():
            bodys[0].x_t = float(self.doubleSpinBox_10.text().replace(',', '.'))
            bodys[0].y_t = float(self.doubleSpinBox_11.text().replace(',', '.'))
            for current_body in bodys:
                current_body.move_in_target_econom()

            self.fill_table(bodys)

            fig, ax = plt.subplots()
            ax.plot(bodys[0].xs, bodys[0].ys, label='y(x)')
            ax.plot(bodys[0].x_t, bodys[0].y_t, 'bo', label='x_t:y_t')
            leg = ax.legend()
            plt.show()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
