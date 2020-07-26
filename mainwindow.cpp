#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    textToFile = ternarySearchTree.getDotFile();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

void MainWindow::on_pushButtonOfInsert_clicked()
{
    std::string toInsert = ui->lineEditOfInsert->text().toStdString();

    bool ret = ternarySearchTree.insert(toInsert);

    updateDotFile();
    updateImage();
    renderImage();

    QMessageBox msgBox;
    if (ret)
        msgBox.setText("The data was inserted");
    else
        msgBox.setText("This data already exists in the tree");
    msgBox.exec();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    std::string toSearch = ui->lineEditOfSearch->text().toStdString();
    NodeOfTernarySearchTree* node = ternarySearchTree.search(toSearch);

    QMessageBox msgBox;

    if (node != nullptr)
        msgBox.setText("This word exists");
    else
        msgBox.setText("This word does not exists");

    msgBox.exec();
}

void MainWindow::on_pushButtonOfRemove_clicked()
{
    std::string toRemove = ui->lineEditOfRemove->text().toStdString();
    bool ret = ternarySearchTree.remove(toRemove);

    QMessageBox msgBox;

    if (ret)
        msgBox.setText("The word was removed");
    else
        msgBox.setText("This word does not exists");

    updateDotFile();
    updateImage();
    renderImage();
}
