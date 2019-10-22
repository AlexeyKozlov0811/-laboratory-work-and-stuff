# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uis\Exchange.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(347, 255)
        MainWindow.setMouseTracking(False)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.BuyButton = QtWidgets.QRadioButton(self.centralwidget)
        self.BuyButton.setGeometry(QtCore.QRect(10, 10, 91, 25))
        self.BuyButton.setObjectName("BuyButton")
        self.SellButton = QtWidgets.QRadioButton(self.centralwidget)
        self.SellButton.setGeometry(QtCore.QRect(250, 10, 91, 25))
        self.SellButton.setMinimumSize(QtCore.QSize(91, 0))
        self.SellButton.setTabletTracking(False)
        self.SellButton.setAutoFillBackground(False)
        self.SellButton.setObjectName("SellButton")
        self.ArrowLabel = QtWidgets.QLabel(self.centralwidget)
        self.ArrowLabel.setGeometry(QtCore.QRect(130, 14, 80, 21))
        self.ArrowLabel.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.ArrowLabel.setObjectName("ArrowLabel")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 90, 90, 30))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(250, 90, 90, 30))
        self.label_3.setMinimumSize(QtCore.QSize(81, 0))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(130, 40, 80, 30))
        self.label_4.setObjectName("label_4")
        self.ResultButton = QtWidgets.QPushButton(self.centralwidget)
        self.ResultButton.setGeometry(QtCore.QRect(10, 170, 90, 30))
        self.ResultButton.setObjectName("ResultButton")
        self.ExitButton = QtWidgets.QPushButton(self.centralwidget)
        self.ExitButton.setGeometry(QtCore.QRect(250, 170, 90, 30))
        self.ExitButton.setMinimumSize(QtCore.QSize(81, 0))
        self.ExitButton.setObjectName("ExitButton")
        self.LeftCurrency = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.LeftCurrency.setGeometry(QtCore.QRect(10, 120, 90, 30))
        self.LeftCurrency.setObjectName("LeftCurrency")
        self.RightCurrency = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.RightCurrency.setGeometry(QtCore.QRect(250, 120, 90, 30))
        self.RightCurrency.setObjectName("RightCurrency")
        self.CurrencyBuyLabel = QtWidgets.QLabel(self.centralwidget)
        self.CurrencyBuyLabel.setGeometry(QtCore.QRect(10, 40, 90, 30))
        self.CurrencyBuyLabel.setStyleSheet("QLabel {\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"background-color: white;")
        self.CurrencyBuyLabel.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.CurrencyBuyLabel.setObjectName("CurrencyBuyLabel")
        self.CurrencySellLabel = QtWidgets.QLabel(self.centralwidget)
        self.CurrencySellLabel.setGeometry(QtCore.QRect(250, 40, 90, 30))
        self.CurrencySellLabel.setStyleSheet("QLabel {\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"background-color: white;")
        self.CurrencySellLabel.setObjectName("CurrencySellLabel")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.BuyButton.setText(_translate("MainWindow", "Купівля"))
        self.SellButton.setText(_translate("MainWindow", "Продаж"))
        self.ArrowLabel.setText(_translate("MainWindow", "<html><head/><body><p>--&gt;</p></body></html>"))
        self.label_2.setText(_translate("MainWindow", "<html><head/><body><p>USD</p></body></html>"))
        self.label_3.setText(_translate("MainWindow", "<html><head/><body><p>UAH</p></body></html>"))
        self.label_4.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\">Курс</p></body></html>"))
        self.ResultButton.setText(_translate("MainWindow", "Обчислити"))
        self.ExitButton.setText(_translate("MainWindow", "Вихід"))
        self.CurrencyBuyLabel.setText(_translate("MainWindow", "25.1"))
        self.CurrencySellLabel.setText(_translate("MainWindow", "24.7"))
