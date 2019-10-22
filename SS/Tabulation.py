import sys
from PyQt5 import QtWidgets
from uis.Tabulation_ui import Ui_MainWindow
import math


class TabulationWindow(QtWidgets.QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()

        self.Tabulate.triggered.connect(self.tabulate)
        self.Clear.triggered.connect(self.clear)
        self.About.triggered.connect(self.about)
        self.Exit.triggered.connect(self.exit)

    def about(self):
        self.Output.setText("Програма призначена для Табулювання функції — це обчислення значень функції при зміненні "
                            "аргументу від деякого початкового значення до деякого кінцевого значення з певним "
                            "кроком. Саме так складають таблиці значень функцій, звідси й назва — табулювання.")

    def tabulate(self):
        x_list = []
        result_list = []

        if self.LeftBorder.value() and self.RightBorder.value() and self.Step.value():
            left_border = self.LeftBorder.value()
            right_border = self.RightBorder.value()
            step = self.Step.value()
            while left_border <= right_border:
                x_list.append(format(left_border, '.3f'))
                result_list.append(format(math.sin(left_border)+1, '.3f'))
                left_border += step

        if self.PrintOnScreen.isChecked():
            self.Output.setText('x: ' + ' '.join(x_list) + '\ny: ' + ' '.join(result_list))

        if self.PrintInFile.isChecked():
            output_file = open('result.txt', 'a')
            for result in result_list:
                output_file.write(result + '\n')
            output_file.write('\n')
            output_file.close()

    def clear(self):
        self.Output.clear()
        self.Step.clear()
        self.LeftBorder.clear()
        self.RightBorder.clear()

    def exit(self):
        sys.exit()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    SS = TabulationWindow()
    sys.exit(app.exec_())
