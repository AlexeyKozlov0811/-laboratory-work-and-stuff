from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *

from matplotlib import colors, pyplot
from numpy import *
from IM_L1_UI import Ui_MainWindow
import sys

class MyWindow(QMainWindow, Ui_MainWindow):
    number_of_digits = 1000
    x = []
    number_of_intervals = 0

    def __init__(self):
        QMainWindow.__init__(self)
        self.setupUi(self)

        self.setWindowTitle("Випадкові числа")

        self.Compute.clicked.connect(self.Compute_all)
        self.ShowGist.clicked.connect(self.Show_Gist)
        self.ShowGist.setEnabled(False)

    def Compute_all(self):
        self.ShowGist.setEnabled(True)
        M = int(self.M.text())
        m = int(self.m.text())
        self.number_of_intervals = int(self.number_of_intervals.text())

        INTERVALS = 1 / self.number_of_intervals
        self.table_freq_and_intervals.setRowCount(self.number_of_intervals)
        frequency = [0] * int(1 / INTERVALS)
        intervals = []

        left_interval_border = 0
        right_interval_border = INTERVALS
        for interval in range(self.number_of_intervals):
            stringOfInterval = str(float("{0:.2f}".format(left_interval_border))) + " - " + str(
                float("{0:.2f}".format(right_interval_border)))
            intervals.append(stringOfInterval)
            left_interval_border += INTERVALS
            right_interval_border += INTERVALS
            self.table_freq_and_intervals.setItem(interval, 0, QTableWidgetItem(stringOfInterval))
        self.table_freq_and_intervals.resizeColumnsToContents()

        for number_idx in range(self.number_of_digits):
            if number_idx != 0:
                self.x.append((M * self.x[number_idx - 1]) % 1)
            else:
                self.x.append(2 ** (-m))

            left_interval_border = 0
            right_interval_border = INTERVALS
            for interval_idx in range(int(self.number_of_intervals)):
                if left_interval_border <= self.x[number_idx] < right_interval_border:
                    frequency[interval_idx] += 1
                    break
                else:
                    left_interval_border += INTERVALS
                    right_interval_border += INTERVALS

        self.numbers_table.setRowCount(self.number_of_digits)
        for number_idx in range(self.number_of_digits):
            self.numbers_table.setItem(number_idx, 0, QTableWidgetItem(str(self.x[number_idx])))
        self.numbers_table.resizeColumnsToContents()

        for interval_idx in range(int(self.number_of_intervals)):
            self.table_freq_and_intervals.setItem(interval_idx, 1, QTableWidgetItem(str(frequency[interval_idx])))
            self.table_freq_and_intervals.setItem(interval_idx, 2, QTableWidgetItem(str(frequency[interval_idx] / self.number_of_digits)))
        self.table_freq_and_intervals.resizeColumnsToContents()

        mx = mean(self.x)  # математическое ожидание
        self.math_hope.setText(str(mx))
        dx = var(self.x)  # дисперсия
        self.dispersion.setText(str(dx))
        o = std(self.x)  # среднеквадратическое отклонение
        self.standart_devitation.setText(str(o))

    def Show_Gist(self):
        fig, axs = pyplot.subplots(1, 1, sharey=True, tight_layout=True)

        axs.hist(self.x, self.number_of_intervals)
        N, bins, patches = axs.hist(self.x, bins=self.number_of_intervals)

        fracs = N / N.max()

        norm = colors.Normalize(fracs.min(), fracs.max())

        for thisfrac, thispatch in zip(fracs, patches):
            color = pyplot.cm.viridis(norm(thisfrac))
            thispatch.set_facecolor(color)

        pyplot.show()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
