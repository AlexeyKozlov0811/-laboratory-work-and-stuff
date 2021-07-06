from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *

from matplotlib import colors, pyplot
from matplotlib.pyplot import scatter
from numpy import *
from IM_L3_UI import Ui_MainWindow
import sys
import random
from scipy import interpolate

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

        pi = [float(item) for item in self.pi.text().split(',')]
        xi = [float(item) for item in self.xi.text().split(',')]

        self.table_freq_and_intervals.setRowCount(len(set(pi)))
        for number_idx in range(int(self.number_of_digits.text())):
            self.numbers.append(random.uniform(xi[0], xi[-1]))

        frequency = []

        for i in range(len(set(xi))):
            self.intervals.append(list(set(xi))[i])

        in_start = list(set(xi))[0:-1]
        in_finish = list(set(xi))[1:]

        for idx in range(len(in_start)):
            frequency.append(0)
            for value in self.numbers:
                if in_start[idx] <= value <= in_finish[idx]:
                    frequency[idx] += 1

        for value in self.numbers:
            digit = interp(value, xi, pi)
            self.x.append(digit)

        self.numbers_table.setRowCount(int(self.number_of_digits.text()))
        for i in range(int(self.number_of_digits.text())):
            self.numbers_table.setItem(i, 0, QTableWidgetItem("{0:.2f}".format(self.numbers[i])))
            self.numbers_table.setItem(i, 1, QTableWidgetItem("{0:.2f}".format(self.x[i])))
        self.numbers_table.resizeColumnsToContents()

        for i in range(len(in_start)):
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
        #
        self.table_freq_and_intervals.resizeColumnsToContents()
        lineplot(xi, pi, self.numbers, self.x)
        scatter(self.numbers, self.x, color='red')
        pyplot.show()

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


def lineplot(x_data, y_data, numbers, x, x_label="", y_label="", title=""):
    # Create the plot object
    fig, ax = pyplot.subplots()

    ax.plot(x_data, y_data,
            label='sinc(x)')

    # ax.plot(numbers, x,
    #         marker='x',
    #         label='interp')

    ax.set_title('Линейная интерполяция точек')

    # pyplot.show()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWindow()
    my_app.show()
    sys.exit(app.exec_())
