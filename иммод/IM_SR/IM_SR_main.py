from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from matplotlib import colors, pyplot
from numpy import *
from IM_SR_ui import Ui_MainWindow
import sys

class MyWindow(QMainWindow, Ui_MainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("Дослідження генератора випадкових чисел")
        self.radioButton.setChecked(True)
        self.pushButton.clicked.connect(self.Reset)
        self.pushButton_2.clicked.connect(self.Compute)

    def Reset(self):
        self.spinBox.setValue(11)
        self.spinBox_2.setValue(123456789)
        self.spinBox_3.setValue(31)

    def Compute(self):
        U0 = random.random()
        U = [U0]
        A = self.spinBox.value()
        B = self.spinBox_2.value()
        M = self.spinBox_3.value()
        length = self.spinBox_4.value()
        number_of_intervals = self.spinBox_5.value()

        for _ in range(length - 1):
            U.append((U[-1] * B + A) % M % 1)

        if self.radioButton.isChecked():
            self.textBrowser.setHtml("")
            INTERVALS = 1 / number_of_intervals
            self.tableWidget.setRowCount(number_of_intervals)
            frequency = [0] * int(1 / INTERVALS)
            intervals = []
            left_interval_border = 0
            right_interval_border = INTERVALS
            for interval in range(number_of_intervals):
                stringOfInterval = str(float("{0:.2f}".format(left_interval_border))) + " - " + str(
                    float("{0:.2f}".format(right_interval_border)))
                intervals.append(stringOfInterval)
                left_interval_border += INTERVALS
                right_interval_border += INTERVALS
                self.tableWidget.setItem(interval, 0, QTableWidgetItem(stringOfInterval))
            self.tableWidget.resizeColumnsToContents()

            for number_idx in range(length):
                U.append((U[-1] * B + A) % M % 1)
                left_interval_border = 0
                right_interval_border = INTERVALS
                for interval_idx in range(int(number_of_intervals)):
                    if left_interval_border <= U[number_idx] < right_interval_border:
                        frequency[interval_idx] += 1
                        break
                    else:
                        left_interval_border += INTERVALS
                        right_interval_border += INTERVALS

            for interval_idx in range(int(number_of_intervals)):
                self.tableWidget.setItem(interval_idx, 1, QTableWidgetItem(str(frequency[interval_idx])))
                self.tableWidget.setItem(interval_idx, 2, QTableWidgetItem(str(frequency[interval_idx] / length)))
            self.tableWidget.resizeColumnsToContents()

            fig, axs = pyplot.subplots(1, 1, sharey=True, tight_layout=True)

            axs.hist(U, number_of_intervals)
            N, bins, patches = axs.hist(U, bins=number_of_intervals)

            fracs = N / N.max()

            norm = colors.Normalize(fracs.min(), fracs.max())

            for thisfrac, thispatch in zip(fracs, patches):
                color = pyplot.cm.viridis(norm(thisfrac))
                thispatch.set_facecolor(color)

            pyplot.show()
        else:
            self.tableWidget.setRowCount(0)
            self.tableWidget.resizeColumnsToContents()
            try:
                period = U.index(U0, 1)
                self.textBrowser.setHtml("Періодичність вибірки = " + str(period))
            except ValueError:
                self.textBrowser.setHtml("Періодичність більше обсягу вибірки")


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
