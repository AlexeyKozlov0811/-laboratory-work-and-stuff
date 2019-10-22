import sys
from PyQt5 import QtWidgets
from uis.Calculator_ui import Ui_MainWindow


class CalculatorWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    firstNumber = 0
    userIsTypingSecondNumber = False

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()

        self.ResultButton.clicked.connect(self.get_result)

        self.ClearButton.clicked.connect(self.clear_label)

        self.SeparatorButton.clicked.connect(self.decimal_pressed)

        self.ZeroButton.clicked.connect(self.digit_pressed)
        self.OneButton.clicked.connect(self.digit_pressed)
        self.TwoButton.clicked.connect(self.digit_pressed)
        self.ThreeButton.clicked.connect(self.digit_pressed)
        self.FourButton.clicked.connect(self.digit_pressed)
        self.FiveButton.clicked.connect(self.digit_pressed)
        self.SixButton.clicked.connect(self.digit_pressed)
        self.SevenButton.clicked.connect(self.digit_pressed)
        self.EightButton.clicked.connect(self.digit_pressed)
        self.NineButton.clicked.connect(self.digit_pressed)

        self.SignButton.clicked.connect(self.unary_pressed)
        self.PercentButton.clicked.connect(self.unary_pressed)

        self.DivideButton.clicked.connect(self.binary_pressed)
        self.MultiplyButton.clicked.connect(self.binary_pressed)
        self.MinusButton.clicked.connect(self.binary_pressed)
        self.PlusButton.clicked.connect(self.binary_pressed)

        self.DivideButton.setCheckable(True)
        self.MultiplyButton.setCheckable(True)
        self.MinusButton.setCheckable(True)
        self.PlusButton.setCheckable(True)

    def digit_pressed(self):
        button = self.sender()

        if ((self.DivideButton.isChecked() or
             self.MultiplyButton.isChecked() or
             self.MinusButton.isChecked() or
             self.PlusButton.isChecked()) and
                (not self.userIsTypingSecondNumber)):
            newLabel = format(float(button.text()), '.15g')
            self.userIsTypingSecondNumber = True
        else:
            if '.' in self.CalcLabel.text() and button.text() == '0':
                newLabel = format(self.CalcLabel.text() + button.text(), '.15')
            else:
                newLabel = format(float(self.CalcLabel.text() + button.text()), '.15g')

        self.CalcLabel.setText(newLabel)

    def clear_label(self):
        self.DivideButton.setChecked(False)
        self.MultiplyButton.setChecked(False)
        self.MinusButton.setChecked(False)
        self.PlusButton.setChecked(False)
        self.userIsTypingSecondNumber = False
        self.CalcLabel.setText('0')

    def decimal_pressed(self):
        if '.' not in self.CalcLabel.text():
            self.CalcLabel.setText(self.CalcLabel.text() + '.')

    def unary_pressed(self):
        button = self.sender()
        labelNumber = float(self.CalcLabel.text())

        if button.text() == '+/-':
            labelNumber = -labelNumber
        else:
            labelNumber = labelNumber * 0.01

        newLabel = format(labelNumber, '.15g')
        self.CalcLabel.setText(newLabel)

    def binary_pressed(self):
        button = self.sender()
        self.firstNumber = float(self.CalcLabel.text())
        button.setChecked(True)

    def get_result(self):
        secondNumber = float(self.CalcLabel.text())
        labelNumber = self.firstNumber

        if self.DivideButton.isChecked():
            if secondNumber:
                labelNumber /= secondNumber
            else:
                pass
            self.DivideButton.setChecked(False)

        elif self.MultiplyButton.isChecked():
            labelNumber *= secondNumber
            self.MultiplyButton.setChecked(False)

        elif self.MinusButton.isChecked():
            labelNumber -= secondNumber
            self.MinusButton.setChecked(False)

        elif self.PlusButton.isChecked():
            labelNumber += secondNumber
            self.PlusButton.setChecked(False)
        else:
            labelNumber = secondNumber

        self.userIsTypingSecondNumber = False
        self.CalcLabel.setText(format(labelNumber, '.15g'))


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    SS = CalculatorWindow()
    sys.exit(app.exec_())
