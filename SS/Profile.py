import sys
from PyQt5 import QtWidgets, QtGui
from uis.Profile_ui import Ui_MainWindow


class ProfileWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()

        self.setWindowTitle('Анкета')
        self.label.setText('Анкета студента')
        self.label_2.setText('Іван Іванов, студент групи СП-325')
        self.label_3.setText('Вищого навчального закладу')
        self.label_4.setText('Національний авіаційний університет')
        self.label_5.setText('Рік народження: 2000')
        self.label_6.setText('Адреса: м. Київ, вул. Шулявська')

        self.PortraitImage.clicked.connect(self.image_display)
        self.ArtImage.clicked.connect(self.image_display)

    def image_display(self):
        button = self.sender()
        self.label_picture.setPixmap(QtGui.QPixmap(button.objectName() + ".jpg").scaled(130, 130))


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    SS = ProfileWindow()
    sys.exit(app.exec_())
