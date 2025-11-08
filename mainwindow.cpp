#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    setWindowTitle("ToDo リスト管理");
    
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addTodo);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteTodo);
    connect(ui->todoLineEdit, &QLineEdit::returnPressed, this, &MainWindow::onReturnPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTodo()
{
    QString todoText = ui->todoLineEdit->text().trimmed();
    
    if (!todoText.isEmpty()) {
        ui->todoListWidget->addItem(todoText);
        ui->todoLineEdit->clear();
        ui->todoLineEdit->setFocus();
    }
}

void MainWindow::deleteTodo()
{
    int currentRow = ui->todoListWidget->currentRow();
    
    if (currentRow >= 0) {
        QListWidgetItem* item = ui->todoListWidget->takeItem(currentRow);
        delete item;
    } else {
        QMessageBox::information(this, "情報", "削除するタスクを選択してください。");
    }
}

void MainWindow::onReturnPressed()
{
    addTodo();
}

void MainWindow::on_pushButton_clicked()
{

}

