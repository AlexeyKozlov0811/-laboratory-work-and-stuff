from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *

from matplotlib import colors, pyplot
from numpy import *
from IM_L2_UI import Ui_MainWindow
import sys

class MyWindow(QMainWindow, Ui_MainWindow):
    x = []
    numbers = []
    intervals = [0.0]

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
        pi = self.pi.text().split(',')
        xi = self.xi.text().split(',')
        self.table_freq_and_intervals.setRowCount(len(pi))
        for number_idx in range(int(self.number_of_digits.text())):
            if number_idx != 0:
                self.numbers.append((M * self.numbers[number_idx - 1]) % 1)
            else:
                self.numbers.append(2 ** (-m))

        frequency = [0]

        for i in range(len(pi)):
            self.intervals.append(self.intervals[i] + float(pi[i]))
            frequency.append(0)

        in_start = self.intervals[0:-1]
        in_finish = self.intervals[1:]

        for value in self.numbers:
            for i in range(len(self.intervals)-1):
                if in_start[i] <= value < in_finish[i]:
                    frequency[i] += 1
                    self.x.append(int(xi[i]))

        self.numbers_table.setRowCount(int(self.number_of_digits.text()))
        for i in range(int(self.number_of_digits.text())):
            self.numbers_table.setItem(i, 0, QTableWidgetItem("{0:.2f}".format(self.numbers[i])))
            self.numbers_table.setItem(i, 1, QTableWidgetItem(str(self.x[i])))
        self.numbers_table.resizeColumnsToContents()

        for i in range(len(self.intervals)-1):
            stringOfInterval = str(float("{0:.2f}".format(in_start[i]))) + " - " \
                               + str(float("{0:.2f}".format(in_finish[i])))
            self.table_freq_and_intervals.setItem(i, 0, QTableWidgetItem(stringOfInterval))
            self.table_freq_and_intervals.setItem(i, 1, QTableWidgetItem(str(frequency[i])))
            self.table_freq_and_intervals.setItem(i, 2, QTableWidgetItem(str(frequency[i] /
                                                                             int(self.number_of_digits.text()))))
        #
        mx = mean(self.x)  # математическое ожидание
        self.math_exp.setText(str(mx))
        dx = var(self.x)  # дисперсия
        self.dispersion.setText(str(dx))
        o = std(self.x)  # среднеквадратическое отклонение
        self.standart_devitation.setText(str(o))

        self.table_freq_and_intervals.resizeColumnsToContents()

    def Show_Gist(self):
        fig, axs = pyplot.subplots(1, 1, sharey=True, tight_layout=True)

        axs.hist(self.numbers, self.intervals)
        N, bins, patches = axs.hist(self.numbers, bins=self.intervals)

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
