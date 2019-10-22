import sys
from PyQt5 import QtWidgets
from uis.Exchange_ui import Ui_MainWindow


class ExchangeWindow(QtWidgets.QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()

        self.BuyButton.setChecked(True)
        self.BuyButton.toggled.connect(self.change_arrow)
        self.SellButton.toggled.connect(self.change_arrow)

        self.ResultButton.clicked.connect(self.get_result)

        self.ExitButton.clicked.connect(self.close_app)

    def change_arrow(self):
        if self.BuyButton.isChecked():
            self.ArrowLabel.setText('-->')
        else:
            self.ArrowLabel.setText('<--')

    def get_result(self):
        if self.BuyButton.isChecked():
            newCurrency = self.LeftCurrency.value() * float(self.CurrencySellLabel.text())
            self.RightCurrency.setValue(newCurrency)
        else:
            newCurrency = self.RightCurrency.value() / float(self.CurrencyBuyLabel.text())
            self.LeftCurrency.setValue(newCurrency)

    def close_app(self):
        sys.exit()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = ExchangeWindow()
    sys.exit(app.exec_())

