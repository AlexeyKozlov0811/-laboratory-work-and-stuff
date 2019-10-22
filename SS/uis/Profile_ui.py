# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uis\Profile.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(339, 356)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 20, 320, 20))
        self.label.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 50, 320, 20))
        self.label_2.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 80, 320, 20))
        self.label_3.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(10, 110, 320, 20))
        self.label_4.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(10, 140, 321, 20))
        self.label_5.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label_5.setObjectName("label_5")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(10, 170, 320, 20))
        self.label_6.setStyleSheet("QLabel {\n"
"    qproperty-alignment: \'AlignCenter\';\n"
"}")
        self.label_6.setObjectName("label_6")
        self.PortraitImage = QtWidgets.QPushButton(self.centralwidget)
        self.PortraitImage.setGeometry(QtCore.QRect(10, 230, 130, 30))
        self.PortraitImage.setObjectName("PortraitImage")
        self.ArtImage = QtWidgets.QPushButton(self.centralwidget)
        self.ArtImage.setGeometry(QtCore.QRect(10, 290, 130, 30))
        self.ArtImage.setObjectName("ArtImage")
        self.label_picture = QtWidgets.QLabel(self.centralwidget)
        self.label_picture.setGeometry(QtCore.QRect(180, 200, 130, 130))
        self.label_picture.setText("")
        self.label_picture.setObjectName("label_picture")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "TextLabel"))
        self.label_2.setText(_translate("MainWindow", "TextLabel"))
        self.label_3.setText(_translate("MainWindow", "TextLabel"))
        self.label_4.setText(_translate("MainWindow", "TextLabel"))
        self.label_5.setText(_translate("MainWindow", "TextLabel"))
        self.label_6.setText(_translate("MainWindow", "TextLabel"))
        self.PortraitImage.setText(_translate("MainWindow", "Портретна фотографія"))
        self.ArtImage.setText(_translate("MainWindow", "Художня фотографія"))
