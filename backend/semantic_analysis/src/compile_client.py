"""
 * @file compile_client.py
 * @author Linzhi 2020211472
 * @brief
        Pascal_S compiler 客户端
        基于python、QT、QML实现
* @version 0.1
* @date 2023-05-05
* @copyright(python) 2023
"""
# -*- coding: utf-8 -*-
import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QFileDialog, QApplication, QPushButton, QWidget, QGridLayout
from PyQt5.QtGui import QIcon
import requests


#   需要几个按钮
#   打开文件、编译、保存
#   两个框，一个装文件，一个装返回结果
class MainUi(QMainWindow):

    def __init__(self):
        super().__init__()
        self.fname = ""
        self.url = "http://127.0.0.1:8888"
        self.initUI()

    def initUI(self):
        self.setFixedSize(1920, 1080)
        self.main_widget = QWidget()  # 创建窗口主部件
        self.main_layout = QGridLayout()  # 创建主部件的网格布局
        self.main_widget.setLayout(self.main_layout)  # 设置窗口主部件布局为网格布局

        self.left_widget = QWidget()  # 创建左侧部件
        self.left_widget.setObjectName('left_widget')
        self.left_layout = QGridLayout()  # 创建左侧部件的网格布局
        self.left_widget.setLayout(self.left_layout)  # 设置左侧部件布局为网格布局

        self.right_widget = QWidget()  # 创建右侧部件
        self.right_widget.setObjectName('right_widget')
        self.right_layout = QGridLayout()  # 创建右侧部件的网格布局
        self.right_widget.setLayout(self.right_layout)  # 设置右侧部件布局为网格布局

        self.main_layout.addWidget(self.left_widget, 0, 0, 12, 2)
        self.main_layout.addWidget(self.right_widget, 0, 2, 12, 10)
        self.setCentralWidget(self.main_widget)  # 设置窗口主部件

        self.button1 = QPushButton(QIcon(''), '打开文件')  # 创建按钮
        self.left_layout.addWidget(self.button1, 1, 0, 1, 3)
        self.button2 = QPushButton(QIcon(''), '保存文件')  # 创建按钮
        self.left_layout.addWidget(self.button2, 2, 0, 1, 3)
        self.button3 = QPushButton(QIcon(''), '编译文件')  # 创建按钮
        self.left_layout.addWidget(self.button3, 3, 0, 1, 3)
        self.textEdit = QTextEdit()  # 创建文本框用于显示
        self.right_layout.addWidget(self.textEdit, 0, 0, 4, 8)
        self.message = QTextEdit()  # 创建文本框用于显示返回信息
        self.right_layout.addWidget(self.message, 4, 0, 3, 8)
        self.button1.clicked.connect(self.showDialog1)
        self.button2.clicked.connect(self.saveFile)
        self.button3.clicked.connect(self.compile)

    #   定义打开文件夹目录的函数
    def showDialog1(self):
        self.fname = QFileDialog.getOpenFileName(self, 'OpenF file', '.')
        if self.fname[0]:
            f = open(self.fname[0], 'r')
            with f:
                data = f.read()
                self.textEdit.setText(data)

    #  定义保存文件的函数
    def saveFile(self):
        self.fname = QFileDialog.getOpenFileName(self, 'Save file', '.')
        if self.fname[0]:
            f = open(self.fname[0], 'w')
            with f:
                data = self.textEdit.toPlainText()
                f.write(data)

    #   定义编译函数
    def compile(self):
        if self.fname == "":
            print("请先打开文件")
        if self.fname[0]:
            f = open(self.fname[0], 'r')
            with f:
                files = {"data": f}
                r = requests.post(self.url+"/Compile", files=files)
                self.message.setText(r.text)
                if r.status_code == 200:
                    print("编译成功")
                    r = requests.get(self.url+"/file")
                    with open(self.fname[0]+".exe", "wb") as code:
                        code.write(r.content)


def main():
    app = QApplication(sys.argv)
    gui = MainUi()
    gui.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
