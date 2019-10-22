# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uis\SS.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(200, 300)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.ResultButton = QtWidgets.QPushButton(self.centralwidget)
        self.ResultButton.setEnabled(True)
        self.ResultButton.setGeometry(QtCore.QRect(150, 250, 50, 50))
        self.ResultButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.ResultButton.setObjectName("ResultButton")
        self.DivideButton = QtWidgets.QPushButton(self.centralwidget)
        self.DivideButton.setEnabled(True)
        self.DivideButton.setGeometry(QtCore.QRect(150, 50, 50, 50))
        self.DivideButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.DivideButton.setObjectName("DivideButton")
        self.PlusButton = QtWidgets.QPushButton(self.centralwidget)
        self.PlusButton.setEnabled(True)
        self.PlusButton.setGeometry(QtCore.QRect(150, 200, 50, 50))
        self.PlusButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.PlusButton.setObjectName("PlusButton")
        self.FourButton = QtWidgets.QPushButton(self.centralwidget)
        self.FourButton.setEnabled(True)
        self.FourButton.setGeometry(QtCore.QRect(0, 150, 50, 50))
        self.FourButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.FourButton.setObjectName("FourButton")
        self.OneButton = QtWidgets.QPushButton(self.centralwidget)
        self.OneButton.setEnabled(True)
        self.OneButton.setGeometry(QtCore.QRect(0, 200, 50, 50))
        self.OneButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.OneButton.setObjectName("OneButton")
        self.FiveButton = QtWidgets.QPushButton(self.centralwidget)
        self.FiveButton.setEnabled(True)
        self.FiveButton.setGeometry(QtCore.QRect(50, 150, 50, 50))
        self.FiveButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.FiveButton.setObjectName("FiveButton")
        self.TwoButton = QtWidgets.QPushButton(self.centralwidget)
        self.TwoButton.setEnabled(True)
        self.TwoButton.setGeometry(QtCore.QRect(50, 200, 50, 50))
        self.TwoButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.TwoButton.setObjectName("TwoButton")
        self.MinusButton = QtWidgets.QPushButton(self.centralwidget)
        self.MinusButton.setEnabled(True)
        self.MinusButton.setGeometry(QtCore.QRect(150, 150, 50, 50))
        self.MinusButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.MinusButton.setObjectName("MinusButton")
        self.SignButton = QtWidgets.QPushButton(self.centralwidget)
        self.SignButton.setEnabled(True)
        self.SignButton.setGeometry(QtCore.QRect(50, 50, 50, 50))
        self.SignButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}")
        self.SignButton.setObjectName("SignButton")
        self.EightButton = QtWidgets.QPushButton(self.centralwidget)
        self.EightButton.setEnabled(True)
        self.EightButton.setGeometry(QtCore.QRect(50, 100, 50, 50))
        self.EightButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.EightButton.setObjectName("EightButton")
        self.SeparatorButton = QtWidgets.QPushButton(self.centralwidget)
        self.SeparatorButton.setEnabled(True)
        self.SeparatorButton.setGeometry(QtCore.QRect(100, 250, 50, 50))
        self.SeparatorButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}")
        self.SeparatorButton.setObjectName("SeparatorButton")
        self.PercentButton = QtWidgets.QPushButton(self.centralwidget)
        self.PercentButton.setEnabled(True)
        self.PercentButton.setGeometry(QtCore.QRect(100, 50, 50, 50))
        self.PercentButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}")
        self.PercentButton.setObjectName("PercentButton")
        self.MultiplyButton = QtWidgets.QPushButton(self.centralwidget)
        self.MultiplyButton.setEnabled(True)
        self.MultiplyButton.setGeometry(QtCore.QRect(150, 100, 50, 50))
        self.MultiplyButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.MultiplyButton.setObjectName("MultiplyButton")
        self.CalcLabel = QtWidgets.QLabel(self.centralwidget)
        self.CalcLabel.setEnabled(False)
        self.CalcLabel.setGeometry(QtCore.QRect(0, 0, 200, 51))
        self.CalcLabel.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignVCenter | AlignRight\';\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"background-color: white;")
        self.CalcLabel.setInputMethodHints(QtCore.Qt.ImhNone)
        self.CalcLabel.setTextFormat(QtCore.Qt.PlainText)
        self.CalcLabel.setObjectName("CalcLabel")
        self.SevenButton = QtWidgets.QPushButton(self.centralwidget)
        self.SevenButton.setEnabled(True)
        self.SevenButton.setGeometry(QtCore.QRect(0, 100, 50, 50))
        self.SevenButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.SevenButton.setObjectName("SevenButton")
        self.ThreeButton = QtWidgets.QPushButton(self.centralwidget)
        self.ThreeButton.setEnabled(True)
        self.ThreeButton.setGeometry(QtCore.QRect(100, 200, 50, 50))
        self.ThreeButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.ThreeButton.setObjectName("ThreeButton")
        self.ZeroButton = QtWidgets.QPushButton(self.centralwidget)
        self.ZeroButton.setEnabled(True)
        self.ZeroButton.setGeometry(QtCore.QRect(0, 250, 100, 50))
        self.ZeroButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.ZeroButton.setObjectName("ZeroButton")
        self.NineButton = QtWidgets.QPushButton(self.centralwidget)
        self.NineButton.setEnabled(True)
        self.NineButton.setGeometry(QtCore.QRect(100, 100, 50, 50))
        self.NineButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.NineButton.setObjectName("NineButton")
        self.SixButton = QtWidgets.QPushButton(self.centralwidget)
        self.SixButton.setEnabled(True)
        self.SixButton.setGeometry(QtCore.QRect(100, 150, 50, 50))
        self.SixButton.setStyleSheet("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}")
        self.SixButton.setObjectName("SixButton")
        self.ClearButton = QtWidgets.QPushButton(self.centralwidget)
        self.ClearButton.setEnabled(True)
        self.ClearButton.setGeometry(QtCore.QRect(0, 50, 50, 50))
        self.ClearButton.setStyleSheet("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}")
        self.ClearButton.setObjectName("ClearButton")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "СПЗ лабораторные"))
        self.ResultButton.setText(_translate("MainWindow", "="))
        self.DivideButton.setText(_translate("MainWindow", "/"))
        self.PlusButton.setText(_translate("MainWindow", "+"))
        self.FourButton.setText(_translate("MainWindow", "4"))
        self.OneButton.setText(_translate("MainWindow", "1"))
        self.FiveButton.setText(_translate("MainWindow", "5"))
        self.TwoButton.setText(_translate("MainWindow", "2"))
        self.MinusButton.setText(_translate("MainWindow", "-"))
        self.SignButton.setText(_translate("MainWindow", "+/-"))
        self.EightButton.setText(_translate("MainWindow", "8"))
        self.SeparatorButton.setText(_translate("MainWindow", "."))
        self.PercentButton.setText(_translate("MainWindow", "%"))
        self.MultiplyButton.setText(_translate("MainWindow", "*"))
        self.CalcLabel.setText(_translate("MainWindow", "0"))
        self.SevenButton.setText(_translate("MainWindow", "7"))
        self.ThreeButton.setText(_translate("MainWindow", "3"))
        self.ZeroButton.setText(_translate("MainWindow", "0"))
        self.NineButton.setText(_translate("MainWindow", "9"))
        self.SixButton.setText(_translate("MainWindow", "6"))
        self.ClearButton.setText(_translate("MainWindow", "С"))
