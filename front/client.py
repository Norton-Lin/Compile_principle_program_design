"""
 * @file compile_client.py
 * @author Linzhi 2020211472
 * @brief
        Pascal_S compiler 客户端
        基于python、QT实现
* @version 0.1
* @date 2023-05-05
* @copyright(python) 2023
"""
# -*- coding: utf-8 -*-
import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QFileDialog, QApplication, QPushButton
from PyQt5.QtWidgets import QWidget, QGridLayout
from PyQt5.QtGui import QIcon, QTextCharFormat, QSyntaxHighlighter, QFont, QColor
from PyQt5.QtCore import QRegExp
import requests


class KeyWordHighlighter(QSyntaxHighlighter):

    def __init__(self, parent=None):
        super(KeyWordHighlighter, self).__init__(parent)

        self.tagFormat = QTextCharFormat()
        self.tagFormat.setForeground(QColor("orange"))
        self.tagFormat.setFontWeight(QFont.Bold)
        self.keyword = [
            "and", "array", "begin", "case", "const", "div", "do", "downto",
            "else", "end", "file", "for", "function", "goto", "if", "in",
            "label", "mod", "nil", "not", "of", "or", "packed", "procedure",
            "program", "record", "repeat", "set", "then", "to", "type",
            "until", "var", "while", "with"
        ]
        keywordPatterns = ["\\b" + key + "\\b" for key in self.keyword]

        self.highlightingRules = [(QRegExp(pattern), self.tagFormat)
                                  for pattern in keywordPatterns]

    def highlightBlock(self, text):
        for pattern, format in self.highlightingRules:
            expression = QRegExp(pattern)
            index = expression.indexIn(text)
            while index >= 0:
                length = expression.matchedLength()
                self.setFormat(index, length, format)
                index = expression.indexIn(text, index + length)


class ErrorHighlighter(QSyntaxHighlighter):
    def __init__(self, parent=None):
        super(ErrorHighlighter, self).__init__(parent)
        lineFormat = QTextCharFormat()
        lineFormat.setBackground(QColor("red"))

        self.highlightingRules = [(QRegExp(".*[e|E]rror.*"), lineFormat)]

    def highlightBlock(self, text):
        for pattern, format in self.highlightingRules:
            expression = QRegExp(pattern)
            index = expression.indexIn(text)
            while index >= 0:
                length = expression.matchedLength()
                self.setFormat(0, len(text), format)
                index = expression.indexIn(text, index + length)


#   需要几个按钮
#   打开文件、编译、保存
#   两个框，一个装文件，一个装返回结果
class MainUi(QMainWindow):

    def __init__(self):
        super().__init__()
        self.fname = ""
        self.url = "http://127.0.0.1:8888"
        self.initUI()
        self.setWindowTitle("Pascal_s_Compiler")

    def initUI(self):
        self.setBaseSize(1920, 960)
        self.main_widget = QWidget()  # 创建窗口主部件
        self.main_layout = QGridLayout()  # 创建主部件的网格布局
        self.main_widget.setLayout(self.main_layout)  # 设置窗口主部件布局为网格布局
        with open("widget.qss", "r") as f:
            style = f.read()
            self.main_widget.setStyleSheet(style)
        self.bottom_widget = QWidget()  # 创建下侧部件
        self.bottom_widget.setObjectName('bottom_widget')
        self.bottom_layout = QGridLayout()  # 创建下侧部件的网格布局
        self.bottom_widget.setLayout(self.bottom_layout)  # 设置下侧部件布局为网格布局

        self.top_widget = QWidget()  # 创建上侧部件
        self.top_widget.setObjectName('top_widget')
        self.top_layout = QGridLayout()  # 创建上侧部件的网格布局
        self.top_widget.setLayout(self.top_layout)  # 设置上侧部件布局为网格布局
          
        self.main_layout.addWidget(self.top_widget, 1, 0, 12, 12)
        self.main_layout.addWidget(self.bottom_widget, 0, 0, 1, 12)
        self.setCentralWidget(self.main_widget)  # 设置窗口主部件

        self.bottom_layout.setHorizontalSpacing(400)
        self.button1 = QPushButton(QIcon(''), '打开文件')  # 创建按钮
        with open("botton.qss", "r") as f:
            style = f.read()
            self.button1.setStyleSheet(style)
        self.bottom_layout.addWidget(self.button1, 2, 1, 2, 1)
        self.button2 = QPushButton(QIcon(''), '保存文件')  # 创建按钮
        with open("botton.qss", "r") as f:
            style = f.read()
            self.button2.setStyleSheet(style)
        self.bottom_layout.addWidget(self.button2, 2, 5, 2, 1)
        self.button3 = QPushButton(QIcon(''), '编译文件')  # 创建按钮
        with open("botton.qss", "r") as f:
            style = f.read()
            self.button3.setStyleSheet(style)
        self.bottom_layout.addWidget(self.button3, 2, 9, 2, 1)
        self.textEdit = QTextEdit()  # 创建文本框用于显示
        with open("style.qss", "r") as f:
            style = f.read()
            self.textEdit.setStyleSheet(style)
        self.text1 = KeyWordHighlighter(self.textEdit.document())
        self.top_layout.addWidget(self.textEdit, 0, 0, 8, 12)
        self.message = QTextEdit()  # 创建文本框用于显示返回信息
        with open("style.qss", "r") as f:
            style = f.read()
            self.message.setStyleSheet(style)
        self.text2 = ErrorHighlighter(self.message.document())
        self.message.setReadOnly(True)
        self.top_layout.addWidget(self.message, 8, 0, 4, 10)
        self.result = QTextEdit()  # 创建文本框用于显示返回信息
        with open("style.qss", "r") as f:
            style = f.read()
            self.result.setStyleSheet(style)
        self.text3 = ErrorHighlighter(self.message.document())
        self.message.setReadOnly(True)
        self.top_layout.addWidget(self.result, 8, 10, 4, 2)
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
            f.close()

    #  定义保存文件的函数
    def saveFile(self):
        self.fname = QFileDialog.getOpenFileName(self, 'Save file', '.')
        if self.fname[0]:
            f = open(self.fname[0], 'w')
            with f:
                data = self.textEdit.toPlainText()
                f.write(data)
            f.close()

    #   定义编译函数
    def compile(self):
        if self.fname == "":
            print("请先打开文件")
        if self.fname[0]:
            f = open(self.fname[0], 'w')
            with f:
                data = self.textEdit.toPlainText()
                f.write(data)
                f.close()
            f = open(self.fname[0], 'r')
            with f:
                files = {"data": f}
                r = requests.post(self.url + "/Compile", files=files)
                self.message.setText(r.text)
                if r.status_code == 200:
                    self.result.setText("编译成功")
                    r = requests.get(self.url + "/file")
                    with open(self.fname[0] + ".exe", "wb") as code:
                        print("成功写入")
                        code.write(r.content)
                else:
                    self.result.setText("编译失败,请根据编译信息检查代码")
            f.close()


def main():
    app = QApplication(sys.argv)
    gui = MainUi()
    gui.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
